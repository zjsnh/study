#include<iostream>
using namespace std;

#include"Hash.h"


int main()
{

	hs::Hash<int, int> H;
	H.Insert(make_pair(1, 4));
	H.Insert(make_pair(2, 4));
	H.Insert(make_pair(3, 4));
	H.Insert(make_pair(4, 4));
	H.Insert(make_pair(5, 4));
	H.Insert(make_pair(6, 4));
	H.Insert(make_pair(7, 4));
	H.Insert(make_pair(7, 4));
	H.Insert(make_pair(7, 4));
	H.Insert(make_pair(7, 4));
	H.Insert(make_pair(7, 4));
	H.Insert(make_pair(7, 4));


	return 0;
}