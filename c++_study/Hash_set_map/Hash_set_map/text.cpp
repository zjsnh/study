#include<iostream>
#include<string>
using namespace std;
#include"hash.h"
#include"unordered_map.h"
#include"unordered_set.h"
#include"bitset.h"
#include"BloomFilter.h"


//int main()
//{
//	Hash<string, string> h;
//	h.Insert(make_pair("sort", "sort"));
//	h.Insert(make_pair("quit", "sort"));
//	h.Insert(make_pair("right", "sort"));
//	h.Insert(make_pair("hash", "sort")); 
//	h.Insert(make_pair("cnm", "sort"));
//	h.Insert(make_pair("yes", "sort"));
//	h.Insert(make_pair("average", "sort"));
//	h.Insert(make_pair("is", "sort"));
//	h.Insert(make_pair("nihao", "sort"));
//	h.Insert(make_pair("delete", "sort"));
//	//h.Insert(make_pair("left", "sort"));
//	//h.Insert(make_pair("cnm", "sort"));
//
//	cout << h.Find("sort") << endl;
//	h.Earse("sort");
//	cout << h.Find("sort");
//
//	return 0;
//}
//
//int main()
//{
//	// 17:05
//	unordered_set<int> us;
//	us.insert(5);
//	us.insert(15);
//	us.insert(52);
//	us.insert(3);
//
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		//*it += 5;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//int main()
//{
//	unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", ""));
//	dict.insert(make_pair("string", "ַ"));
//	dict.insert(make_pair("insert", ""));
//
//	for (auto& kv : dict)
//	{
//		/*kv.first += 'x';*/
//		kv.second += 'x';
//
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//
//	string arr[] = { "㽶", "","ƻ", "", "ƻ", "", "ƻ", "ƻ", "", "ƻ", "㽶", "ƻ", "㽶" };
//	unordered_map<string, int> count_map;
//	for (auto& e : arr)
//	{
//		count_map[e]++;
//	}
//
//	for (auto& kv : count_map)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//	return 0;
//}

int main()
{
	/*bitset<100> b;
	b.set(41);
	b.set(42);
	b.set(49);


	cout << b.which(40) << endl;
	cout << b.which(41) << endl;
	cout << b.which(42) << endl;
	cout << b.which(49) << endl;*/

	int a[] = { 1,2,44,44,55,66,77,99,33,55,99 };
	twobitset<100> t;

	for (auto& e : a)
	{
		t.set(e);
	}

	t.Print();
	

	return 0;
}