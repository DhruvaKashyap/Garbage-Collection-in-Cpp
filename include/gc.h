#ifndef GC_H
#define GC_H
#include <cstddef>
#include <concepts>
using namespace std;

template <typename T>
class gcptr
{
    T val;

public:
};

template <typename T>
void *gc_new()
{
    return gcptr<T>();
}

template <typename T>
class gc
{
public:
    void *operator new(size_t t)
    {
        return gc_new<T>();
    };
    void operator delete(void *p)
    {
    }
};

#endif