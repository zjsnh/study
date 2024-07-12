#include<iostream>
using namespace std;

#include"RBtree.h"
#include"map.h"
#include"set.h"
#include<vector>


//int main()
//{
//	mp::map<string, string> m;
//	m.insert(make_pair("sort", "ÅÅÐò"));
//	m.insert(make_pair("left", "ÅÅÐò"));
//	m.insert(make_pair("right", "ÅÅÐò"));
//	m.insert(make_pair("nihao", "ÅÅÐò"));
//
//	/*for (auto& e : m)
//	{
//		cout << m[string("sort")];
//		++e;
//	}*/
//	mp::map<string, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		it->second = "nihao1"; 
//		cout << it->first << ": " << it->second << endl;
//		++it;
//	}
//
//	mp::map<string, string>::const_iterator it2 = m.begin();
//	while (it2 != m.end())
//	{
//		/*it2->second = "nihao1";*/
//		cout << it2->first << ": " << it2->second << endl;
//		++it;
//	}
//
//
//	return 0;
//}


//int main()
//{
//	st::set<int> m;
//	m.insert(1);
//	m.insert(2);
//	m.insert(3);
//	/*for (auto& e : m)
//	{
//		cout << m[string("sort")];
//		++e;
//	}*/
//	st::set<int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << *it;
//		++it;
//	}
//}

int removeDuplicates(vector<int>& nums) {

    if (nums.size() == 0)
        return 0;
    int index = 1;
    int sum = 0;
    for (int i = 1; i < nums.size(); i++)
    {

        if (sum == 1)
        {
            index++;
        }

        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i];
            sum = 0;
        }
        else
        {
            sum++;
        }

    }

    if (sum == 1)
    {
        int x = nums[index-1];
        nums[index++] = x;
    }

    return index;

}

int main()
{

    vector<int>v{ 0,0,1,1,1,1,2,3,3 };
    cout << removeDuplicates(v) << endl;
    for (auto e : v)
    {
        cout << e;
    }

    cout << endl;


    return 0;
}