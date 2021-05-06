#ifndef POLICY_H
#define POLICY_H
#include <utility>
#include <climits>
#include "meta/meta.h"
using namespace std;

class policy
{
public:
    virtual ~policy();
    virtual pair<Mem_manager::book* , size_t> find_block(char *p, size_t size, size_t req) = 0;
};



#endif