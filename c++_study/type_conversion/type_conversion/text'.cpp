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


//Խ�� ����
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

		cout << "Խ��" << endl;
	}
}

int main()
{
	// ����ת�����򣺸��������ת����������󣬵��Ǹ���ָ������ÿ���ת������ָ�������
	A a;
	B b;
	fun(&a);
	fun(&b);

	return 0;

}