#include<iostream>
using namespace std;
#include<functional>
#include<string>
#include<map>




void swapFunc(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

struct Swap
{
	void operator()(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};


//int main()
//{
//	auto f = [](int& a, int& b)
//		{
//			int tmp = a;
//			a = b;
//			b = tmp;
//		};
//
//	int a = 1;
//	int b = 2;
//	f(a, b);
//
//	cout << a << " " << b << endl;
//
//	//函数指针
//	function<void(int& a, int& b)> f2 = swapFunc;
//
//	//仿函数
//	function<void(int& a, int& b)> f2 = Swap();
//
//	//lambda
//	function<void(int& a, int& b)> f3 = [](int& a, int& b)
//		{
//			int tmp = a;
//			a = b;
//			b = tmp;
//		};
//
//	f3(a, b);
//	cout << a << " " << b << endl;
//
//	return 0;
//}


class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}


	double plusd(double a, double b)
	{
		return a + b;
	}

};


void Function()
{
	int a = 1;
	int b = 2;
	//函数指针
	function<void(int& a, int& b)> f1 = swapFunc;

	//仿函数
	function<void(int& a, int& b)> f2 = Swap();

	//lambda
	function<void(int& a, int& b)> f3 = [](int& a, int& b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		};


	auto f = [](int& a, int& b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		};

	//map<string, function<bool(int, int)>> cmdOP;
	map<string, function<void(int&, int&)>> cmdOP = {
		{"函数指针",swapFunc},{"仿函数",Swap()},{"lambda", f}
	};

	cmdOP["函数指针"](a, b);
	cout << a << " " << b << endl;

	cmdOP["仿函数"](a, b);
	cout << a << " " << b << endl;

	cmdOP["lambda"](a, b);
	cout << a << " " << b << endl;
}

void Bind_function()
{

	//对于静态成员函数，&可加可不加
	//function<int(int, int)> f1 = &Plus::plusi;
	function<int(int, int)> f1 = Plus::plusi;
	cout << f1(1, 2) << endl;


	//非静态成员函数 类域和& 都需要
	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus ps;
	f2(&ps, 1.1, 1.2);


	function<double(Plus,double, double)> f3 = &Plus::plusd;
	f3(Plus(), 1.2, 1.3);


	//bind 绑定类域
	function<double(double, double)> f4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	f4(1.3, 1.4);

}

void Bind()
{
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	//通过placeholder  交换参数传递的顺序
	//function<void(int&, int&)> f = bind(swapFunc, placeholders::_1, placeholders::_2);
	function<void(int&, int&)> f = bind(swapFunc, placeholders::_2, placeholders::_1);
	//_2 ->b  _1 ->a;

	cout << a << " " << b << endl;


	//传递固定数据
	//原本   函数参数  function<double(Plus,double, double)>  固定的就不用写出来！！！！  第一个参数是可调用对象
	function<double(double)> f1 = bind(&Plus::plusd, Plus(), 20.0, placeholders::_1);
	cout << f1(2.0) << endl;
}

int main()
{
	//function 基本应用
	//Function();

	//bind 
	Bind();

	//bind  function  成员函数的function
	//Bind_function();


	return 0;
}