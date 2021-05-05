#ifndef MM_H
#define MM_H
#include <climits>
#include <utility>
#include "policies/policy.h"
using namespace std;

class Mem_manager
{
    char *p;
    int size;
    struct book_t
    {
        int isfree;
        struct book_t *next;
    };
    mem_policy *policy;

public:
    using ptr = int;
    using book = book_t;
    Mem_manager(int n, mem_policy *pol) : size(n), policy(pol)
    {
        p = new char[n];
        book *b = (book *)p;
        b->next = (book *)(p + size);
        b->isfree = 1;
    }
    ~Mem_manager()
    {
        delete[] p;
    }
    ptr mymalloc(int size); //function to allocate a block of size "size" from p

    void myfree(ptr n_idx); //free the block pointed to by the parameter

    void display_mem_map(); // print the memory array p in the following format
};



class memSingleton
{
    memSingleton(int n, mem_policy *m) : ::Mem_manager(n, m){};
    memSingleton(const memSingleton &);
    Mem_manager manager;
    Collector C;

public:
    static memSingleton &get(int n, mem_policy *m)
    {
        static memSingleton instance(n, m);
        return instance;
    };
};

class Collector
{
    memS    
};
#endif
