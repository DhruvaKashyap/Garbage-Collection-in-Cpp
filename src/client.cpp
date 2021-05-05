#include "gc.h"
#include <iostream>
using namespace std;
int main()
{
    // Collector c(algorithm); strategy policy pattern implementation
    // init_thread(global::collector);
    // Interface for the client to create garbage collectable objects
    // Collector called after THRESHOLD bytes allocated
    // Rigourous tests for calculating THRESHOLD and other parameters and at end
    // GC for other resources like FILES, mutexes etc
    // GC only for heap based resources
    // operator functions etc
    // Work on all kinds of objects eg: user defined classes,containers
    // auto i = new gc<int>;
    // A(){p=new gc<int>;}
    // auto i = new gc<A>;
    {
        auto i = new gc<int>;
    } // auto j = i;
    // shape* s = new circle;
    // heirarchy of ptrs for a type
    // base classes, lots of them
    // random root < ptr arithmatic
    // specialize for is_class to inherit and get interface

    // With simple resources, do FT-1 assignment 1 in C++
    // Problems:
    // Derived to base conversion
    // Complex resources
}