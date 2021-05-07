#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "meta/meta.h"
#include <vector>

class Collector
{
    vector<Mem_manager::ptr> references;
    int liveResources;

public:
    void collect(Mem_manager *m);
    void printInfo();
    void registerIndex(MetaData *meta, bool isResource, Mem_manager *m);
    void unregisterIndex(MetaData *meta, Mem_manager *m);
};

#endif