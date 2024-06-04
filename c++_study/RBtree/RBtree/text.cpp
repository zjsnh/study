#include<iostream>
using namespace std;
#include"RBtree.h"

//int main()
//{
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	RBTree<int, int> A;
//
//	for (auto e : a)
//	{
//		A.insert(pair<int, int>(e, e));
//	}
//
//	A.InOrder();
//	return 0;
//}

int main()
{
	RBTree<int, int> A;
	for (int i = 0; i < 10; i++)
	{
		int e = rand() % 100000;

		if (e == 26500)
		{
			int a = 0;
		}
		A.insert(make_pair(e, e));
		
	}

	cout << A.IsBlance() << endl;
	
	return 0;
}