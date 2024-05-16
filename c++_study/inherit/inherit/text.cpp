#include<iostream>
#include<string>
using namespace std;

#include"inherir.h"

//int main()
//{
//	Student s;
//	Teacher t;
//
//
//	s.Print();
//
//	return 0;
//}


//class A
//{
//protected:
//	int _a;
//};
//
//class B :public A
//{
//protected:
//	int _b;
//};
//
//class C
//{
//protected:
//	int _a;
//};
//
//class D
//{
//protected:
//	C _c;
//	int _b;
//};
//
//int main()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(D) << endl;
//}


class A
{
public:
	A(const char* a)
	{
		cout << a;
	}

	~A()
	{}
};

class B:virtual public A
{
public:
	B(const char* b, const char* a)
		:A(a)
	{
		cout << b;
	}

	~B()
	{}
};

class C :virtual public A
{
public:
	C(const char* c, const char* a)
		:A(a)
	{
		cout << c;
	}

	~C()
	{}
};

class D :public B, public C
{
public:
	D(const char* a, const char* b, const char* c, const char* d)
		:B(b,a)
		,C(c,a)
		,A(a)
	{
		cout << d;
	}

	~D()
	{}

};

int main()
{
	D *p=new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;

}