//#include <iostream>
//using namespace std;
//// 识别两个类型是否相同，提前进入模板元编程^_^
//template<typename T1, typename T2> // 通例，返回 false
//class theSameType 
//{ 
//public: 
//    enum { ret = false }; 
//};
//
//template<typename T>               // 特例，两类型相同时返回 true
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
//    typedef unsigned  uint; // typedef 定义类型别名而不是引入新类型
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


//C++ 11
#include <iostream>
using namespace std;
template<typename T>
class aTMP {
public: typedef const T reType;
};

void f() { std::cout << "global f()\n"; }

template<typename T>
class Base {
public:
    template <int N = 99>
    void f() { std::cout << "member f(): " << N << '\n'; }
};

template<class T>
class Derived : public Base<T> {
public:
    typename T::reType m; // typename 不能省略     如果T作为类空间，就需要在模板实例化时传入 实例化的类
    Derived(typename T::reType a) : m(a) { }
    void df1() { f(); }                       // 调用全局 f()，而非想象中的基类 f()
    void df2() { this-> template f(); }        // 基类 f<99>() 显示传递
    void df3() { Base<T>::template f<22>(); } // 强制基类 f<22>()
    void df4() { ::f(); }                     // 强制全局 f()
};

int main() {
    //Derived<int> b(10);
    //b.m;


    Derived<aTMP<int>> a(10);
    a.m;
    a.df1(); 
    a.df2(); 
    a.df3(); a.df4();
    std::cin.get(); return 0;
}



int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1.1, 1.2) << endl;
    cout << add(1.2, 1) << endl;

    return 0;
}