#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

//#include"string.h"

void text()
{

	//str::string s("hello world");
	////s.insert(0, 'v');
	////s.insert(5, "vvvvvvnnnnnnnnnnnnn");
	///*cout << s;

	//s.erase(5, 3);
	//cout << s;
	//s.erase(2, 100);*/

	//s.append("wwwwww");

	//cout << s;

	//cin >> s;
	//cout << s;

	string s1("xxxxxxxxxxxxxxxxxxx");

	string s2(s1);

	cout << (void*)s1.c_str() << endl;//cout 默认将char* 识别为字符串
	cout << (void*)s2.c_str() << endl;//不会打印出地址，强制转化为void* 打印出地址

	s1[0]++;

	cout << (void*)s1.c_str() << endl;
	cout << (void*)s2.c_str() << endl;
}

int main()
{

	text();
	return 0;
}