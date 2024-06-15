#include<iostream>

using namespace std;


void _ShowList()
{
	cout << endl;
}

template<class T, class ...Args>
void _ShowList(const T& val, Args... args)
{
	cout << val << " ";
	_ShowList(args...);
}


template<class ...Args>
void ShowList(Args... args)
{
	_ShowList(args...);
}


int main()
{
	ShowList(1);
	ShowList(1,"xxxx");
	ShowList(1, "111", 2.2, 9);

	return 0;
}