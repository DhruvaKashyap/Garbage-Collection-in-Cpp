#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "../meta/meta.h"

class Collector
{
    vector<Mem_manager::ptr> rootSet;
    vector<Mem_manager::ptr> lostResources;
    int liveResources;

public:
    void collect();
    void printInfo();
    void registerIndex(MetaData *meta, bool isResource, Mem_manager *m);
    void unregisterIndex(MetaData *meta, Mem_manager *m);
    Mem_manager::ptr findParent(MetaData *meta, Mem_manager *m);
};

#endif