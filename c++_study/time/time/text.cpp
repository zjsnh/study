#include"time.h"

int main()
{
	/*time_t local;
	struct */


	Date d(2023, 3, 4);
	Date d2 = d;
	cout << d << d2;
	d += 100;
	cout << d << d2;
	
	/*localtime();*/

	return 0;
}