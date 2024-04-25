#include<iostream>
#include<vector>

using namespace std;

#include"vector.h"

int main()
{
	vec::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vec::vector<int>::iterator it = find(v.begin(), v.end(), 5);

	auto it2 = v.begin();
	v.insert(it, 100);
	v.insert(it2, 100);

	it = find(v.begin(), v.end(), 4);
	//vec::vector<int>::iterator it = find(v.begin(), v.end(), 4);

	v.erase(it);

	for (auto e : v)
	{
		cout << e << " ";

	}

	cout << endl;
	return 0;
}