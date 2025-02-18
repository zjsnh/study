//#include <iostream>
//
//
//
//
//
//class point
//{
//private:
//	int x;
//
//public:
//	virtual void print() = 0;
//};
//
//
//class Ipoint : public point
//{
//private:
//	int y;
//
//
//public:
//	virtual void print() override
//	{
//		std::cout << y << std::endl;
//		std::cout << "Ipoint" << std::endl;
//	}
//};
//
//
//int main()
//{
//	point* p = new Ipoint();
//	p->print();
//	return 0;
//}


#include <iostream>

void print(unsigned int n)
{
	printf("%p\n", &n);
	if (n > 9)
		print(n / 10);
	std::cout << n % 10 << " ";
}

int main()
{
	unsigned int num = 0; 
	scanf_s("%u", &num); 
	print(num); 
	return 0; 
}