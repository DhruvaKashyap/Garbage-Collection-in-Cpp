#ifndef META_H
#define META_H
#include "mm/mm.h"
#include <vector>
using namespace std;

enum Colour
{
    White,
    Grey,
    Black
};

struct MetaData
{
    bool isfree;
    Mem_manager::ptr next; // next meta block
    Colour colour = White;
    Mem_manager::ptr owner = -1; // owner meta block
    vector<Mem_manager::ptr> children; // child meta blocks
};

#endif