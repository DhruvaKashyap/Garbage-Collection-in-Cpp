#include <iostream>
#include "../../include/alloc/alloc.h"

class X
{
    GCBase<double> i;
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
    GCBase<int> c;
    GCBase<Y> a(1);
    GCBase<X> b(1, 2);
    a->hi();
}