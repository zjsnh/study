//#include <iostream>
//using namespace std;
//// ʶ�����������Ƿ���ͬ����ǰ����ģ��Ԫ���^_^
//template<typename T1, typename T2> // ͨ�������� false
//class theSameType 
//{ 
//public: 
//    enum { ret = false }; 
//};
//
//template<typename T>               // ��������������ͬʱ���� true
//class theSameType<T, T> {
//public: 
//    enum { ret = true }; 
//};
//
//template<typename T, int i> class aTMP { };
//
//int main() {
//
//    
//    typedef unsigned  uint; // typedef �������ͱ�������������������
//    typedef uint uint2;
//    uint2 n;
//    cout << typeid(n).name() << endl;
//    std::cout << theSameType<unsigned int, uint2>::ret << '\n';
//
//    std::cout << theSameType<aTMP<unsigned int, 2>, aTMP<uint2, 2>>::ret << '\n';
//    std::cout << theSameType<aTMP<int, 2>, aTMP<int, 3>>::ret << '\n';
//
//    std::cin.get(); 
//    return 0;
//}


////C++ 11
//#include <iostream>
//using namespace std;
//template<typename T>
//class aTMP {
//public: typedef const T reType;
//};
//
//void f() { std::cout << "global f()\n"; }
//
//template<typename T>
//class Base {
//public:
//    template <int N = 99>
//    void f() { std::cout << "member f(): " << N << '\n'; }
//};
//
//template<class T>
//class Derived : public Base<T> {
//public:
//    typename T::reType m; // typename ����ʡ��     ���T��Ϊ��ռ䣬����Ҫ��ģ��ʵ����ʱ���� ʵ��������
//    Derived(typename T::reType a) : m(a) { }
//    void df1() { f(); }                       // ����ȫ�� f()�����������еĻ��� f()
//    void df2() { this-> template f(); }        // ���� f<99>() ��ʾ����
//    void df3() { Base<T>::template f<22>(); } // ǿ�ƻ��� f<22>()
//    void df4() { ::f(); }                     // ǿ��ȫ�� f()
//};
//
//int main() {
//    //Derived<int> b(10);
//    //b.m;
//
//
//    Derived<aTMP<int>> a(10);
//    a.m;
//    a.df1(); 
//    a.df2(); 
//    a.df3(); a.df4();
//    std::cin.get(); return 0;
//}
//
//
//template<typename T>
//T add(T a, T b)
//{
//    return a + b;
//}
//
//
//int main()
//{
//    cout << add(1, 2) << endl;
//    cout << add(1.1, 1.2) << endl;
//    //cout << add(1.2, 1) << endl;
//
//    return 0;
//}


#include<iostream>
using namespace std;

template<typename T0
	,typename T1
	,typename T2
	,typename T3
	,typename T4>
T2 fun(T1 v1, T3 v3, T4 v4)
{
	return 0;
}

int main()
{
	//ʵ����ʱ�����Ǳ���Ҫ�����޷����Ƶ���������Щ����ģ�������  ���� TO T1 T2 ��
	int a = fun<double, int, int, float, char>(1, 2, 3);

	return 0;
}
