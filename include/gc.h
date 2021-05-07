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
    GCBase(T p = T())
    {
        idx = memSingleton::get().construct<T>(p);
    }
    GCBase(const GCBase<T> &copy)
    {
        idx = memSingleton::get().copyref(copy.idx);
    }
    GCBase &operator=(const GCBase<T> &copy)
    {
        memSingleton::get().free(idx);
        idx = memSingleton::get().copyref(copy.idx);
        return *this;
    }
    ~GCBase()
    {
        memSingleton::get().free(idx);
    }
    operator T() const
    {
        return *memSingleton::get().get_from_mem<T>(idx);
    }
    //operator+,-,==,!=
    friend GCBase<T> operator+(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs)+T(rhs);
    }
};

template <typename T>
requires is_class<T>::value class GCBase<T>
{
    Mem_manager::ptr idx;

public:
    template <typename... Args>
    GCBase(Args &&...args)
    {
        T obj(args...);
        idx = memSingleton::get().construct<T>(obj);
    }
    GCBase(const GCBase<T> &copy)
    {
        idx = memSingleton::get().copyref(copy.idx);
    }
    GCBase &operator=(const GCBase<T> &copy)
    {
        memSingleton::get().free(idx);
        idx = memSingleton::get().copyref(copy.idx);
        return *this;
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