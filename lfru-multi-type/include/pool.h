#pragma once

#include <array>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <list>
#include <new>
#include <stack>
#include <unordered_map>
#include <vector>

class PoolAllocator
{

public:
    PoolAllocator(std::size_t count, std::initializer_list<std::size_t> sizes);

    void * allocate(std::size_t n);

    int search_index(const void * ptr) const;

    void deallocate(const void * ptr);

    ~PoolAllocator();

    char * pool;
    std::stack<char *> * blocks;
    char ** block_starts; // we can get rid of it
    int size;
    std::unordered_map<int, int> index_by_size;
    std::unordered_map<int, int> size_by_index;
};
