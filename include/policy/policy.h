#ifndef POLICY_H
#define POLICY_H
#include <utility>
#include <climits>
#include "../mm/mm.h"
using namespace std;

class policy
{
public:
    virtual ~policy(){};
    virtual pair<Mem_manager::book* , int> find_block(char *p, size_t size, size_t req) = 0;
};



#endif