#include"heap.h"


Heap::Heap(int capacity)
{
	_capacity = capacity;
	_size = 0;

	Datatype* temp = (Datatype*)malloc(sizeof(Datatype) * _capacity);
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}

	heap = temp;
}

Heap::~Heap()
{
	free(heap);
	heap = nullptr;
	_capacity = _size = 0;
}

void Heap::New_capacity() {
	_capacity *= 2;  


	Datatype* temp = (Datatype*)realloc(heap, sizeof(Datatype) * _capacity);
	if (temp == nullptr) {
		perror("realloc");  
		exit(-1);  
	}


	heap = temp;
}



void Heap::adjustup(int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (heap[parent] < heap[child])
		{
			swap(heap[parent] , heap[child]);
		}

		child = parent;
		parent = (child - 1) / 2;
	}
}

void Heap::Push(Datatype a)
{
	if (_size == _capacity)
	{
		New_capacity();
	}
	heap[_size++] = a;

	adjustup(_size-1);

}

void Heap::adjustdown()
{
	int parent = 0;
	int child = parent * 2 + 1;

	while (child < _size)
	{
		if (child + 1 < _size && heap[child] < heap[child + 1])
		{
			child += 1;
		}

		if (heap[parent] < heap[child])
		{
			swap(heap[parent], heap[child]);
		}

		parent = child;

		child = parent * 2 + 1;
	}
}

Datatype Heap::TPop()
{
	assert(!Empty());

	Datatype temp = heap[0];

	swap(heap[0], heap[--_size]);
	adjustdown();
	cout << temp;
	return temp;
}

bool Heap::Empty()
{
	return _size == 0;
}