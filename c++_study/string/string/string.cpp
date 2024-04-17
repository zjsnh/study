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
//	//cout<<s2.max_size();//用不着，，，，
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
//	s2.push_back('!');//char  字符
//
//	s2.append("zws");//cosnt char  常量字符串
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
//	cout << "sz.capacity()=" << sz << endl;//没有扩容的大小
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
//	s2.resize(100,'x');//初始化为x
//	//s2.resize(100);//使用缺省值初始化 0
//	cout << s2.capacity() << endl;
//	cout << s2.size() << endl;
//
//	return 0;
//
//}

//int main()
//{
//	string s1("!:@#$ $%%^");
//	string::iterator it = s1.begin();//begin 第一个位置的指针
//	while (it != s1.end())//end 最后一个位置的下一个位置
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
//			//s.replace(std::distance(s.begin(), it), 1, "%%d");//用distancs计算迭代器的距离
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
//    // 使用迭代器遍历字符串
//    for (auto it = s.begin(); it != s.end(); ) {
//        if (*it == ' ') {
//            // 计算要替换的空格及其后的字符数量
//            size_t replace_length = replace_string.length();
//            size_t erase_length = 1; // 空格本身
//
//            // 如果空格后面还有空格，则继续计算要替换的长度
//            while (std::next(it) != s.end() && *std::next(it) == ' ') {
//                ++erase_length;
//            }
//
//            // 执行替换操作
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
//			//s.replace(std::distance(s.begin(), it), 1, "%%d");//用distancs计算迭代器的距离
//			//it = s.replace(it, it + 1, "abc", 3).begin() + (it - s.begin());
//			//it = s.replace(it, it + 1, 1, '*').begin() + (it - s.begin());//更换一个字符
//
//			//s.replace(it, it + 1, 1, '*');
//
//			//it = s.replace(it, it + 1, 1, '*').begin();
//			
//			it=s.replace(it, it + 1, "abc", 3).begin();
//
//			//replac返回修改后的字符串的首地址
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
	//		//s.replace(std::distance(s.begin(), it), 1, "%%d");//用distancs计算迭代器的距离
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
		pos = s.find(' ',pos+3);//pos起始位置
	}

	cout << s << endl;

	return 0;

}
