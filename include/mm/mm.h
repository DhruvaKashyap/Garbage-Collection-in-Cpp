#ifndef MM_H
#define MM_H
#include <climits>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

class MetaData;
class policy;
class Collector;
class Mem_manager
{
    char *p;
    int size;
    int n = 1000000;
    policy *pol;
    const int MAXSIZE = 10000000;

public:
    friend class memSingleton;
    friend class Collector;
    using ptr = int;
    using book = MetaData;
    Mem_manager();
    ~Mem_manager();
    ptr mymalloc(size_t size); //function to allocate a block of size "size" from p
    void expand(size_t size);
    void myfree(ptr n_idx); //free the block pointed to by the parameter
    void display_mem_map(); // print the memory array p in the following format
};
#endif
