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
//	//����ָ��
//	function<void(int& a, int& b)> f2 = swapFunc;
//
//	//�º���
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
	//����ָ��
	function<void(int& a, int& b)> f1 = swapFunc;

	//�º���
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
		{"����ָ��",swapFunc},{"�º���",Swap()},{"lambda", f}
	};

	cmdOP["����ָ��"](a, b);
	cout << a << " " << b << endl;

	cmdOP["�º���"](a, b);
	cout << a << " " << b << endl;

	cmdOP["lambda"](a, b);
	cout << a << " " << b << endl;
}

void Bind_function()
{

	//���ھ�̬��Ա������&�ɼӿɲ���
	//function<int(int, int)> f1 = &Plus::plusi;
	function<int(int, int)> f1 = Plus::plusi;
	cout << f1(1, 2) << endl;


	//�Ǿ�̬��Ա���� �����& ����Ҫ
	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus ps;
	f2(&ps, 1.1, 1.2);


	function<double(Plus,double, double)> f3 = &Plus::plusd;
	f3(Plus(), 1.2, 1.3);


	//bind ������
	function<double(double, double)> f4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	f4(1.3, 1.4);

}

void Bind()
{
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	//ͨ��placeholder  �����������ݵ�˳��
	//function<void(int&, int&)> f = bind(swapFunc, placeholders::_1, placeholders::_2);
	function<void(int&, int&)> f = bind(swapFunc, placeholders::_2, placeholders::_1);
	//_2 ->b  _1 ->a;

	cout << a << " " << b << endl;


	//���ݹ̶�����
	//ԭ��   ��������  function<double(Plus,double, double)>  �̶��ľͲ���д������������  ��һ�������ǿɵ��ö���
	function<double(double)> f1 = bind(&Plus::plusd, Plus(), 20.0, placeholders::_1);
	cout << f1(2.0) << endl;
}

int main()
{
	//function ����Ӧ��
	//Function();

	//bind 
	Bind();

	//bind  function  ��Ա������function
	//Bind_function();


	return 0;
}