#include<iostream>
using namespace std;

#include"RBtree.h"
#include"map.h"
#include"set.h"


int main()
{
	mp::map<string, string> m;
	m.insert(make_pair("sort", "����"));
	m.insert(make_pair("left", "����"));
	m.insert(make_pair("right", "����"));
	m.insert(make_pair("nihao", "����"));

	/*for (auto& e : m)
	{
		cout << m[string("sort")];
		++e;
	}*/
	mp::map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ": " << it->second << endl;
		++it;
	}


	return 0;
}