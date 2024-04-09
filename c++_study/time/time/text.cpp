#include"time.h"

int main()
{


	Date d(2023, 3, 4);
	Date d2 = d;
	cout << d << d2;
	d += 100;
	cout << d << d2;
	


	return 0;
}