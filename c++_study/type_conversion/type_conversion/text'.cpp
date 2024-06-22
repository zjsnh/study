#include<iostream>
using namespace std;


//  static_cast
//  reinterpret_cast
//  const_cast
//  dynamic_cast

class A
{
public:

	virtual void Print_A()
	{
		cout << "virtual void Print()" << endl;
	}

	int _a = 1;
};

class B: public A
{
public:

	int _b = 1;
};


//越界 报错
//void fun(A* us)
//{
//	B* ptr = (B*)us;
//	ptr->_a++;
//	ptr->_b++;
//}

void fun(A* us)
{
	B* ptr = dynamic_cast<B*>(us);
	if (ptr)
	{
		ptr->_a++;
		ptr->_b++;

		cout << "action" << endl;
	}
	else
	{

		cout << "越界" << endl;
	}
}

int main()
{
	// 向下转换规则：父类对象不能转换成子类对象，但是父类指针和引用可以转换子类指针和引用
	A a;
	B b;
	fun(&a);
	fun(&b);

	return 0;

}