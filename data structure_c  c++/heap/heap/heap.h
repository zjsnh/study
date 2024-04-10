#pragma once
#include<iostream>
#include<cassert>
#include<cstdbool>
using namespace std;


typedef int Datatype;

class Heap
{
	friend inline ostream& operator<<(ostream& out, const Heap& h);
public:
	Heap(int capacity=4);
	~Heap();
	void Push(Datatype a);
	Datatype TPop();
	bool Empty();

private:
	void adjustup(int child);
	void adjustdown();

	inline void swap(Datatype& q1, Datatype& q2)
	{
		Datatype temp = q1;
		q1 = q2;
		q2 = temp;
	}

	void New_capacity();
	Datatype* heap;
	int _size;
	int _capacity;
};

inline ostream& operator<<(ostream& out, Heap& h)
{
	while (!h.Empty())
	{
		out << h.TPop()<<" ";
	}

	out << endl;

	return out;
}