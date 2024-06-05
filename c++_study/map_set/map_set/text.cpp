#include<iostream>
using namespace std;

#include"RBtree.h"
#include"map.h"
#include"set.h"


//int main()
//{
//	mp::map<string, string> m;
//	m.insert(make_pair("sort", "ÅÅÐò"));
//	m.insert(make_pair("left", "ÅÅÐò"));
//	m.insert(make_pair("right", "ÅÅÐò"));
//	m.insert(make_pair("nihao", "ÅÅÐò"));
//
//	/*for (auto& e : m)
//	{
//		cout << m[string("sort")];
//		++e;
//	}*/
//	mp::map<string, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << ": " << it->second << endl;
//		++it;
//	}
//
//
//	return 0;
//}


int main()
{
	st::set<int> m;
	m.insert(1);
	m.insert(2);
	m.insert(3);
	/*for (auto& e : m)
	{
		cout << m[string("sort")];
		++e;
	}*/
	st::set<int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << *it;
		++it;
	}
}