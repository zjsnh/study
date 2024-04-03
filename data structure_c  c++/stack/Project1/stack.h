#pragma once
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef int Datatype;

class Stack
{
public:
	Stack(int capacity = 4);
	~Stack();

	void Push(Datatype x);
	void New_capacity();
	void Pop();
	void pPop();

private:
	Datatype* _data;
	int _size;
	int _capacity;
};
