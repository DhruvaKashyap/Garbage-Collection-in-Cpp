#ifndef MEMSINGLETON_H
#define MEMSINGLETON_H
#include "mm/mm.h"
#include "collector/collector.h"

class memSingleton
{
    Mem_manager manager;
    Collector C;
    memSingleton();
    memSingleton(const memSingleton &);
    ~memSingleton();
    // has to take care of doing placement new, register owner and what not
    Mem_manager::ptr alloc(size_t s);

public:
    template <typename T, typename TT, typename... Args>
    Mem_manager::ptr construct(TT val, Args &&...args)
    {
        auto idx = alloc(sizeof(T));
        C.registerIndex((MetaData *)(manager.p + idx - sizeof(MetaData)), 1, &manager);
        new (manager.p + idx) T(val, args...);
        return idx;
    }
    Mem_manager::ptr copyref(Mem_manager::ptr idx)
    {
        C.registerIndex((MetaData *)(manager.p + idx - sizeof(MetaData)), 0, &manager);
        return idx;
    }
    template <typename T>
    T *get_from_mem(Mem_manager::ptr idx)
    {
        return (T *)(manager.p + idx);
    }
    template <typename T>
    void free(Mem_manager::ptr n_idx)
    {
        ((T *)(manager.p + n_idx))->~T();
        C.unregisterIndex((MetaData *)(manager.p + n_idx - sizeof(MetaData)), &manager);
    }
    void print_info();
    static memSingleton &get();
};
#endif