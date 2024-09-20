#include<iostream>
using namespace std;
#include<string>
#include<list>
//
//namespace text
//{
//	string to_string(int val)
//	{
//		string ret;
//		while (val)
//		{
//			int a = val % 10;
//			val /= 10;
//			ret += ('0' + a);
//		}
//
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//
//	
//}
//int main()
//{
//	//string s = text::to_string(1234);
//
//	string r1("hello");
//	string r2 = r1;
//	string&& r3 = move(r1);
//
//
//	return 0;
//}


//int main()
//{
//	list<int> L{ 1,2,3,4,5 };
//	
	//pair<int, char> p;
	//list<pair<int, char>> Ls{ p, {1,'q'},{2,'w'},{3,'e'} };
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year,int month,int day)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1{ 2024,9,18 };
//	Date d2[]{ {2024,9,18},{2024,9,17} ,{2024,9,16} };
//
////	return 0;
////}
//
//
//class _list
//{
//public:
//	_list(const initializer_list<int>& L)
//	{
//		initializer_list<int>::iterator it = L.begin();
//		while (it != L.end())
//		{
//			cout << *it << " ";
//			it++;
//		}
//	}
//};
//
//int main()
//{
//	_list l{ 1,2,3,4 };
//
//	return 0;
//}


//int main()
//{
//	auto a;
//	auto b = 1.2;
//
//	list < pair<string, int>> l;
//	auto c = l.begin();
//	list<pair<string, int>>::iterator it = l.begin();
//
//	return 0;
//}

//template<class T2>
//T2 fun1()
//{
//	return T2();
//}
//
//template<class T1,class T2>
//void fun(T1 a)
//{
//	T2 b = fun1();
//}
//
////通过auto 在传递模板参数的时候，传入一个就可以
//template<class T1>
//void fun(T1 a)
//{
//	auto b = fun1();
//}


//#include<stack>
//#include<string>
//#include<list>
//#include<unordered_map>
//#include<vector>
//
//
//int main()
//{
//	stack<int> S;
//	S.push(1);
//
//
//
//
//	return 0;
//}

//void _List()
//{
//	cout << "end" << endl;
//}

//template<class T, class ...Args>
//void _List(const T& val, Args... args)
//{
//	_List(args...);
//}
//
//template<typename T>
//T sum(T t)
//{
//	return t ;
//}
//template<typename T, typename ... Types>
//T sum(T first, Types ... rest)
//{
//	return first + sum<T>(rest...);
//
//	//   1  +  (2,3,4)  ->  1  +  (2 + (3,4)) ->  
//}
//
//int main()
//{
//	_List(1, 2, 3, 4);
//	return 0;
//}

 //  ... 也就是将参数包展开，依次调用

//template <class T>
//void printarg(T t)
//{
//	cout << t << endl;
//	//return t;
//}
//
//template <class ...Args>
//void expand(Args... args)
//{
//	int arr[] = { (printarg(args)，0)... };
//}
//
//int main()
//{
//	expand(1, 2, 3, 4, 5);
//	return 0;
//}


//template <class T, class R, typename... Args>
//class  MyDelegate
//{
//public:
//    MyDelegate(T* t, R(T::* f)(Args...)) :m_t(t), m_f(f) {}
//
//    R operator()(Args&&... args)
//    {
//        return (m_t->*m_f)(std::forward<Args>(args) ...);
//    }
//
//private:
//    T* m_t;
//    R(T::* m_f)(Args...);
//};
//
//template <class T, class R, typename... Args>
//MyDelegate<T, R, Args...> CreateDelegate(T* t, R(T::* f)(Args...))
//{
//    return MyDelegate<T, R, Args...>(t, f);
//}
//
//struct A
//{
//    void Fun(int i) { cout << i << endl; }
//    void Fun1(int i, double j) { cout << i + j << endl; }
//};
//
//int main()
//{
//    A a;
//    auto d = CreateDelegate(&a, &A::Fun); //创建委托
//
//    cout << typeid(d).name() << endl;
//    d(1); //调用委托，将输出1
//    auto d1 = CreateDelegate(&a, &A::Fun1); //创建委托
//
//    cout << typeid(d1).name() << endl;
//    d1(1, 2.5); //调用委托，将输出3.5
//
//
//    return 0;
//}



//#include <iostream>
//
//// 使用模板参数包和函数参数包
//template<typename... Args>
//void Size(Args... args) {
//
//    std::cout << "参数包类型数量: " << sizeof...(Args) << std::endl;
//
//    std::cout << "参数包数量: " << sizeof...(args) << std::endl;
//}
//
//int main() {
//    Size(1, 2, 3);   
//    Size(10, 20.5);
//
//    return 0;
//}


#include <tuple>
#include <iostream>

// 一个简单的容器类，接受不定数量的参数并存储
template<typename... Args>
class MyContainer {
public:
    MyContainer(Args... args) : data(args...) {}  // 构造函数使用参数包

    void printData() {
        printTuple(data);
    }

private:
    std::tuple<Args...> data;  // 使用 tuple 存储不定数量的参数

    // 辅助函数，用于逐个打印 tuple 元素
    template<std::size_t Index = 0>
    void printTuple(const std::tuple<Args...>& tup) {
        if constexpr (Index < sizeof...(Args)) {  // 递归基条件
            std::cout << std::get<Index>(tup) << " ";
            printTuple<Index + 1>(tup);
        }
    }
};

int main() {
    MyContainer<int, double, string> container(42, 3.14, "Hello");
    container.printData();
    // 输出：42 3.14 Hello

    return 0;
}
