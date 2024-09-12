#include<iostream>
using namespace std;
#include<string>

//继承 概念
// 继承关系
//继承子类对象对基类的赋值
//子类对象内基类对象的创建，销毁时间
// 基类 派生类的类型转换
//继承 友元 static
//多继承
//菱形继承
//多态





typedef void(*Fun)();

//多态
class animal  //基类
{
public:
	virtual void call()
	{
		cout << "animal: 你好" << endl;
	}

	string _animal = "anminal";
};

class dog : public animal
{
public:

	void call() override
	{
		cout << "dog : 汪汪" << endl;
	}

	string _dog = "dog";
};

void VFun(Fun* a)
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		cout << i << ":" << a[i] << endl;
		Fun f = a[i];
		(*f)();
	}
	cout << endl;
}


int main()
{
	dog D;
	animal A;
	D._dog;


	//cout << &(D.call_dog()) << endl;
	//cout << (Fun)(*(int*)&D);
	cout << &D << endl;
	printf("%p: D.call:\n", &dog::call);
	printf("%p 虚表:\n", *((int*)&D));
	/*Fun a = (Fun)(*((int*)&D));
	a();*/
	Fun* a = (Fun*)(*((int*)&D));
	//(&a)();

	VFun((Fun*)(*((int*)&D)));
	return 0;
}