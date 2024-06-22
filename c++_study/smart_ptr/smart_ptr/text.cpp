#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"shared_ptr.h"


int main()
{
	smart_ptr::shared_ptr<int> sp1;
	smart_ptr::shared_ptr<int> sp2(new int[10], 
		[](int* ptr) 
		{
			delete[]ptr; 
			cout << "delete[]" << endl; 
		});

	smart_ptr::shared_ptr<FILE> file(fopen("Text.cpp", "r"),
		[](FILE* ptr)
		{
			cout << (void*)ptr << endl;
			fclose(ptr);
			cout << "fclose" << endl;
		});

	return 0;
}