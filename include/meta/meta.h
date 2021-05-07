#ifndef META_H
#define META_H
#include "mm/mm.h"

using namespace std;

struct MetaData
{
    bool isfree;
    Mem_manager::ptr next;
};

#endif