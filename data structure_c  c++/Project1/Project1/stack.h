#pragma once
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef int Datetype;

class Stack
{
public:
	Stack(int capacity = 4);
	~Stack();

	void Push(Datetype x);
	void New_capacity();
	void Pop();
	void pPop();

private:
	Datetype* _date;
	int _size;
	int _capacity;
};
