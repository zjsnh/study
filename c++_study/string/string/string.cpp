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

//int main()
//{
//	string s1("!:@#$ $%%^");
//	string::iterator it = s1.begin();//begin ��һ��λ�õ�ָ��
//	while (it != s1.end())//end ���һ��λ�õ���һ��λ��
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	
//
//	cout << endl;
//
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//
//	cout << endl;
//
//
//	return 0;
//}



//int main()
//{
//	string s ("ning wen bo!");
//
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if (*it == ' ')
//		{
//			//s.replace(std::distance(s.begin(), it), 1, "%%d");//��distancs����������ľ���
//			s.replace(it, it + 1, 1, '*');
//		}
//		else
//		{
//			++it;
//		}
//	}
//
//	cout << s << endl;
//
//	return 0;
//
//}


//int main() {
//    std::string s("hello world");
//    std::string replace_string("replace_string");
//
//    // ʹ�õ����������ַ���
//    for (auto it = s.begin(); it != s.end(); ) {
//        if (*it == ' ') {
//            // ����Ҫ�滻�Ŀո������ַ�����
//            size_t replace_length = replace_string.length();
//            size_t erase_length = 1; // �ո���
//
//            // ����ո���滹�пո����������Ҫ�滻�ĳ���
//            while (std::next(it) != s.end() && *std::next(it) == ' ') {
//                ++erase_length;
//            }
//
//            // ִ���滻����
//            it = s.replace(it, it + erase_length, replace_string.c_str(), replace_length).begin() + (it - s.begin());
//        }
//        else {
//            ++it;
//        }
//    }
//
//    std::cout << s << std::endl;
//
//    return 0;
//}


//int main()
//{
//	string s ("ning wen bo!");
//
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if (*it == ' ')
//		{
//			//s.replace(std::distance(s.begin(), it), 1, "%%d");//��distancs����������ľ���
//			//it = s.replace(it, it + 1, "abc", 3).begin() + (it - s.begin());
//			//it = s.replace(it, it + 1, 1, '*').begin() + (it - s.begin());//����һ���ַ�
//
//			//s.replace(it, it + 1, 1, '*');
//
//			//it = s.replace(it, it + 1, 1, '*').begin();
//			
//			it=s.replace(it, it + 1, "abc", 3).begin();
//
//			//replac�����޸ĺ���ַ������׵�ַ
//		}
//		else
//		{
//			++it;
//		}
//	}
//
//	cout << s << endl;
//
//	return 0;
//
//}

int main()
{
	string s ("ning wen bo!");

	//string::iterator it = s.begin();
	//while (it != s.end())
	//{
	//	if (*it == ' ')
	//	{
	//		//s.replace(std::distance(s.begin(), it), 1, "%%d");//��distancs����������ľ���
	//		s.replace(it, it + 1, 1, '*');
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}

	

	size_t pos = s.find(' ');
	while (pos != string::npos)
	{
		s.replace(pos, 1, "%20");
		pos = s.find(' ',pos+3);//pos��ʼλ��
	}

	cout << s << endl;

	return 0;

}
