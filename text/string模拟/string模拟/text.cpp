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

	cout << (void*)s1.c_str() << endl;//cout Ĭ�Ͻ�char* ʶ��Ϊ�ַ���
	cout << (void*)s2.c_str() << endl;//�����ӡ����ַ��ǿ��ת��Ϊvoid* ��ӡ����ַ

	s1[0]++;

	cout << (void*)s1.c_str() << endl;
	cout << (void*)s2.c_str() << endl;
}

int main()
{

	text();
	return 0;
}