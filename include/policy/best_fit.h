#ifndef BEST_FIT_H
#define BEST_FIT_H
#include "policy.h"

class best_fit : public mem_policy
{
public:
    virtual pair<Mem_manager::book *, int> find_block(char *p, size_t size, size_t req);
};

#endif