#ifndef MM_H
#define MM_H
#include <climits>
#include <utility>
#include "../policy/policy.h"
#include <iostream>
#include <vector>
#define MAXSIZE 10000000
using namespace std;

class Mem_manager
{
    char *p;
    int size;
    int n = 1000000;
    mem_policy *policy;

    struct book_t
    {
        bool isfree;
        int next;
    };

public:
    friend class memSingleton;
    using ptr = int;
    using book = book_t;
    Mem_manager();
    ~Mem_manager();
    template <typename T>
    T *construct(ptr pt, T obj)
    {
        new (p + pt) T(obj);
        return (T *)(p + pt);
    }
    ptr mymalloc(size_t size); //function to allocate a block of size "size" from p
    void expand(size_t size);
    void myfree(ptr n_idx); //free the block pointed to by the parameter
    void display_mem_map(); // print the memory array p in the following format
};
#endif
