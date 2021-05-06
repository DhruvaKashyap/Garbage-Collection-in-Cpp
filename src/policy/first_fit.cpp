#include "policy/first_fit.h"

pair<Mem_manager::book *, size_t> first_fit::find_block(char *p, size_t size, size_t req)
{
    size_t chunk_size;
    Mem_manager::book *target;
    Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
    while (pres != (Mem_manager::book *)(p + size))
    {
        chunk_size = ((p + pres->next - (char *)pres)) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
        if (chunk_size >= req && pres->isfree == 1)                                 //finds largest free chunk
        {
            return make_pair(pres, chunk_size);
        }
        pres = (Mem_manager::book *)(p + pres->next);
    }
    return make_pair(target, 0);
}
