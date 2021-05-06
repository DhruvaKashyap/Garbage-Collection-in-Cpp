#include "../../include/collector/collector.h"
#include "../../include/meta/meta.h"
#include <iostream>
using namespace std;

void Collector::collect()
{
}

void Collector::printInfo()
{
    cout << "Number of references in the root set: " << rootSet.size() << "\n";
    cout << "Number of live resources in the heap: " << liveResources << "\n";
}

void Collector::registerIndex(MetaData *meta, bool isResource, Mem_manager *m)
{
    Mem_manager::ptr parent = findParent(meta, m);
    Mem_manager::ptr idx = (char*)(meta) - m->p;

    if (isResource)
        liveResources += 1;
    meta->colour = Grey;

    if (parent == -1)
    {
        rootSet.push_back(idx);
    }
    else
    {
        meta->owner = parent;
        MetaData *temp = (MetaData *)(m->p + meta->owner);
        temp->children.push_back(idx);
    }
}

void Collector::unregisterIndex(MetaData *meta, Mem_manager *m)
{
    int counts = 0;
    vector<Mem_manager::ptr> *curr; 
    Mem_manager::ptr idx = (char*)(meta) - m->p;

    if (meta->owner == -1)
    {
        curr = &rootSet;
    }
    else
    {
        curr = &(((MetaData *)(m->p + meta->owner))->children);
    }

    auto found = curr->end();
    for (auto it = curr->begin(); it != curr->end(); it++)
    {
        if (*it == idx)
        {
            counts += 1;
            found = it;
        }
    }
    curr->erase(found);
    meta->colour = White;

    if (counts < 2)
    {
        lostResources.push_back(idx);
    }
}

Mem_manager::ptr Collector::findParent(MetaData *meta, Mem_manager *m)
{
    char* temp = m->p;
    while(temp-m->p < m->size)
    {
        if(temp+sizeof(MetaData)  &meta && &meta )
    }
}