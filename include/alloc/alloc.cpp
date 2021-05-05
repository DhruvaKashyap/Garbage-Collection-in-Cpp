#include <iostream>
#include "alloc.h"

class X
{
public:
    X(int a, int b){};
};
class Y
{
public:
    Y(int a){};
};

int main()
{
    GCBase<Y> a(1);
    GCBase<X> b(1, 2);
}