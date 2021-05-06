#include <iostream>
#include "../../include/memsingleton/memsingleton.h"
using namespace std;
int main()
{
    memSingleton &m = memSingleton::get();
    m.dump();
    // m.print_book();
    printf("\n");

    Mem_manager::ptr a = m.alloc(20 * sizeof(char));
    printf("a:20\n");
    m.dump();
    // m.print_book();
    printf("\n");

    // for(int i = 0; i < 200; ++i)
    // printf("%c",a[i] );

    Mem_manager::ptr b = m.alloc(30 * sizeof(char));
    printf("b:30\n");
    // printf("b:%p\n",b);
    m.dump();
    printf("\n");

    // for (int i = 0; i < 30; ++i)
    //     b[i] = '0';
    // for (int i = 0; i < 30; ++i)
    //     printf("%c", b[i]);
    printf("\n");

    m.free(a);
    printf("free a:20\n");
    m.dump();
    printf("\n");

    Mem_manager::ptr c = m.alloc(4 * sizeof(char));
    printf("c:4\n");
    m.dump();
    printf("\n");
    printf("d:20\n");
    Mem_manager::ptr d = m.alloc(20 * sizeof(char));

    m.dump();
    printf("\n");

    // m.free(b);
    // printf("free b:20\n");
    // m.dump();
    // printf("\n");

    Mem_manager::ptr dd = m.alloc(20 * sizeof(char));
    printf("dd:20\n");
    m.dump();
    printf("\n");

    m.free(b);
    printf("free b:20\n");
    m.dump();
    printf("\n");

    Mem_manager::ptr e = m.alloc(30 * sizeof(char));
    printf("e:30\n");
    m.dump();
    printf("\n");

    m.free(d);
    printf("free d:20\n");
    m.dump();
    printf("\n");

    m.free(dd);
    printf("free dd:20\n");
    m.dump();
    printf("\n");

    m.free(e);
    printf("free e:30\n");
    m.dump();
    printf("\n");

    m.free(c);
    printf("free c:4\n");
    m.dump();
    printf("\n");

    // m.free(d);
    // printf("free d:20\n");
    // dump();
    // printf("\n");
    // allocate(78);
    // Mem_manager::ptr a=(char*)m.alloc(10*sizeof(char));
    // dump();
    // printf("\n");
    // Mem_manager::ptr b=(char*)m.alloc(10*sizeof(char));
    // dump();
    // printf("\n");
    // Mem_manager::ptr c=(char*)m.alloc(10*sizeof(char));
    // dump();
    // printf("\n");
    // m.free(b);
    // dump();
    // printf("\n");

    // b=m.alloc(5*sizeof(char));
    // dump();
    // printf("\n");
}
