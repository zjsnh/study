#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>
#include<math.h>

//int main()
//{
//	
//	string _str;
//	getline(cin, _str); 
//
//	string comp;
//	getline(cin, comp);
//	unordered_map<char, int> str;
//
//	for (auto& e : comp)
//	{
//		str[e]++;
//	}
//
//	string Str;
//	for (int i = 0; i < _str.size(); i++)
//	{
//		if (str[_str[i]] != 1)
//		{
//			Str += _str[i];
//		}
//	}
//
//	cout << Str << endl;
//
//	return 0;
//}
//
//struct ListNode
//{
//	ListNode* next;
//	int val;
//};
//
//
//
//ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//
//	ListNode* temp1 = pHead1;
//	ListNode* temp2 = pHead2;
//
//	int cur1 = 0;
//	int cur2 = 0;
//	while (temp1)
//	{
//		temp1 = temp1->next;
//		cur1++;
//	}
//
//	while (temp2)
//	{
//		temp2 = temp2->next;
//		cur2++;
//	}
//
//	ListNode* Long = pHead1;
//	ListNode* Short = pHead2;
//
//	if (cur2 > cur1)
//	{
//		Long = pHead2;
//		Short = pHead1;
//	}
//	int distance = abs(cur1 - cur2);
//
//	while (distance)
//	{
//		Long = Long->next;
//		--distance;
//	}
//
//	while (Long && Short && Long != Short)
//	{
//		Long = Long->next;
//		Short = Short->next;
//	}
//
//	if (Long == nullptr)
//	{
//		return nullptr;
//	}
//
//	return Long;
//}

//hash<char,>

//8
//sshhyyau
//
//int main()
//{
//	string shiny("sshhyyau");
//	long long count = 0;
//	for (int i = 0; i < shiny.size(); i++)
//	{
//		if (shiny[i] == 's')
//		{
//			int left = i + 1;
//			int curh = 0;
//			while (left < shiny.size() - 1)
//			{
//				
//				if (shiny[left] == 'h')
//				{
//					++curh;
//				}
//
//				if (shiny[left] == 'y')
//				{
//					count += curh;
//				}
//
//				++left;
//			}
//
//		}
//	}
//
//	cout << count << endl;
//
//	return 0;
//}

int main()
{
    long long n;
    cin >> n;
    string str;
    cin >> str;

    vector<long long> s(str.size() + 1);
    auto sh = s;
    auto shy = s;

    for (int i = 1; i < str.size(); i++)
    {
        s[i] = str[i - 1] == 's' ? s[i - 1] + 1 : s[i - 1];
        sh[i] = str[i - 1] == 'h' ? s[i] + sh[i - 1] : sh[i - 1];
        shy[i] = str[i - 1] == 'y' ? sh[i] + shy[i - 1] : shy[i - 1];
    }

    cout << shy[str.size()] << endl;
    return 0;
}