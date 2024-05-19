#include<iostream>
#include<string>
using namespace std;

#include"inherir.h"

//int main()
//{
//	Student s;
//	Teacher t;
//
//
//	s.Print();
//
//	return 0;
//}


//class A
//{
//protected:
//	int _a;
//};
//
//class B :public A
//{
//protected:
//	int _b;
//};
//
//class C
//{
//protected:
//	int _a;
//};
//
//class D
//{
//protected:
//	C _c;
//	int _b;
//};
//
//int main()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(D) << endl;
//}


//class A
//{
//public:
//	A(const char* a)
//	{
//		cout << a;
//	}
//
//	~A()
//	{}
//};
//
//class B:virtual public A
//{
//public:
//	B(const char* b, const char* a)
//		:A(a)
//	{
//		cout << b;
//	}
//
//	~B()
//	{}
//};
//
//class C :virtual public A
//{
//public:
//	C(const char* c, const char* a)
//		:A(a)
//	{
//		cout << c;
//	}
//
//	~C()
//	{}
//};
//
//class D :public B, public C
//{
//public:
//	D(const char* a, const char* b, const char* c, const char* d)
//		:B(b,a)
//		,C(c,a)
//		,A(a)
//	{
//		cout << d;
//	}
//
//	~D()
//	{}
//
//};
//
//int main()
//{
//	D *p=new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//
//}

//class A
//{
//
//};
//
//
//class Person
//{
//public:
//	virtual void BuyTickett()
//	{
//		cout << "Person()" << endl;
//
//	}
//};
//
//class Student :public Person
//{
//public:
//	void BuyTickett()
//	{
//		cout << "Student()" << endl;
//
//	}
//
//};
//
//void fun(Person& p)
//{
//	p.BuyTickett();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	fun(ps);
//	fun(st);
//
//	return 0;
//
//}

//#include <iostream>
//#include <iterator>
//using namespace std;

//struct Date {
//
//    int years;
//    int months;
//    int days;
//} ;
//
//int getMonthdays(const int year, const int month) {
//    int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)) {
//        return 29;
//    }
//
//    return months[month];
//}
//
//Date& fun(Date& d) {
//
//    while (d.days > getMonthdays(d.years, d.months)) {
//        d.days -= getMonthdays(d.years, d.months);
//        ++d.months;
//
//        if (d.months == 13) {
//            ++d.years;
//            d.months = 1;
//        }
//        
//    }
//    return d;
//}
//
//int main() {
//    int a, b;
//    while (cin >> a >> b) { // 注意 while 处理多个 case
//
//        Date d;
//        d.days = b;
//        d.months = 1;
//        d.years = a;
//
//        fun(d);
//
//        cout << d.years << "-" << d.months << "-" << d.days;
//
//    }
//
//    return 0;
//}
int main()

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;

}


