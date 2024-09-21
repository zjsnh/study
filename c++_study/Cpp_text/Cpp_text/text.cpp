//#include <iostream>
//using namespace std;
//int main() {
//    cout << sizeof(long) << endl;
//    cout << sizeof(int) << endl;
//    /*int zero = 0;
//    short one = 1;*/
//    //int three = zero - one;
//
//    unsigned char zero = 0, one = 1;
//    //突然想到decltype可以获取表达式类型  
//    decltype(zero - one) ret;
//    cout << typeid(ret).name() << endl;
//    if ((zero-one) < zero)
//        std::cout << "less";
//    else
//        std::cout << "more";
//
//}


//#include <iostream>
//
//struct A {
//	A(int i) : m_i(i) {}
//
//	operator bool() const 
//	{ 
//		return m_i > 0; 
//	}
//
//	int m_i;
//};
//
//int main() {
//	A a1(1), a2(2);
//	std::cout << a1 - a2;
//	std::cout << (a1 == a2);
//
//
//	return 0;
//}
//
//#include <iostream>
//
//struct X {
//    X() { std::cout << "1"; }
//
//    X(const X& )  
//    { 
//        std::cout << "3"; 
//    }
//
//    ~X() { std::cout << "2"; }
//
//    void f() { std::cout << "4"; }
//
//} object;
//
//int main() {
//    X(object);
//
//    object.f();
//
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//
//int main() {
//    
//    unsigned char zero = 0, one = 1;
//    //decltype可以获取表达式类型  
//    decltype(zero - one) ret;
//
//    cout << typeid(zero - one).name() << endl;
//    cout << typeid(ret).name() << endl;
//
//    //typeid(ret).before();
//
//}



//#include <iostream>
//using namespace std;
//#include <string>
//int main()
//{
//	string s;
//	cin >> s;
//	int length = 1189, with = 841;
//	int index = s[1] - '0';
//	for (int i = 0; i < index; i++)
//	{
//		int temp;
//		if (with > length) {
//			swap(with, length);
//		}
//		length = length / 2;
//	}
//	if(with>length)
//		swap(with, length);
//
//	cout << length << endl;
//	cout << with;
//	return 0;
//}


#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#include<vector>
#include<set>


//int main()
//{
//	string s;
//	cin >> s;
//	sort(s.begin(), s.end());
//	cout << s << endl;
//
//	return 0;
//}

//int removeDuplicates(vector<int>& nums) {
//
//	set<int> s(nums.begin(), nums.end());
//	return s.size();
//
//
//}
//
//int main()
//{
//	vector<int> nums;
//	removeDuplicates(nums);
//	return 0;
//}


//int main()
//{
//	char buffer[1024];
//
//	buffer[12] = '\0';
//	cout << sizeof(buffer) << endl;
//	cout << strlen(buffer) << endl;
//
//	return 0;
//}
struct A
{
	int _a;
	double _b;
};

int main()
{
	int n = 5;
	vector<int> V(n);
	/*for (int i = 0; i < 10; i++)
	{
		cin >> V[i] ;
	}*/
	return 0;
}
