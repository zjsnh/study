#include<iostream>
#include<string>

using namespace std;


//
//int main()
//{
//	string s1;
//
//	string s2("hello world");
//	string s3 = "hello world";
//
//	//cout<<s2.max_size();//�ò��ţ�������
//
//
//	///*for (size_t t = 0; t < s2.size(); ++t)
//	//{
//	//	cout << s2[t];
//	//}*/
//	//cout << s2;
//
//	//cout << endl;
//
//	//for (size_t t = 0; t < s2.size(); ++t)
//	//{
//	//	s2[t]++;
//	//}
//
//	//cout << s2;
//
//	s2.push_back(' ');
//	s2.push_back('!');//char  �ַ�
//
//	s2.append("zws");//cosnt char  �����ַ���
//
//	s2 += ' ';
//	s2 += "  ";
//	s2 += "hello";
//	s2 += "  !";
//
//	cout << s2;
//
//	return 0;
//}

//
//int main()
//{
//	string s;
//
//	s.reserve(100);
//
//	size_t sz = s.capacity();
//	cout << "sz.capacity()=" << sz << endl;//û�����ݵĴ�С
//
//	for (size_t t = 0; t < 100; t++)
//	{
//		s.push_back('c');
//
//		if (sz != s.capacity())
//		{
//			cout << "sz.capacity()=" << s.capacity()<< endl;
//
//			sz = s.capacity();
//		}
//	}
//
//	return 0;
//
//}


//int main()
//{
//	string s1 = "hello word";
//
//	s1.reserve(100);
//	cout << s1.capacity()<<endl;
//	cout << s1.size() << endl;
//
//	string s2 = "hello word";
//
//	s2.resize(100,'x');//��ʼ��Ϊx
//	//s2.resize(100);//ʹ��ȱʡֵ��ʼ�� 0
//	cout << s2.capacity() << endl;
//	cout << s2.size() << endl;
//
//	return 0;
//
//}

int main()
{
	string s1("!:@#$ $%%^");
	string::iterator it = s1.begin();//begin ��һ��λ�õ�ָ��
	while (it != s1.end())//end ���һ��λ�õ���һ��λ��
	{
		cout << *it << " ";
		++it;
	}

	

	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}

	cout << endl;


	return 0;
}