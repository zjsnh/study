#include"stack.h"

Stack::Stack(int capacity=4)
{
	_date = (Datetype*)malloc(sizeof(Datetype) * capacity);
	if (_date == nullptr)
	{
		perror("malloc");
		exit(-1);
	}

	int _size = 0;

}

Stack::~Stack()
{
	free(_date);
	_date = nullptr;
	_size = _capacity = 0;
}

void Stack::New_capacity()
{
	_capacity *= 2;

	Datetype* temp = (Datetype*)malloc(sizeof(int) * _capacity);
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}

	_date = temp;
}

void Stack::Push(Datetype x)
{
	if (_size == _capacity)
	{
		New_capacity();
	}

	_date[_size++] = x;

}

void Stack::Pop()
{

}

void Stack::pPop()
{

}