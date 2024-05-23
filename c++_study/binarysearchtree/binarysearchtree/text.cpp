#include"binarysearchtree.h"


int main()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BStree<int> bs;
	for (auto e : a)
	{
		bs.InsertR(e);
	}

	bs.InOrder();

	bs.EraseR(8);
	bs.InOrder();

	for (auto e : a)
	{
		bs.EraseR(e);
		bs.InOrder();
	}

	return 0;
}