#include "mm/mm.h"
#include "meta/meta.h"
#include "policy/best_fit.h"
#include "policy/first_fit.h"
#include <memory>
#include <iostream>
#include <cstring>
using namespace std;

Mem_manager::Mem_manager()
{
    size = 100;
    pol = new best_fit;
    p = new char[size];
    book *b = (book *)p;
    b->next = size;
    b->isfree = 1;
}
Mem_manager::~Mem_manager()
{
    delete pol;
    delete[] p;
}

Mem_manager::ptr Mem_manager::mymalloc(size_t s) //function to allocate a block of size "s" from p
{
    Mem_manager::book *target = nullptr; //chunk where pointer is supposed to be allocated memory
    size_t found_size = 0;               //stores the size of the largest empty chunk

    auto pl = pol->find_block(p, size, s);
    target = pl.first;
    found_size = pl.second;
    if (found_size == 0 || (found_size < s)) //no free chunks or chunks big enough to allocate memory
    {
        return -1;
    }
    if (s + sizeof(Mem_manager::book) < found_size) //when the remaining chunk is big enough to store more data
    {
        //allocate and add a Mem_manager::book to indicate the remaining free space
        target->isfree = 0;                                                        //mark as allocated
        Mem_manager::book *n;                                                      //new Mem_manager::book
        n = (Mem_manager::book *)((char *)target + sizeof(Mem_manager::book) + s); //position of the new Mem_manager::book
        n->isfree = 1;
        n->next = target->next;
        target->next = ((char *)target + sizeof(Mem_manager::book) + s) - p;
    }
    else
    {
        //case when the remaining free space in the chunk is less than the size of a Mem_manager::book
        //entire chunk is allocated
        target->isfree = 0;
    }
    return (char *)(target + 1) - p; //Mem_manager::book* that points to the required space type casted automatically to void*
}

void Mem_manager::myfree(Mem_manager::ptr b) //free the block pointed to by the parameter
{
    if (b != -1)
    {
        Mem_manager::book *pres = (Mem_manager::book *)p;
        Mem_manager::book *prev = nullptr;
        while (pres != (Mem_manager::book *)(p + size)) //finding the pointer in memory
        {
            if (pres + 1 == (Mem_manager::book *)(p + b))
                break;
            prev = pres;
            pres = (Mem_manager::book *)(p + pres->next);
        }
        //freeing chunk and merging
        if (pres != (Mem_manager::book *)(p + size) && pres->isfree != 1) //chunk is found and is not already free
        {
            pres->isfree = 1;
            Mem_manager::book *x = (Mem_manager::book *)(p + pres->next);
            if ((x != (Mem_manager::book *)(p + size)) && (x->isfree == 1)) //next chunk exists and is free
            {
                pres->next = x->next;
            }
            if (prev != nullptr && prev->isfree == 1) //prev chunk exists and is free
                prev->next = pres->next;
            else if (prev != nullptr) //existing prev chunk points to newly freed chunk
                prev->next = (char *)pres - p;
        }
    }
}

void Mem_manager::display_mem_map() // print the memory array p
{
    Mem_manager::book *ff = (Mem_manager::book *)p;
    int i = 0;
    int s = 0;
    cout << "start_addr\tblock_in_bytes\tstatus\n";
    while (ff != (Mem_manager::book *)(p + size))
    {
        printf("%d\t\t%ld\t\tMem_manager::book\n", i, sizeof(Mem_manager::book)); //chunks always start with a Mem_manager::book
        s = (p + ff->next - (char *)ff) - sizeof(Mem_manager::book);              //calculates size of the chunk in bytes(sizeof a character)
        if (ff->isfree == 1)
            printf("%ld\t\t%d\t\tfree\n", i + sizeof(Mem_manager::book), s);
        else
            printf("%ld\t\t%d\t\tallocated\n", i + sizeof(Mem_manager::book), s);
        ff = (Mem_manager ::book *)(p + ff->next);
        i += s + sizeof(Mem_manager::book);
    }
}

void Mem_manager::expand(size_t sizen)
{
    char *newloc = new char[sizen];
    for (int i = 0; i < size; ++i)
        newloc[i] = p[i];
    Mem_manager::book *ff = (Mem_manager::book *)newloc;
    Mem_manager::book *lastbook = (Mem_manager::book *)newloc;
    while (ff != (Mem_manager::book *)(newloc + size))
    {
        lastbook = ff;
        ff = (Mem_manager ::book *)(newloc + ff->next);
    }
    if (lastbook->isfree)
    {
        lastbook->next = sizen;
    }
    else
    {
        Mem_manager::book *new_book = (Mem_manager::book *)(newloc + size);
        new_book->isfree = 1;
        new_book->next = sizen;
    }
    delete[] p;
    size = sizen;
    p = newloc;
}