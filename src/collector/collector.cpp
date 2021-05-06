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

void Collector::registerIndex(MetaData *meta, int isResource, char *p)
{
    int parent = findParent(meta, p);
    if (isResource)
        liveResources += 1;
    meta->c = Grey;
    if (parent == -1)
    {
        rootSet.push_back(meta);
    }
    else
    {
        MetaData *temp = (MetaData *)(p + meta->owner);
        temp->idx = parent;
        temp->children.push_back(meta->idx);
    }
}

void Collector::unregisterIndex(MetaData *meta, char *p)
{
    int counts = 0;

    if (meta->owner == -1)
    {
        auto found = rootSet.end();
        for (auto it = rootSet.begin(); it != rootSet.end(); it++)
        {
            if ((*it)->idx == meta->idx)
            {
                counts += 1;
                found = it;
            }
        }

        rootSet.erase(found);
    }
    else
    {
        MetaData *temp = (MetaData *)(p + meta->owner);
        auto found = temp->children.end();
        for (auto it = temp->children.begin(); it != temp->children.end(); it++)
        {
            if (*it == meta->idx)
            {
                counts += 1;
                found = it;
            }
        }
        temp->children.erase(found);
    }

    if (counts < 2)
    {
        lostResources.push_back(meta);
    }
}

int Collector::findParent(MetaData &meta, char *p)
{
}