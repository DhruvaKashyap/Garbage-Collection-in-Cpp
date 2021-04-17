# Garbage-Collection-in-Cpp

Team members:
Abhijit Mohanty	PES1201801293 Section C
Dhruva Kashyap	PES1201801457 Section F
Thrivikraman V 	PES1201801469 Section D

```cpp

template T
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

main()
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
