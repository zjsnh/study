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


