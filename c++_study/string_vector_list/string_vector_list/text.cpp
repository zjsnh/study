#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//#include"string.h"
//#include"vector.h"


//#include"list.h"
//#include"vector.h"
//#include"string.h"
//#include<vector>


//int main()
//{
//	vec::vector<string> w;
//	w.push_back("11111111111111111111111");
//	w.push_back("11111111111111111111111");
//	w.push_back("11111111111111111111111");
//	w.push_back("11111111111111111111111");
//	w.push_back("11111111111111111111111");
//	//memcpy虽然将vector内的空间值拷贝了过去，但是，string内指向的空间并没有被深拷贝，
//	//导致释放原来空间的时候，数据找不到
//
//
//	for (auto e : w)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//
//	return 0;
//}

//int main()
//{
//	lt::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//
//
//	lt::list<int>::const_iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	return 0;
//
//}

//void Print(const lt::list<int>& l)
//{
//	lt::list<int>::const_reverse_iterator it = l.rbegin();
//
//	cout << *it << " ";
//	while (it != l.rend())
//	{
//		cout << *it << " ";
//		it++;
//	}
//}
//
//int main()
//{
//	//sk::stack<int, lt::list<int>> s;
//	
//	lt::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//
//	Print(l);
//
//	return 0;
//
//
//}

//void Print(const vec::vector<int>& s)
//{
//	vec::vector<int>::const_reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}
//
//int main()
//{
//	vec::vector<int> s;
//
//	s.push_back(1);
//	s.push_back(2);
//	s.push_back(3);
//	s.push_back(4);
//
//	/*vec::vector<int>::reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}*/
//
//	/*vec::vector<int>::const_reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}*/
//
//	Print(s);
//
//	return 0;
//}


//int main()
//{
//	vec::vector<int> V(10, 2);
//	V.insert(V.begin(), 8);
//
//
//
//	vec::vector<int>::iterator it = V.find(8);
//	cout << *it;
//
//	return 0;
//}

#include<iostream>
using namespace std;
#include"string.h"
#include"list.h"



int main()
{
	/*str::string r1("hello");
	str::string r2 = r1;
	str::string r3 = move(r1);*/

	lt::list<int> L = { 1,2,3,4 };

	/*lt::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);*/


	return 0;
}