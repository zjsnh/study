#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

//int main()
//{
//	int a = 5;
//
//	long long minsquare = 1E13;
//	long long num = 1;
//	while (abs(a - num * num) < minsquare)
//	{
//		minsquare = min(minsquare, abs(a - num * num));
//		num++;
//
//	}
//
//	cout << (num - 1) * (num - 1) << endl;
//
//	return 0;
//}

//struct com
//{
//	bool operator()(int& p1,int& p2, unordered_map<int, int> M)
//	{
//		return M[p1] > M[p2];
//	}
//};

#include <cmath> // 包含 ceil 函数

// 比较器，按频率从大到小排序
struct com
{
	com(unordered_map<int, int>& M) : M(M) {} // 使用构造函数捕获引用
	bool operator()(int p1, int p2)
	{
		return M[p1] < M[p2];
	}
	unordered_map<int, int>& M;
};

int find_max(unordered_map<int, int>& M)
{
	int Max = 0;
	for (auto& e : M)
	{
		Max = max(Max, e.second);
	}

	return Max;
}

int main()
{
	/*int group = 3;
	vector<int> V{ 2,2,3,3,3 };*/

	int a;
	cin >> a;

	int group;
	cin >> group;
	vector<int> V;
	int b;
	while (cin >> b)
	{
		V.push_back(b);
	}

	unordered_map<int, int> M;

	for (auto& e : V)
	{
		M[e]++;
	}

	int size = M.size();

	unordered_set<int> S(V.begin(), V.end());
	V.clear();
	for (auto& e : S)
	{
		V.push_back(e);
	}

	//cout << (6 / 4) << endl;

	sort(V.begin(), V.end(),com(M));
	int _group = group - size;


	double Max;

	while (V.size() != group)
	{
		int flag = 0;
		for (int i = 2; i <= _group + 1; i++)
		{
			if (M[V.back()] / i < M[V[V.size() - _group + (i - 3)]])
			{
				Max = M[V[V.size() - _group - (i - 1)]];
				M[V.back()] = ceil(M[V.back()] / static_cast<double>(i)); // 使用 ceil 函数
				flag = 1;

				V.push_back(V.back());
				break;
			}
		}

		if (flag == 0)
		{

			double value = (double) M[V.back()] / (_group + 1);
			M[V.back()] = ceil(value); // 使用 ceil 确保至少为1.0

			cout << M[V.back()] << endl;
			return 0;
		}

		sort(V.begin(), V.end(), com(M));
	}

	cout << Max << endl;
	return 0;
}