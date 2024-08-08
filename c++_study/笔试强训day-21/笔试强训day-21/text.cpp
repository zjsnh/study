#include<iostream>
using namespace std;
#include<vector>

//using ll = long long;
//int main()
//{
//	int size = 0;
//	cin >> size;
//
//	int queuesize = (size + 1) / 2;
//
//	for (int i = 1; i <= queuesize; i++) {
//		cout << i << " ";
//
//		if (queuesize + i <= size)    
//			cout << queuesize + i << " ";
//	}
//
//	cout << endl;
//	
//
//
//	return 0;
//
//}


//#include<set>
//
//int main()
//{
//	int size1;
//	int size2;
//	cin >> size1 >> size2;
//
//	set<int> S;
//	for (int i = 0; i < size1+size2; i++) {
//		int b;
//		cin >> b;
//		S.insert(b);
//	}
//
//	set<int>::iterator it = S.begin();
//	while (it != S.end())
//	{
//		cout << *it;
//		if (++it != S.end())
//		{
//			cout << " ";
//		}
//	}
//
//	cout << endl;
//	return 0;
//}


#include<string>

//int length(string str)
//{
//	int left = 0;
//	int right = str.size() - 1;
//	while (right != left)
//	{
//		if (str[left] != str[right])
//		{
//			int _right = right;
//			int _left = _left;
//
//			//×óÏòÓÒÒÆ¶¯
//			
//		}
//	}
//}

int l_r(string str, int left, int right)
{
	int lengh = 0;

	if (left > right)
	{
		return 0;
	}

	if (left == right)
	{
		return 1;
	}

	if (str[left] == str[right])
	{
		return 2 + l_r(str, left + 1, right - 1);
	}

	return max(l_r(str, left + 1, right), l_r(str, left, right - 1));
}

int main()
{
	string str;
	cin >> str;
	int left = 0;

	int distance = 0;
	/*for (; left < str.size(); left++)
	{
		distance = max(distance, l_r(str, left, str.size() - 1));
	}*/
	cout << l_r(str, left, str.size() - 1) << endl;

	return 0;
}