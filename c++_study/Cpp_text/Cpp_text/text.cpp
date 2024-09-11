//#include <iostream>
//using namespace std;
//int main() {
//    cout << sizeof(long) << endl;
//    cout << sizeof(int) << endl;
//    /*int zero = 0;
//    short one = 1;*/
//    //int three = zero - one;
//
//    unsigned char zero = 0, one = 1;
//    //突然想到decltype可以获取表达式类型  
//    decltype(zero - one) ret;
//    cout << typeid(ret).name() << endl;
//    if ((zero-one) < zero)
//        std::cout << "less";
//    else
//        std::cout << "more";
//
//}


//#include <iostream>
//
//struct A {
//	A(int i) : m_i(i) {}
//
//	operator bool() const 
//	{ 
//		return m_i > 0; 
//	}
//
//	int m_i;
//};
//
//int main() {
//	A a1(1), a2(2);
//	std::cout << a1 - a2;
//	std::cout << (a1 == a2);
//
//
//	return 0;
//}

#include <iostream>

struct X {
    X() { std::cout << "1"; }

    X(const X& )  
    { 
        std::cout << "3"; 
    }

    ~X() { std::cout << "2"; }

    void f() { std::cout << "4"; }

} object;

int main() {
    X(object);

    object.f();

    return 0;
}

