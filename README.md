# Garbage-Collection-in-Cpp

Team members:
Abhijit Mohanty	PES1201801293 Section C
Dhruva Kashyap	PES1201801457 Section F
Thrivikraman V 	PES1201801469 Section D

```cpp
template<typename T>
class A
{	
	T x;
	public:
	A();
	// pools
	~A();
	// pools
	class smart
	{}
	smart operator new()..
	smart operator delete()..
}
template<typename T>
class B
{
	A<T> *p;
	B()
	{
		p = new A<T>();
	}
	~B()
	{
		delete p //optional in case of mark-sweep			
	}
}

int main()
{
	A<int>*::smart p = new A<int>(1);
	A<int>*::smart y = new A<int>(1);
	A<int>*::smart z = new A<int>(1);
	B *x = new B();	//not collected
	A<B>::smart x = new A<B>();
}

mstr a = "asda"
mstr b = "asda"

concept T::*
template<typename T>
class cg: T
{
}

template<typename T>
class cg
{
T val;
opertor+(){return this.val+rhs.val;}

```


Collector c(algorithm); strategy policy pattern implementation

init_thread(global::collector);

Interface for the client to create garbage collectable objects

Collector called after THRESHOLD bytes allocated

Rigourous tests for calculating THRESHOLD and other parameters and at end

GC for other resources like FILES, mutexes etc

GC only for heap based resources

operator functions etc

Work on all kinds of objects eg: user defined classes,containers

```cpp
auto i = new gc<int>;
A(){p=new gc<int>;}
auto i = new gc<A>;
    {
        auto i = new gc<int>;
    } // auto j = i;
shape* s = new circle;
```

heirarchy of ptrs for a type

base classes, lots of them

random root < ptr arithmatic

specialize for is_class to inherit and get interface

With simple resources, do FT-1 assignment 1 in C++

Problems:

Derived to base conversion

Complex resources

# Class has to be canonical

# references must always be initialized

1. Flash Diagrams
2. Simple mark and sweep
3. Interface
	mention memory buffer
4. Client
	placement new
	explicit dtors
	heap expansion and limit
5. UML