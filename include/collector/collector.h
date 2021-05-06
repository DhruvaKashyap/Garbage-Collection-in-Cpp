#ifndef COLLECTOR_H
#define COLLECTOR_H
class Collector
{
    vector<Mem_manager::ptr> rootSet;
    vector<Mem_manager::ptr> lostResources;
    int liveResources;

public:
    void collect();
    void printInfo();
    void registerIndex(MetaData *meta, int isResource, char *p);
    void unregisterIndex(MetaData *meta, char *p);
    int findParent(MetaData &meta, char *p);
};

#endif