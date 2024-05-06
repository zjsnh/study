#include<iostream>
#include<list>

using namespace std;

#include"list.h"


int main()
{
	/*lt::list<int> l;

	l.push_back(1);

	return 0;*/


	lt::list<int> l;

	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(6);

	lt::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		
		cout << *it << " ";
		cout << it.operator*() << " ";
		++it;
	}

	return 0;

}