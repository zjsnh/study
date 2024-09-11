#include<iostream>
using namespace std;
#include"text1.h"
//#include"text2.h"













template<typename T>
T add(T a, T b)
{
	return a + b;
}


//int main()
//{
//	cout << add<int>(1, 2) << endl;
//	cout << add<float>(1.1, 1.2) << endl;
//
//	return 0;
//}

//模板参数的 自动推导
#include<iostream>
using namespace std;

template<typename T0
	, typename T1
	, typename T2
	, typename T3
	, typename T4>
T2 fun1(T1 v1, T3 v3, T4 v4)
{
	T2 a = T2();
}


template<typename T0 = float
	, typename T1
	, typename T2 = double
	, typename T3
	, typename T4>
T2 fun2(T1 v1, T3 v3, T4 v4)
{
	return 0;
}


////
//int main()
//{
//	//实例化时，我们必须要给出无法被推导出来的那些函数模板的类型  例如 TO T1 T2 ；
//	int a = fun1<double, int, double>(1, 2, 3.0);
//
//	//如果我们将无法被推导出来的模板给上默认值 就不用实例化
//	int b = fun2(1, 2, 3.0);
//
//	return 0;
//}
//模板默认值


//重复模板实例

//模板定义与编译分离 
	 //export template


//类模板
//模板参数的省略  如果类模板的所有模板参数都有默认参数，
// 在使用实例的时候就可以省略，但是不能省略 <> 
// 类模板不能自动推导模板参数，只能通过缺省参数省略实例化
//template<class T = int>
//struct list_node
//{
//	list_node<T>* next;
//};

//int main()
//{
//	list_node<> L;
//}

////异至链表
//template<class T, class N>
//struct list_node
//{
//	T _val;
//	N* _next;
//
//	list_node(T val, N* next)
//		:_val(val)
//		, _next(next)
//	{}
//};

//#include <iostream>
//
//// 定义链表节点模板
//template<class T, class N>
//struct list_node
//{
//    T _val;
//    N* _next;
//
//    list_node(T val, N* next)
//        : _val(val)
//        , _next(next)
//    {}
//};
//
//// 示例：创建三个节点并将它们连接起来
//int main() {
//    // 创建第三个节点（末尾节点，_next 为 nullptr）
//    list_node<int, void> node3(3, nullptr);
//
//    // 创建第二个节点，_next 指向 node3
//    list_node<int, list_node<int, void>> node2(2, &node3);
//
//    // 创建第一个节点，_next 指向 node2
//    list_node<int, list_node<int, list_node<int, void>>> node1(1, &node2);
//
//    //输出值
//    cout << node1._val << endl
//        << node1._next->_val << endl
//        << node1._next->_next->_val << endl;
//    
//
//    return 0;
//}


//#include <iostream>
//
//// 通用模板
//template<typename T>
//bool compare(const T& a, const T& b) {
//	return a > b;
//}
//
//// 完全特化（处理 int* 指针类型）
//template<>
//bool compare<int*>( int* const& a,  int* const& b) {
//	return *a > *b;
//}

//
//template<class T1,class T2>
//class Date
//{
//public:
//	void printf()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//};
//
//template<>
//class Date<int, double>
//{
//	void printf()
//	{
//		cout << "Date<int,double>" << endl;
//	}
//
//};
//
//template<class T1>
//class Date<T1,double>
//{
//	void printf()
//	{
//		cout << "Date<double,T1>" << endl;
//	}
//
//};
//
//template<class T1,class T2>
//class Date<T1*,T2*>
//{
//	void printf()
//	{
//		cout << "Date<T1*,T2*>" << endl;
//	}
//
//};

enum color
{
	red,
	blue
};

template<class T1,enum color>
class Date
{
public:
	swaitch()
	{
		//....
	}
private:
	
};