#include<iostream>

//int&& add(int a, int b)
//{
//	int temp = (a + b);
//	return std::move(temp);
//}

//int add(int a, int b)
//{
//	int temp = (a + b);
//	return std::move(temp);
//}
//namespace str
//{
//	class string
//	{
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//
//		const static size_t npos = -1;
//	};
//
//}

void fun2(int&& x)
{
	std::cout << "fun2(int&& x)" << std::endl;
}

void fun2(const int& x)
{
	std::cout << "fun2(const int& x)" << std::endl;
}


void fun1(int&& x)
{
	fun2(std::forward<int>(x));
	return;
}


int main()
{
	fun1(3);

	return 0;
}