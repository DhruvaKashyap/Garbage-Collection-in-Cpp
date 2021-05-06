#include "../../include/memsingleton/memsingleton.h"

memSingleton::memSingleton() : manager()
{

}

memSingleton::~memSingleton()
{
}

Mem_manager::ptr memSingleton::alloc(size_t s)
{
    auto ret = manager.mymalloc(s);
    while (ret == -1 && manager.size < MAXSIZE)
    {
        C.collect();
        ret = manager.mymalloc(s);
        if (ret == -1)
        {
            try
            {
                auto new_size = manager.size * 2;
                if (new_size > MAXSIZE)
                    throw "HEAP SIZE EXCEEDED\n";
                manager.expand(new_size);
            }
            catch (const char *a)
            {
                cout << a;
                exit(0);
            }
            manager.display_mem_map();
        }
    }
    return ret;
}

void memSingleton::free(Mem_manager::ptr n_idx)
{
    manager.myfree(n_idx);
}

void memSingleton::dump()
{
    manager.display_mem_map();
}

memSingleton &memSingleton::get()
{
    static memSingleton instance;
    return instance;
}
