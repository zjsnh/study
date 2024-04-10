#include"heap.h"

int main()
{
	Heap h;
	h.Push(7);
	h.Push(8);
	h.Push(5);
	h.Push(3);
	h.Push(4);
	h.Push(1);
	h.Push(2);


	cout << h;

	return 0;
}
