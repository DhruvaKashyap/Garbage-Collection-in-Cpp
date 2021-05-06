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
    Mem_manager::ptr alloc(size_t s);
    void dump();

public:
    void free(Mem_manager::ptr n_idx);
    template <typename T>
    Mem_manager::ptr construct(const T *obj)
    {
        auto idx = alloc(sizeof(T));
        new (manager.p + idx) T(*obj);
        // C.registerIndex((MetaData *)(manager.p + idx - sizeof(MetaData)), 1, &manager);
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
    static memSingleton &get();
};
#endif