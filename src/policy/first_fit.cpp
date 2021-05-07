#include "policy/first_fit.h"

pair<Mem_manager::book *, size_t> first_fit::find_block(Mem_manager* m,const size_t req)
{
    size_t chunk_size;
    Mem_manager::book *pres = (Mem_manager::book *)(m->p); //points to the first Mem_manager::book
    Mem_manager::book *target = pres;
    while (pres != (Mem_manager::book *)(m->p + m->size))
    {
        chunk_size = ((m->p + pres->next - (char *)pres)) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
        if (chunk_size >= req && pres->isfree == 1)                                 //finds largest free chunk
        {
            return make_pair(pres, chunk_size);
        }
        pres = (Mem_manager::book *)(m->p + pres->next);
    }
    return make_pair(target, 0);
}
