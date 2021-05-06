#include "../../include/policy/best_fit.h"

pair<Mem_manager::book *, size_t> best_fit::find_block(char *p, size_t size, size_t req)
{
    size_t chunk_size;
    size_t found_size = INT_MAX;
    Mem_manager::book *target;
    Mem_manager::book *pres = (Mem_manager::book *)p; //points to the first Mem_manager::book
    while (pres != (Mem_manager::book *)(p + size))
    {
        chunk_size = (p + pres->next - (char *)pres) - sizeof(Mem_manager::book); //calculates size of a chunk in bytes
        if (chunk_size < found_size && chunk_size >= req && pres->isfree == 1)    //finds largest free chunk
        {
            target = pres;
            found_size = chunk_size;
        }
        pres = (Mem_manager::book *)(p + pres->next);
    }
    return make_pair(target, found_size == INT_MAX ? 0 : found_size);
}
