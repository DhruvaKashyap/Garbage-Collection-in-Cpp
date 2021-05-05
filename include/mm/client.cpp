#include <iostream>
#include "mm.h"
using namespace std;
int main()
{
    mem_policy *mm = new first_fit;
    memSingleton &m = memSingleton::get(10000, mm);
    m.display_mem_map();
    // m.print_book();
    printf("\n");

    memSingleton::Mem_manager::ptr a = m.mymalloc(20 * sizeof(char));
    printf("a:20\n");
    m.display_mem_map();
    // m.print_book();
    printf("\n");

    // for(int i = 0; i < 200; ++i)
    // printf("%c",a[i] );

    memSingleton::Mem_manager::ptr b = m.mymalloc(30 * sizeof(char));
    printf("b:30\n");
    // printf("b:%p\n",b);
    m.display_mem_map();
    printf("\n");

    // for (int i = 0; i < 30; ++i)
    //     b[i] = '0';
    // for (int i = 0; i < 30; ++i)
    //     printf("%c", b[i]);
    printf("\n");

    m.myfree(a);
    printf("free a:20\n");
    m.display_mem_map();
    printf("\n");

    memSingleton::Mem_manager::ptr c = m.mymalloc(4 * sizeof(char));
    printf("c:4\n");
    m.display_mem_map();
    printf("\n");

    memSingleton::Mem_manager::ptr d = m.mymalloc(20 * sizeof(char));
    printf("d:20\n");
    m.display_mem_map();
    printf("\n");

    // m.myfree(b);
    // printf("free b:20\n");
    // m.display_mem_map();
    // printf("\n");

    memSingleton::Mem_manager::ptr dd = m.mymalloc(20 * sizeof(char));
    printf("dd:20\n");
    m.display_mem_map();
    printf("\n");

    m.myfree(b);
    printf("free b:20\n");
    m.display_mem_map();
    printf("\n");

    memSingleton::Mem_manager::ptr e = m.mymalloc(30 * sizeof(char));
    printf("e:30\n");
    m.display_mem_map();
    printf("\n");

    m.myfree(d);
    printf("free d:20\n");
    m.display_mem_map();
    printf("\n");

    m.myfree(dd);
    printf("free dd:20\n");
    m.display_mem_map();
    printf("\n");

    m.myfree(e);
    printf("free e:30\n");
    m.display_mem_map();
    printf("\n");

    m.myfree(c);
    printf("free c:4\n");
    m.display_mem_map();
    printf("\n");

    // m.myfree(d);
    // printf("free d:20\n");
    // display_mem_map();
    // printf("\n");
    // allocate(78);
    // memSingleton::Mem_manager::ptr a=(char*)m.mymalloc(10*sizeof(char));
    // display_mem_map();
    // printf("\n");
    // memSingleton::Mem_manager::ptr b=(char*)m.mymalloc(10*sizeof(char));
    // display_mem_map();
    // printf("\n");
    // memSingleton::Mem_manager::ptr c=(char*)m.mymalloc(10*sizeof(char));
    // display_mem_map();
    // printf("\n");
    // m.myfree(b);
    // display_mem_map();
    // printf("\n");

    // b=m.mymalloc(5*sizeof(char));
    // display_mem_map();
    // printf("\n");
    delete mm;
}
