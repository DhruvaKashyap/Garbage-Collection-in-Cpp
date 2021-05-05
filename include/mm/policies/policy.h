#ifndef POLICY_H
#define POLICY_H
#include <utility>
#include <climits>
#include "../mm.h"
using namespace std;
class mem_policy
{
public:
    virtual ~mem_policy(){};
    virtual pair<Mem_manager::book *, int> find_block(char *p, int size) = 0;
};

class best_fit : public mem_policy
{
public:
    virtual pair<Mem_manager::book *, int> find_block(char *p, int size)
    {
        int chunk_size;
        int found_size = INT_MAX;
        Mem_manager::book *target;
        Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
        while (pres != (Mem_manager::book *)(p + size))
        {
            chunk_size = ((char *)pres->next - (char *)pres) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
            if (chunk_size < found_size && pres->isfree == 1)                             //finds largest free chunk
            {
                target = pres;
                found_size = chunk_size;
            }
            pres = pres->next;
        }
        return make_pair(target, found_size);
    }
};

class first_fit : public mem_policy
{
public:
    virtual pair<Mem_manager::book *, int> find_block(char *p, int size)
    {
        int chunk_size;
        int found_size = INT_MAX;
        Mem_manager::book *target;
        Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
        while (pres != (Mem_manager::book *)(p + size))
        {
            chunk_size = ((char *)pres->next - (char *)pres) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
            if (chunk_size < found_size && pres->isfree == 1)                             //finds largest free chunk
            {
                target = pres;
                found_size = chunk_size;
                return make_pair(target, found_size);
            }
            pres = pres->next;
        }
        return make_pair(target, found_size);
    }
};
#endif