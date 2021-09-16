#pragma once

#include <cstddef>
#include <functional>
#include <list>
#include <new>
#include <ostream>

template <class Key, class KeyProvider, class Allocator>
class Cache
{
public:
    struct node
    {
        std::pair<Key, void *> data;
        node * next;
        node * prev;

        void (Allocator::*destroyPtr)(void *);

        node(const Key & key, void * data, node * prev, node * next, void (Allocator::*destroyPtr)(void *))
            : data(key, data)
            , next(next)
            , prev(prev)
            , destroyPtr(destroyPtr)
        {
        }
    };

    class EqualFn
    {
    public:
        bool operator()(Key const & t1, Key const & t2) const
        {
            return static_cast<KeyProvider>(t1) == t2;
        }
    };

    struct non_priv_queue;

    struct lru_list
    {
        std::size_t upper_bound = 0;
        std::size_t size = 0;
        node * head = nullptr;
        node * tail = nullptr;
        std::unordered_map<Key, node *, std::hash<Key>, EqualFn> p_table;

        lru_list() = default;

        lru_list(std::size_t top)
            : upper_bound(top)
        {
        }

        void erase(node * n)
        {
            if (find(n->data.first) == nullptr) { // O(1) check
                return;
            }
            node * prev = n->prev;
            node * next = n->next;
            if (prev != nullptr) {
                prev->next = next;
            }
            if (next != nullptr) {
                next->prev = prev;
            }
            if (n == tail) {
                tail = n->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }
            if (n == head) {
                head = n->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            size--;
            p_table.erase(n->data.first);
        }

        node * insert(node * n)
        {
            node * pushed_out = nullptr;
            if (size == upper_bound) {
                auto last = tail;
                erase(last);
                pushed_out = last;
            }
            n->prev = nullptr;
            n->next = head;
            if (head != nullptr) {
                head->prev = n;
            }
            head = n;
            if (size == 0) {
                tail = n;
            }
            size++;
            p_table.insert({n->data.first, n});
            return pushed_out;
        }

        node * find(const Key & key)
        {
            if (head == nullptr) {
                return nullptr;
            }
            auto search_res = p_table.find(key);
            if (search_res == p_table.end()) {
                return nullptr;
            }
            return search_res->second;
        }
    };

    struct non_priv_queue
    {
        non_priv_queue() = default;

        non_priv_queue(std::size_t top)
            : upper_bound(top)
        {
        }

        std::unordered_map<Key, node *, std::hash<Key>, EqualFn> p_table;
        node * head = nullptr;
        node * tail = nullptr;
        std::size_t size = 0;
        std::size_t upper_bound = 0;

        void add(node * n, Allocator & alloc)
        {
            if (size == upper_bound) {
                pop(alloc);
            }
            n->prev = nullptr;
            n->next = head;
            if (head != nullptr) {
                head->prev = n;
            }
            head = n;
            if (size == 0) {
                tail = n;
            }
            size++;
            p_table.insert({n->data.first, n});
        }

        node * find(const Key & key)
        {
            if (head == nullptr) {
                return nullptr;
            }
            auto search_res = p_table.find(key);
            if (search_res == p_table.end()) {
                return nullptr;
            }
            return search_res->second;
        }

        void
        erase(node * n)
        { // we pass a node* here because we don't want to waste resources
            // on unnecessary allocation/deallocation
            if (find(n->data.first) == nullptr) { // O(1) check
                return;
            }
            node * prev = n->prev;
            node * next = n->next;
            if (prev != nullptr) {
                prev->next = next;
            }
            if (next != nullptr) {
                next->prev = prev;
            }
            if (n == tail) {
                tail = n->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }
            if (n == head) {
                head = n->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            size--;
            p_table.erase(n->data.first);
        }

        void pop(Allocator & alloc)
        {
            p_table.erase(tail->data.first);
            node * tmp = tail;
            node * prev = tail->prev;
            (alloc.*tmp->destroyPtr)(tmp->data.second);
            delete tmp;
            tail = prev;
            size--;
        }
    };

    template <class... AllocArgs>
    Cache(const std::size_t cache_size, AllocArgs &&... alloc_args)
        : m_max_top_size(cache_size)
        , m_max_low_size(cache_size)
        , m_alloc(std::forward<AllocArgs>(alloc_args)...)
        , l(cache_size)
        , q(cache_size)
    {
    }

    std::size_t size() const
    {
        return l.size + q.size;
    }

    void print_all(std::ostream & strm, node * begin, node * end) const
    {
        auto tmp = begin;
        do {
            if (tmp != nullptr) {
                strm << tmp->data.first << " ";
                tmp = tmp->next;
            }
        } while (tmp != end);
    }

    bool empty() const
    {
        return size() == 0;
    }

    ~Cache()
    {
        int p_ind = 0;
        node * cur = l.head;
        while (p_ind < static_cast<int>(l.size)) {
            node * tmp = cur->next;
            delete cur;
            cur = tmp;
            p_ind++;
        }
        cur = q.head;
        int ind = 0;
        while (ind < static_cast<int>(q.size)) {
            node * tmp = cur->next;
            delete cur;
            cur = tmp;
            ind++;
        }
    }

    template <class T>
    T & get(const Key & key);

    std::ostream & print(std::ostream & strm) const;

    friend std::ostream & operator<<(std::ostream & strm, const Cache & cache)
    {
        return cache.print(strm);
    }

private:
    const std::size_t m_max_top_size;
    const std::size_t m_max_low_size;
    std::size_t elem_count;
    Allocator m_alloc;
    lru_list l;
    non_priv_queue q;
};

template <class Key, class KeyProvider, class Allocator>
template <class T>
inline T & Cache<Key, KeyProvider, Allocator>::get(const Key & key) // should be T& but idk how to do that
{
    auto elem = l.find(key);
    if (elem != nullptr) {
        l.erase(elem);
        l.insert(elem);
        return *(reinterpret_cast<T *>(l.head->data.second));
    }
    elem = q.find(key);
    if (elem != nullptr) {
        q.erase(elem);
        node * res = l.insert(elem);
        if (res != nullptr) {
            q.add(res, m_alloc);
        }
        return *(reinterpret_cast<T *>(l.head->data.second));
    }
    void * ptr = m_alloc.template create<T>(key);
    node * tmp = new node(key, ptr, nullptr, nullptr, &Allocator::template destroy<T>);
    q.add(tmp, m_alloc);
    return *(reinterpret_cast<T *>(q.head->data.second));
}

template <class Key, class KeyProvider, class Allocator>
inline std::ostream & Cache<Key, KeyProvider, Allocator>::print(std::ostream & strm) const
{
    strm << "Priority: ";
    this->print_all(strm, q.head, q.tail);
    strm << std::endl;
    strm << "Regular: ";
    this->print_all(strm, l.head, l.tail);
    strm << std::endl;
    return strm;
}
