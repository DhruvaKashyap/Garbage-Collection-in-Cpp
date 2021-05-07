#include <iostream>
#include "gc.h"

class Z
{
    double ff = 20.0;

public:
    void hi()
    {
        cout << "zz " << ff << '\n';
    }
};

class Y
{
    int aa;
    GCBase<Z> i;

public:
    Y(int a) : aa(a){};
    void hi()
    {
        i->hi();
        cout << "hi " << aa << "\n";
    }
};

class X
{
    GCBase<Y> i;
    int k;

public:
    X(int a, int b) : i(a), k(b){};
    void hi()
    {
        i->hi();
        cout << k << '\n';
    }
};

int main()
{
    GCBase<int> a = 1;
    GCBase<int> b = 68;
    GCBase<int> c = 419;
    // GCBase<Y> a(420);
    // GCBase<X> b(69, 2);
    // a->hi();
    // b->hi();
    cout << c << '\n';
    c = a + b;
    cout << c << '\n';
}