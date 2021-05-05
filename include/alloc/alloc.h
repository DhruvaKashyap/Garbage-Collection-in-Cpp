#ifndef ALLOC_H
#define ALLOC_H
#include "../mm/mm.h"
#include <concepts>
using namespace std;

template <typename T>
class GCBase
{
    T *ptr_to_mem;

public:
    // write all operators
};

template <typename T>
requires is_class<T>::value class GCBase<T> : public T
{
    T *ptr_to_mem;
    //owner idx
    mem_policy *m;
    int n = 100000;
    Mem_manager::ptr idx;

public:
    GCBase() { m = new first_fit; };
    template <typename TT, typename... Args>
    GCBase(TT val, Args &&...args) : T(val, args...)
    {
        m = new first_fit;
        idx = memSingleton::get(n, m).alloc(sizeof(this));
        // new () GCBase<T> (*this); done by allocator
    }
    ~GCBase()
    {
        delete m;
    }
};

#endif

/*
int i=10;
gc<int> i(10);
// gc<base> b(gc<Derived>());
*/