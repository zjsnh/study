#include<iostream>
#include<list>
#include<vector>

using namespace std;

#include"list.h"

namespace n
{
	int less()
	{
		return 2;
	}
}


int main()
{

	

	//lt::test_list4();
	/*lt::list<int> l;

	l.push_back(1);

	return 0;*/
	//lt::list<int> l;
	//

	//l.push_back(1);
	//l.push_back(1);
	//l.push_back(1);
	//l.push_back(1);
	//l.push_back(1);
	//l.push_back(6);

	///*list<int>::const_iterator it = s.begin();*/

	//lt::list<int>::const_iterator it = l.begin();
	//while (it != l.end())
	//{
	//	
	//	cout << *it << " ";
	//	cout << it.operator*() << " ";
	//	++it;
	//}

	//return 0;

	int a = n::less();


	cout << a;
	return 0;

}
