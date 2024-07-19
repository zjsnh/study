#include<iostream>
#include<deque>
using namespace std;

#include"stack.h"
#include"queue.h"
#include"priority_queue.h"

//template <class T>
//class Less
//{
//public:
//	bool operator()(const T& p1, const T& p2)
//	{
//		return p1 < p2;
//	}
//};
//
//template<class T>
//class Less<T*>
//{
//public:
//	bool operator()(T* x, T* y)
//	{
//		return *x < *y;
//	}
//};
//
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x > y;
//	}
//};
//
//int main()
//{
//	/*priority::priority_queue<int,vector<int>,Greater<int>> q;
//
//	q.push(1);
//	q.push(7);
//	q.push(5);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.top() << " ";
//		q.pop();
//	}
//	cout << endl;*/
//
//	vector<int> v = { 1,7,5,4 };
//
//	/*priority::priority_queue<int> p;*/
//	priority::priority_queue<int, vector<int>, Greater<int>> p(v.begin(), v.end());
//	/*p.push(1);
//	p.push(7);
//	p.push(5);
//	p.push(4);*/
//	
//
//	while (!p.empty())
//	{
//		cout << p.top() << " ";
//		p.pop();
//	}
//	cout << endl;
//	return 0;
//}


//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 特化 -- 全特化
//template<>
//class Data<int, double>
//{
//public:
//	Data() { cout << "Data<int, double>" << endl; }
//};
//
//template<class T>
//class a
//{
//public:
//	a()	{}
//};
//
//template<>
//class a<int>
//{
//public:
//	a()	{}
//};


//
//int main()
//{
//	sk::stack<int> s;
//	return 0;
//}


int main()
{
	sk::stack<int> S;
	S.push(1);
	S.push(9);
	S.push(8);
	S.push(7);
	S.push(3);
	S.push(2);

	for (auto e : S)
	{
		cout << e << endl;
	}
	return 0;
}