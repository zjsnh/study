#pragma once
#include<iostream>
using namespace std;


class sort
{
	sort();
	~sort();

	void q_sort();
	void q_non_sort();

private:
	int* _data;
	int size;
};