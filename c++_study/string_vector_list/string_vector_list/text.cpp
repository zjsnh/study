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
	//memcpy��Ȼ��vector�ڵĿռ�ֵ�����˹�ȥ�����ǣ�string��ָ��Ŀռ䲢û�б������
	//�����ͷ�ԭ���ռ��ʱ�������Ҳ���


	for (auto e : w)
	{
		cout << e << " ";
	}
	cout << endl;



	return 0;
}