#include "memsingleton/memsingleton.h"
#include <iostream>
using namespace std;
memSingleton::memSingleton()
{
}

memSingleton::~memSingleton()
{
    C.cleanUp();
    C.collect(&manager);
    cout << "FINAL COLLECT COMPLETE\n";
    print_info();
}

Mem_manager::ptr memSingleton::alloc(size_t s)
{
    auto ret = manager.mymalloc(s);
    if (ret == -1)
        C.collect(&manager);
    while (ret == -1 && manager.size < manager.MAXSIZE)
    {
        print_info();
        ret = manager.mymalloc(s);
        if (ret == -1)
        {
            try
            {
                auto new_size = manager.size * 2;
                if (new_size > manager.MAXSIZE)
                    throw "HEAP SIZE EXCEEDED\n";
                manager.expand(new_size);
            }
            catch (const char *a)
            {
                cout << a;
                exit(0);
            }
            cout << "******Expanding memory*******\n";
        }
    }
    return ret;
}

void memSingleton::print_info()
{
    cout << "---------------------------------------------\n";
    manager.display_mem_map();
    cout << "---------------------------------------------\n";
    C.printInfo();
    cout << "---------------------------------------------\n\n\n";
}

memSingleton &memSingleton::get()
{
    static memSingleton instance;
    return instance;
}
