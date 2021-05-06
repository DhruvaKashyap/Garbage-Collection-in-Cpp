#ifndef ALLOC_H
#define ALLOC_H
#include "memsingleton/memsingleton.h"
#include <concepts>
using namespace std;

template <typename T>
class GCBase
{
    Mem_manager::ptr idx;

public:
    // write all operators
};

template <typename T>
requires is_class<T>::value class GCBase<T> : public T
{
    Mem_manager::ptr idx;

public:
    template <typename... Args>
    GCBase(Args &&...args) : T(args...)
    {
        idx = memSingleton::get().construct<T>(*(T *)this);
    }
    GCBase(const GCBase<T> &copy) : T(copy)
    {
        idx = memSingleton::get().copyref(copy.idx);
    }
    GCBase &operator=(const GCBase<T> &copy)
    {
        memSingleton::get().free(idx);
        idx = memSingleton::get().copyref(copy.idx);
    }
    ~GCBase()
    {
        memSingleton::get().free(idx);
    }
    T *operator->()
    {
        return memSingleton::get().get_from_mem<T>(idx);
    }
};

#endif