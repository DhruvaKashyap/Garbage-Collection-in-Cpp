#include <iostream>
#include "gc.h"

class Y
{
public:
    int aa;
    Y(int a) : aa(a){};
    void hi()
    {
        cout << "hi " << aa << "\n";
    }
};

class X
{
    GCBase<Y> i;

public:
    X(int a, int b) : i(a){};
    void hi()
    {
        cout << i->aa << '\n';
    }
};

int main()
{
    // GCBase<int> c;
    // GCBase<Y> a(420);
    GCBase<X> b(69, 2);
    // a->hi();
    b->hi();
}