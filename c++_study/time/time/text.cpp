#include"time.h"

//int main()
//{
//	/*time_t local;
//	struct */
//
//
//	Date d(2023, 3, 4);
//	Date d2 = d;
//	cout << d << d2;
//	d += 100;
//	cout << d << d2;
//	
//	/*localtime();*/
//
//	return 0;
//}

int main()
{
	Date d1(1970, 1, 1);
	

	Date d2(1999, 1, 1);

	d2 > d1;

	cout << d1;
	cin >> d1;

	d1 << cout;
	d1 >> cin;
	d1.operator<<(cout);
	d1.operator>>(cin);

	

	return 0;
}

