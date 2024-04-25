#include<iostream>
#include<vector>

using namespace std;

#include"vector.h"

void text1()
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

}

void text2()
{
	vector<int> w;

	w.push_back(1);
	w.push_back(2);
	w.push_back(3);

	/*for (auto e : w)
	{
		cout << e << " ";
	}
	cout << w.capacity();

	cout << endl;*/

	w.resize(10);

	/*for (auto e : w)
	{
		cout << e << " ";
	}*/

	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;


	w.resize(5);

	/*vector<int>::iterator it = w.begin();*/
	/*while (it != w.end())
	{
		cout << *it << " ";
		it++;
	}*/

	for (auto it : w)
	{
		cout << it << " ";
	}

	cout << endl;

	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;


}

void text3()
{
	vec::vector<int> w;

	w.push_back(1);
	w.push_back(2);
	w.push_back(3);

	w.resize(5, 0);

	for (auto e : w)
	{
		cout << e << " ";
	}
	/*cout << w.capacity();*/

	cout << endl;

	for (auto e : w)
	{
		cout << e << " ";
	}

	cout << endl;

	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;

	w.resize(10,0);

	vec::vector<int>::iterator it = w.begin();
	while (it != w.end())
	{
		cout << *it << " ";
		it++;
	}

	w.resize(5, 0);
	/*for (auto it : w)
	{
		cout << it << " ";
	}*/

	cout << endl;

	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;
}

void text4()
{
	vec::vector<int> w;

	w.push_back(1);
	w.push_back(2);
	w.push_back(3);


	w.resize(10, 0);

	vec::vector<int>::iterator it = w.begin();
	while (it != w.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;


	w.resize(5, 0);
	for (auto e : w)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << w.size() << " ";
	cout << w.capacity() << " ";
	cout << endl;
}

int main()
{
	text4();
	return 0;
}