#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

using namespace std;
typedef int Datetype;

struct queueNode
{
	Datetype _data;
	queueNode* next;
};


class Queue
{
public:
	Queue();
	~Queue();
	bool empty();
	int size();
	Datetype Front();
	Datetype Back();
	void push_back(Datetype x);
	void pop_front();

private:
	queueNode* front;
	queueNode* tail;
};

