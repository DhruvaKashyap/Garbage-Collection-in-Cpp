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
    // MetaData meta;
    T *ptr_to_mem;

public:
    GCBase(){};
    template <typename TT, typename... Args>
    GCBase(TT val, Args &&...args) : T(val, args...)
    {
        m = new first_fit;
        auto &ms = memSingleton::get();
        auto idx = ms.alloc(sizeof(*this));
        ptr_to_mem = ms.construct<GCBase<T>>(idx, *this);
    }
    ~GCBase()
    {
        // delete m;
    }
    T *operator->()
    {
        return ptr_to_mem;
    }
};

#endif