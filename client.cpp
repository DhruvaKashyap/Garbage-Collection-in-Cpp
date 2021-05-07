#include <iostream>
#include "gc.h"
using namespace std;

class X
{
    int a;

public:
    X() { a = 10; }
    X(int n) : a(n){};
    void f()
    {
        cout << "This is X(" << a << ")\n";
    }
    friend ostream &operator<<(ostream &o, const X &x)
    {
        return o << x.a;
    }
};

class Y
{
    int b;
    GCBase<X> x;

public:
    Y(int n) : b(n), x(n + 1){};
    void f()
    {
        cout << "This is Y(" << b << ")\n";
        x->f();
    }
};

class Z
{
    int c;
    GCBase<X> x;
    GCBase<Y> y;

public:
    Z(int n) : c(n), x(n + 1), y(n + 2){};
    void f()
    {
        cout << "This is Z(" << c << ")\n";
        x->f();
        y->f();
    }
};

int main()
{
    //Simple types
    cout << "Simple Integers a; b; c\n";
    {
        GCBase<int> a = 0;
        GCBase<int> b = 1;
        GCBase<int> c = 1;
        cout << "a: " << a << '\n';
        cout << "b: " << b << '\n';
        cout << "c: " << c << '\n';
        memSingleton::get().print_info();
    }
    cout << "Destructing a; b; c\n";
    memSingleton::get().print_info();

    // Basic class
    cout << "Basic Class x\n";
    {
        GCBase<X> x(2);
        x->f();
        cout << "x:" << x << '\n';
        memSingleton::get().print_info();
    }
    cout << "Destructing x\n";
    memSingleton::get().print_info();

    // Nested class
    cout << "Nested Class y\n";
    {
        GCBase<Y> y(3);
        y->f();
        memSingleton::get().print_info();
    }
    cout << "Destructing class y\n";
    memSingleton::get().print_info();

    // Nested class with Multiple references
    cout << "Nested Class with multiple references\n";
    {
        GCBase<Z> z(5);
        z->f();
        memSingleton::get().print_info();
    }
    cout << "Destructing class z\n";
    memSingleton::get().print_info();

    // Assignment and copy ctors
    {
        
    }
}