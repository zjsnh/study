#pragma once
#include<iostream>
#include<cassert>
#include<cstdbool>
using namespace std;

typedef int Datatype;

struct Sqlist
{
public:
	Sqlist(int capacity=4);
	~Sqlist();

	void Insert(Datatype data);//Ôö
	int seek(Datatype data);//²é

	void Erase(int size);//É¾
	void Alter(int size, Datatype newData);//¸Ä

	bool Empty();

private:
	void Newcapacity();
	Datatype* _data;
	int _size;
	int _capacity;
};

//
//class sqlist
//{
//private:
//	Sqlist* head;
//};
