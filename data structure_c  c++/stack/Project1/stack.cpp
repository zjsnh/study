#include"stack.h"

Stack::Stack(int capacity=4)
{
	_data = (Datatype*)malloc(sizeof(Datatype) * capacity);
	if (_data == nullptr)
	{
		perror("malloc");
		exit(-1);
	}

	int _size = 0;

}

Stack::~Stack()
{
	free(_data);
	_data = nullptr;
	_size = _capacity = 0;
}

void Stack::New_capacity()
{
	_capacity *= 2;

	Datatype* temp = (Datatype*)malloc(sizeof(int) * _capacity);
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}

	_data = temp;
}

void Stack::Push(Datatype x)
{
	if (_size == _capacity)
	{
		New_capacity();
	}

	_data[_size++] = x;

}

void Stack::Pop()
{
	_size--;

}

Datatype Stack::pPop()
{
	return _data[_size - 1];
}