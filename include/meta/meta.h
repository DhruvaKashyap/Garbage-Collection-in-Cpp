#ifndef META_H
#define META_H
#include "../collector/collector.h"
#include "../mm/mm.h"
#include "../alloc/alloc.h"

enum Colour
{
    White,
    Grey,
    Black
};

class MetaData
{
    friend Collector;

    template <typename T>
    friend GCBase;

    Colour c = White;
    Mem_manager::ptr idx;
    Mem_manager::ptr owner = -1;
    vector<Mem_manager::ptr> children;
};

#endif