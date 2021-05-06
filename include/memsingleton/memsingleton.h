#ifndef MEMSINGLETON_H
#define MEMSINGLETON_H
#include "../mm/mm.h"
#include "../collector/collector.h"

class memSingleton
{
    Mem_manager manager;
    Collector C;
    memSingleton();
    memSingleton(const memSingleton &);
    ~memSingleton();
    // has to take care of doing placement new, register owner and what not
public:
    Mem_manager::ptr alloc(size_t s);
    void free(Mem_manager::ptr n_idx);
    template <typename T>
    T *construct(Mem_manager::ptr idx, T obj)
    {
        return manager.construct<T>(idx, obj);
    }
    void dump();
    static memSingleton &get();
};
#endif