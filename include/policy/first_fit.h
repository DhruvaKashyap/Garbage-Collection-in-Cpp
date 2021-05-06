#ifndef FIRST_FIT_H
#define FIRST_FIT_H
#include "policy.h"

class first_fit : public policy
{
public:
    virtual pair<Mem_manager::book *, size_t> find_block(char *p, size_t size, size_t req);
};

#endif