#include "collector/collector.h"
#include "meta/meta.h"
#include <iostream>
using namespace std;

void Collector::collect(Mem_manager *m)
{
    char *temp = m->p;
    cout << "***Cleaning memory***\n";
    while (temp != (m->p + m->size))
    {
        MetaData *meta = (MetaData *)temp;
        if (!(meta->isfree))
        {
            if (find(references.begin(), references.end(), temp - m->p) == references.end())
            {
                m->myfree(temp + sizeof(MetaData) - m->p);
                liveResources -= 1;
            }
        }
        temp = m->p + meta->next;
    }
}

void Collector::printInfo()
{
    cout << "Total number of references: " << references.size() << "\n";
    cout << "Number of live resources in the heap: " << liveResources << "\n";
}

void Collector::registerIndex(MetaData *meta, bool isResource, Mem_manager *m)
{
    Mem_manager::ptr idx = (char *)(meta)-m->p;

    if (isResource)
        liveResources += 1;

    references.push_back(idx);
}

void Collector::unregisterIndex(MetaData *meta, Mem_manager *m)
{
    Mem_manager::ptr idx = (char *)(meta)-m->p;
    auto i = find(references.begin(), references.end(), idx);
    if (i != references.end())
        references.erase(i);
}