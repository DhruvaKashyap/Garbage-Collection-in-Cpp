#ifndef MM_H
#define MM_H
#include <climits>
#include <utility>
#include "policies/policy.h"
#include <iostream>
#define MAXSIZE 50
using namespace std;

class memSingleton;
class mem_policy;
class Collector;
class Mem_manager
{
    char *p;
    int size;
    struct book_t
    {
        int isfree;
        int next;
    };
    mem_policy *policy;

public:
    friend class memSingleton;
    using ptr = int;
    using book = book_t;
    Mem_manager(int n, mem_policy *pol) : size(n), policy(pol)
    {
        p = new char[n];
        book *b = (book *)p;
        b->next = size;
        b->isfree = 1;
    }
    ~Mem_manager()
    {
        delete[] p;
    }
    ptr mymalloc(size_t size); //function to allocate a block of size "size" from p

    void expand(size_t size);

    void myfree(ptr n_idx); //free the block pointed to by the parameter

    void display_mem_map(); // print the memory array p in the following format
};

class Collector
{
    // vector
public:
    void collect(){};
    // void print_stats();
    // register and unregister idx
    // register subptr
    // find owner
};

class mem_policy
{
public:
    virtual ~mem_policy(){};
    virtual pair<Mem_manager::book *, int> find_block(char *p, size_t size, size_t req) = 0;
};

class best_fit : public mem_policy
{
public:
    virtual pair<Mem_manager::book *, int> find_block(char *p, size_t size, size_t req)
    {
        int chunk_size;
        int found_size = INT_MAX;
        Mem_manager::book *target;
        Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
        while (pres != (Mem_manager::book *)(p + size))
        {
            chunk_size = (p + pres->next - (char *)pres) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
            if (chunk_size < found_size && chunk_size >= req && pres->isfree == 1)    //finds largest free chunk
            {
                target = pres;
                found_size = chunk_size;
            }
            pres = (Mem_manager::book *)(p + pres->next);
        }
        return make_pair(target, found_size == INT_MAX ? 0 : found_size);
    }
};

class first_fit : public mem_policy
{
public:
    virtual pair<Mem_manager::book *, int> find_block(char *p, size_t size, size_t req)
    {
        int chunk_size;
        Mem_manager::book *target;
        Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
        while (pres != (Mem_manager::book *)(p + size))
        {
            chunk_size = ((p + pres->next - (char *)pres)) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
            if (chunk_size >= req && pres->isfree == 1)                                 //finds largest free chunk
            {
                return make_pair(pres, chunk_size);
            }
            pres = (Mem_manager::book *)(p + pres->next);
        }
        return make_pair(target, 0);
    }
};

class memSingleton
{
    Mem_manager manager;
    Collector C;
    memSingleton(int n, mem_policy *m) : manager(n, m){};
    memSingleton(const memSingleton &);
    ~memSingleton()
    {
    }
    // has to take care of doing placement new, register owner and what not
public:
    Mem_manager::ptr alloc(size_t s)
    {
        auto ret = manager.mymalloc(s);
        while (ret == manager.size && manager.size < MAXSIZE)
        {
            C.collect();
            ret = manager.mymalloc(s);
            if (ret == manager.size)
            {
                try
                {
                    auto new_size = manager.size * 2;
                    if (new_size > MAXSIZE)
                        throw "HEAP SIZE EXCEEDED\n";
                    manager.expand(new_size);
                }
                catch (const char *a)
                {
                    cout << a;
                    exit(0);
                }
                manager.display_mem_map();
            }
        }
        return ret;
    }
    void free(Mem_manager::ptr n_idx)
    {
        manager.myfree(n_idx);
    }
    void dump()
    {
        manager.display_mem_map();
    }
    static memSingleton &get(int n, mem_policy *m)
    {
        static memSingleton instance(n, m);
        return instance;
    };
};

#endif
