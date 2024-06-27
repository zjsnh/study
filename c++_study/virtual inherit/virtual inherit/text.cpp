#include <iostream>
using namespace std;
class Base {
public:
	Base(int i) { cout << i; }
	~Base() {}
};
class Base1 : virtual public Base {
public:
	Base1(int i, int j = 0) : Base(j)
	{
		cout << i;
	}
	~Base1() {}
};


class Base2 : virtual public Base
{
public:
	Base2(int i, int j = 0) 
		: Base(j) 
	{ cout << i; }


	~Base2() {}
};



class Derived :public Base2, public Base1
{
public:
	Derived(int a, int b, int c, int d) :mem1(a), mem2(b), Base1(c), Base2(d), Base(a)
	{
		cout << b;
	}
private:

	Base2 mem2;
	Base1 mem1;
};


int main() 
{ 
	Derived objD(1, 2, 3, 4); return 0;
}