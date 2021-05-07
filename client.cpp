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

class A
{
    int a;

public:
    A(int n) : a(n){};
    virtual ~A(){};
    virtual void f() { cout << "A\n"; };
};

class B : public A
{
    int b;

public:
    B(int n) : A(n), b(n){};
    virtual void f() { cout << "B\n"; };
};

int main()
{
    // Simple types
    cout << "Simple Integers a; b; c\n";
    {
        GCBase<int> a = 0;
        GCBase<int> b = 1;
        GCBase<int> c = 1;
        a++;
        b = 1729;
        c = b * a;
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

    // Copy Ctors
    cout << "Nested Class with multiple references and copy ctor\n";
    {
        GCBase<Z> z1(9);
        GCBase<Z> z2(z1);
        z1->f();
        z2->f();
        memSingleton::get().print_info();
    }
    cout << "Destructing class z1 and z2\n";
    memSingleton::get().print_info();

    // Assignment operator
    cout << "Nested Class with multiple references\n";
    {
        GCBase<Y> y1(20);
        GCBase<Y> y2(30);
        y1->f();
        cout << "------\n";
        y2->f();
        y1 = y2;
        cout << "-----------\n";
        y1->f();
        cout << "------\n";
        y2->f();
        memSingleton::get().print_info();
    }
    cout << "Destructing class y1 and y2\n";
    memSingleton::get().print_info();

    // Memory expansion
    cout << "Memory expansion\n";
    {
        GCBase<X> x1(1);
        GCBase<double> x2(8.0);
        GCBase<X> x3(3);
        GCBase<X> x4(4);
        GCBase<int> x5(5);
        GCBase<X> x6(6);
        GCBase<string> x7("Hello, World!\n");
        GCBase<X> x8(8);
        GCBase<X> x9(9);
        memSingleton::get().print_info();
    }
    cout << "Destructing class x{1..9}\n";
    memSingleton::get().print_info();

    //Inheritance
    cout << "Inheritance(Experimental Interface)\n";
    {
        GCBase<B> y(1);
        GCBase<A> *a = (GCBase<A> *)&y;
        (*a)->f();
        memSingleton::get().print_info();
    }
    cout << "Destructing Inheritance classes\n";
    memSingleton::get().print_info();
}