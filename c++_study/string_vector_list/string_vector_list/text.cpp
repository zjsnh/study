#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"string.h"
#include"vector.h"


int main()
{
	vec::vector<string> w;
	w.push_back("11111111111111111111111");
	w.push_back("11111111111111111111111");
	w.push_back("11111111111111111111111");
	w.push_back("11111111111111111111111");
	w.push_back("11111111111111111111111");
	//memcpy虽然将vector内的空间值拷贝了过去，但是，string内指向的空间并没有被深拷贝，
	//导致释放原来空间的时候，数据找不到


	for (auto e : w)
	{
		cout << e << " ";
	}
	cout << endl;



	return 0;
}