#include <iostream>
#include "alloc.h"

class X
{
public:
    X(int a, int b){};
};
class Y
{
    int aa;

public:
    Y(int a) : aa(a){};
    void hi()
    {
        cout << "hi " << aa << "\n";
    }
};

int main()
{
    GCBase<Y> a(1);
    GCBase<X> b(1, 2);
    a->hi();
}