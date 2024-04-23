#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

#include"string.h"

void text()
{

	str::string s("hello world");
	s.insert(0, 'v');
	//s.insert(5, "vvvvvvnnnnnnnnnnnnn");
	cout << s;

	s.erase(5, 3);
	cout << s;
	s.erase(2, 100);

	cout << s;

	/*cin >> s;
	cout << s;*/

}

int main()
{

	text();
	return 0;
}