#include<iostream>
using namespace std;

#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>


////ABCBA
////AABB
//int main()
//{
//	string str("ABCBA");
//	string _str("AABB");
//
//	cin >> str >> _str;
//
//	unordered_map<char, int> M;
//	for (auto& e : str)
//	{
//		M[e]++;
//	}
//
//	unordered_map<char, int> m;
//	for (auto& e : _str)
//	{
//		m[e]++;
//	}
//
//	for (auto& e : m)
//	{
//		if (M[e.first] < e.second)
//		{
//			cout << "no" << endl;
//			return 0;
//		}
//	}
//
//	cout << "yes" << endl;
//
//	return 0;
//}

//9
//1 2 1 3 2 2 2 2 3

int main()
{
	/*int a;
	cin >> a;*/
	unordered_map<int, int> M;
	//vector<int> V = { 1, 2, 1, 3, 2, 2, 2, 2, 3 };
	/*vector<int> V = { 8, 4, 6, 10, 4, 3, 2, 1 };*/
	vector<int> V = { 2, 9, 2, 4, 2, 1 };

	/*int b;
	while (cin >> b)
	{
		M[b]++;
	}*/

	for (auto& e : V)
	{
		M[e]++;
	}
	

	unordered_set<int> S(V.begin(), V.end());

	V.clear();
	for (auto& e : S)
	{
		V.push_back(e);
	}

	

	sort(V.begin(),V.end());

	vector<int> dp;
	dp.resize(V.back());

	dp[0] = M[0 + 1] * (0 + 1);
	dp[1] = M[1 + 1] * (1 + 1);
	for (int i = 2; i < V.back(); i++)
	{
		dp[i] = dp[i - 2] + M[i + 1] * (i + 1);
	}

	cout << max(dp[V.back() - 1], dp[V.back() - 2]) << endl;
	return 0;
}

//
//#include <iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//int main() {
//    int a = 0;
//    cin >> a;
//    int b;
//    vector<int> V;
//    while (cin >> b)
//    {
//        V.push_back(b);
//    }
//
//    sort(V.begin(), V.end());
//
//    int i = V.size() - 1;
//    long long num = 0;
//    while (a)
//    {
//        num += V[i - 1];
//        i -= 2;
//        --a;
//    }
//
//    cout << num << endl;
//    return 0;
//
//}


