#include "pool.h"

PoolAllocator::PoolAllocator(const std::size_t count, std::initializer_list<std::size_t> sizes)
    : pool(new char[count * sizes.size()])
    , blocks(new std::stack<char *>[sizes.size()])
    , block_starts(new char *[sizes.size()])
    , size(sizes.size())
{
    std::size_t t_count = count;
    int cur = 0;
    char * cur_ptr = pool;
    for (const auto s : sizes) {
        index_by_size.insert({s, cur});
        size_by_index.insert({cur, s});
        block_starts[cur] = cur_ptr;
        char * cur_block_ptr = cur_ptr;
        for (int i = 0; i < std::floor(t_count / s); i++) {
            blocks[cur].push(cur_block_ptr);
            for (unsigned int j = 0; j < s; j++) {
                cur_block_ptr++;
            }
        }
        for (unsigned int i = 0; i < t_count; i++) {
            cur_ptr++;
        }
        cur++;
    }
}

void * PoolAllocator::allocate(const std::size_t n)
{
    int index = index_by_size[n];
    if (blocks[index].empty()) {
        throw std::bad_alloc();
    }
    char * ptr = blocks[index].top();
    blocks[index].pop();
    return reinterpret_cast<void *>(ptr);
}

int PoolAllocator::search_index(const void * ptr) const
{
    int cur = 0;
    int last = 0;
    while (true) {
        if (ptr >= block_starts[cur]) {
            last = cur;
            if (cur == size - 1) {
                return cur;
            }
            cur++;
        }
        else {
            return last;
        }
    }
}

void PoolAllocator::deallocate(const void * ptr)
{
    int index = search_index(ptr);
    blocks[index].push(reinterpret_cast<char *>(const_cast<void *>(ptr)));
}

PoolAllocator::~PoolAllocator()
{
    delete[] pool;
    delete[] block_starts;
    delete[] blocks;
}