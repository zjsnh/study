#include<iostream>
using namespace std;
#include"hash.h"


int main()
{
	hash_bucket::Hash<int, int> h;

	h.Insert(make_pair(1,2));
	h.Insert(make_pair(2,2));
	h.Insert(make_pair(33,2));
	h.Insert(make_pair(33,3));
	h.Insert(make_pair(33,4));
	h.Insert(make_pair(33,5));
	h.Insert(make_pair(33,6));
	h.Insert(make_pair(33,7));
	h.Insert(make_pair(33,8));
	h.Insert(make_pair(33,9));
	h.Insert(make_pair(33,0));
	h.Insert(make_pair(33,11));
	h.Insert(make_pair(33,34));
	h.Insert(make_pair(4,2));
	h.Insert(make_pair(5,2));
	h.Insert(make_pair(6,2));
	h.Insert(make_pair(7,2));
	h.Insert(make_pair(8,2));
	return 0;
}