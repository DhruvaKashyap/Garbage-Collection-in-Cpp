#include <iostream>
#include "gc.h"
#include <string>
using namespace std;

class Z
{
    double ff = 20.0;

public:
    Z(double f = 20.0) : ff(f) { cout << "ctor z\n"; }
    void hi()
    {
        cout << "zz " << ff << '\n';
    }
    ~Z()
    {
        cout << "dtor z\n";
    }
};

class Y
{
    int aa;
    GCBase<Z> i;

public:
    Y(int a) : aa(a) { cout << "ctor Y\n"; };
    ~Y()
    {
        cout << "dtor y\n";
    }
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
    X(int a, int b) : i(a), k(b) { cout << "ctor X\n"; };
    ~X()
    {
        cout << "dtor x\n";
    }
    void hi()
    {
        i->hi();
        cout << k << '\n';
    }
};

class A
{
    int a;

public:
    virtual void f() { cout << "A\n"; };
};
class B : public A
{

public:
    virtual void f() { cout << "B\n"; };
};

int main()
{
    // GCBase<int> a = 1;
    // GCBase<int> b = 68;
    // GCBase<int> c = 419;
    // GCBase<Y> y(420);
    // cout << "----------------------------------------\n";
    GCBase<Y> j(100);
    // j = y;
    GCBase<X> x(69, 2);
    // y->hi();
    // x->hi();
    // cout << c << '\n';
    // c = a + b;
    // c++;
    // cout << c << '\n';
    // GCBase<string> s1("a");
    // GCBase<string> s2("b");
}