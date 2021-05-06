#ifndef META_H
#define META_H
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
    int next;
    Colour c = White;
    int idx;
    int owner = -1;
    vector<int> children;
};

#endif