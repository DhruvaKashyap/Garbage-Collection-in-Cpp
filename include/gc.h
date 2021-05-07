#ifndef ALLOC_H
#define ALLOC_H
#include "memsingleton/memsingleton.h"
#include <concepts>
#include <iostream>
using namespace std;

template <typename T>
class GCBase
{
    Mem_manager::ptr idx;

public:
    GCBase(T p)
    {
        idx = memSingleton::get().construct<T>(p);
    }
    GCBase(const GCBase<T> &copy)
    {
        idx = memSingleton::get().copyref(copy.idx);
    }
    GCBase &operator=(const T &lhs)
    {
        (*memSingleton::get().get_from_mem<T>(idx)) = lhs;
        return *this;
    }
    GCBase &operator=(const GCBase<T> &copy)
    {
        if ((*this).idx != copy.idx)
        {
            memSingleton::get().free<T>(idx);
            idx = memSingleton::get().copyref(copy.idx);
        }
        return *this;
    }
    ~GCBase()
    {
        memSingleton::get().free<T>(idx);
    }
    operator T() const
    {
        return *memSingleton::get().get_from_mem<T>(idx);
    }

    friend T operator+(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) + T(rhs);
    }
    friend T operator-(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) - T(rhs);
    }
    friend T operator*(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) * T(rhs);
    }
    friend bool operator==(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return (T(lhs) == T(rhs));
    }
    friend bool operator!=(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return !(T(lhs) == T(rhs));
    }
    friend bool operator<(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return (T(lhs) < T(rhs));
    }
    friend bool operator<=(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return !(T(lhs) > T(rhs));
    }
    friend bool operator>(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return rhs < lhs;
    }
    friend bool operator>=(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return !(lhs < rhs);
    }
    GCBase<T> &operator++()
    {
        ++(*memSingleton::get().get_from_mem<T>(idx));
        return *this;
    }
    GCBase<T> operator++(int)
    {
        GCBase<T> temp = *this;
        ++*this;
        return temp;
    }
    GCBase<T> &operator--()
    {
        --(*memSingleton::get().get_from_mem<T>(idx));
        return *this;
    }
    GCBase<T> operator--(int)
    {
        GCBase<T> temp = *this;
        --*this;
        return temp;
    }
    friend T operator%(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) % T(rhs);
    }
    friend T operator/(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) / T(rhs);
    }
    friend T operator^(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) ^ T(rhs);
    }
    friend T operator<<(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) << T(rhs);
    }
    friend T operator>>(const GCBase<T> &lhs, const GCBase<T> &rhs)
    {
        return T(lhs) >> T(rhs);
    }
    friend T operator~(const GCBase<T> &lhs)
    {
        return ~T(lhs);
    }
    GCBase<T> operator+=(const GCBase<T> &rhs)
    {
        T *temp = memSingleton::get().get_from_mem<T>(idx);
        (*temp) += T(rhs);
        return *this;
    }
    GCBase<T> operator-=(const GCBase<T> &rhs)
    {
        T *temp = memSingleton::get().get_from_mem<T>(idx);
        (*temp) -= T(rhs);
        return *this;
    }
    GCBase<T> operator*=(const GCBase<T> &rhs)
    {
        T *temp = memSingleton::get().get_from_mem<T>(idx);
        (*temp) *= T(rhs);
        return *this;
    }
    GCBase<T> operator/=(const GCBase<T> &rhs)
    {
        T *temp = memSingleton::get().get_from_mem<T>(idx);
        (*temp) /= T(rhs);
        return *this;
    }
};

template <typename T>
requires is_class<T>::value class GCBase<T>
{
    Mem_manager::ptr idx;

public:
    GCBase()
    {
        idx = memSingleton::get().construct<T>(T());
    };
    GCBase(const GCBase<T> &copy)
    {
        idx = memSingleton::get().copyref(copy.idx);
    }
    template <typename TT, typename... Args>
    requires(!is_same_v<TT, GCBase<T>>) GCBase(TT val, Args &&...args)
    {
        idx = memSingleton::get().construct<T>(val, args...);
    }
    GCBase<T> &operator=(const GCBase<T> &copy)
    {
        if ((*this).idx != copy.idx)
        {
            memSingleton::get().free<T>(idx);
            idx = memSingleton::get().copyref(copy.idx);
        }
        return *this;
    }
    ~GCBase()
    {
        memSingleton::get().free<T>(idx);
    }
    T *operator->()
    {
        return memSingleton::get().get_from_mem<T>(idx);
    }
    operator T()
    {
        return *memSingleton::get().get_from_mem<T>(idx);
    }
};
#endif