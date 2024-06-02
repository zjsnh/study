#include<iostream>
using namespace std;
#include"AVLtree.h"



int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> A;

	for (auto e : a)
	{
		A.insert(pair<int, int>(e, e));
	}

	A.InOrder();

	return 0;

}