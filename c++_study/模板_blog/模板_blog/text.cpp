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

//ģ������� �Զ��Ƶ�
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
//	//ʵ����ʱ�����Ǳ���Ҫ�����޷����Ƶ���������Щ����ģ�������  ���� TO T1 T2 ��
//	int a = fun1<double, int, double>(1, 2, 3.0);
//
//	//������ǽ��޷����Ƶ�������ģ�����Ĭ��ֵ �Ͳ���ʵ����
//	int b = fun2(1, 2, 3.0);
//
//	return 0;
//}
//ģ��Ĭ��ֵ


//�ظ�ģ��ʵ��

//ģ�嶨���������� 
	 //export template


//��ģ��
//ģ�������ʡ��  �����ģ�������ģ���������Ĭ�ϲ�����
// ��ʹ��ʵ����ʱ��Ϳ���ʡ�ԣ����ǲ���ʡ�� <> 
// ��ģ�岻���Զ��Ƶ�ģ�������ֻ��ͨ��ȱʡ����ʡ��ʵ����
//template<class T = int>
//struct list_node
//{
//	list_node<T>* next;
//};

//int main()
//{
//	list_node<> L;
//}

////��������
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
//// ��������ڵ�ģ��
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
//// ʾ�������������ڵ㲢��������������
//int main() {
//    // �����������ڵ㣨ĩβ�ڵ㣬_next Ϊ nullptr��
//    list_node<int, void> node3(3, nullptr);
//
//    // �����ڶ����ڵ㣬_next ָ�� node3
//    list_node<int, list_node<int, void>> node2(2, &node3);
//
//    // ������һ���ڵ㣬_next ָ�� node2
//    list_node<int, list_node<int, list_node<int, void>>> node1(1, &node2);
//
//    //���ֵ
//    cout << node1._val << endl
//        << node1._next->_val << endl
//        << node1._next->_next->_val << endl;
//    
//
//    return 0;
//}


//#include <iostream>
//
//// ͨ��ģ��
//template<typename T>
//bool compare(const T& a, const T& b) {
//	return a > b;
//}
//
//// ��ȫ�ػ������� int* ָ�����ͣ�
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