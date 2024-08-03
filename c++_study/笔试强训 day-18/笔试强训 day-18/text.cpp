#include<iostream>
using namespace std;
#include<string>
#include<vector>

//string compressString(string param) {
//    // write code here
//
//	int num = 0;
//	string _param;
//	for (int i = 0; i < param.size(); i++)
//	{
//		if (num == 0)
//		{
//			_param += param[i];
//			num = 1;
//			continue;
//		}
//
//
//		if (param[i] == _param.back())
//		{
//			num++;
//		}
//		else
//		{
//			if (num > 1)
//			{
//				_param += to_string(num);
//				
//			}
//			_param += param[i];
//			num = 1;
//		}
//	}
//
//	if (num > 1)
//	{
//		_param += to_string(num);
//	}
//
//	return _param;
//
//}
//
//
//
//int main()
//{
//	string str("shopeew");
//	cout << compressString(str) << endl;
//
//	return 0;
//}
//#include<algorithm>
//
//struct sweet
//{
//	bool operator()(pair<int, int> p1, pair<int, int> p2)
//	{
//		return p1.second < p2.second;
//	}
//};
//
//void change(vector<pair<int, int>>& V, pair<int, int> num, int flag)
//{
//
//	if (flag == 0)
//		return;
//	
//	pair<int, int> b;
//	for (int i = 0; i < V.size() - 1; i++)
//	{
//		if (num.second > V[i].second)
//		{
//			V[V.size() - 1].first = V[V.size() - 1].first + num.first - V[i].first;
//			V[V.size() - 1].second = V[V.size() - 1].second + num.second - V[i].second;
//
//
//			b = V[i];
//			swap(num, V[i]);
//			break;
//		}
//
//		if (num.second == V[i].second && num.first < V[i].first)
//		{
//			V[V.size() - 1].first = V[V.size() - 1].first + num.first - V[i].first;
//
//
//			b = V[i];
//			swap(num, V[i]);
//			break;
//		}
//
//		flag = 0;
//
//	}
//
//	sort(V.begin(), V.end(), sweet());
//	change(V, b, flag);
//
//	return;
//}
//
//int main()
//{
//	int size = 3;
//	int n = 2;
//
//	vector<pair<int, int>> _V = { {1,2},{3,2},{4,5} };
//	vector<pair<int, int>> V;
//
//	int swt = 0;
//	int sour = 0;
//	for (int i = 0; i < n; i++)
//	{
//		V.push_back(_V[i]);
//		swt += _V[i].second;
//		sour += _V[i].first;
//	}
//
//	V.push_back(make_pair(sour, swt));
//
//	sort(V.begin(), V.end(), sweet());
//
//	for (int i = n; i < _V.size(); i++)
//	{
//		change(V, _V[i], 1);
//	}
//
//	cout << V[V.size() - 1].first << " " << V[V.size() - 1].second << endl;
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 自定义比较函数，根据 pair 的第二个元素排序
struct CompareBySecond {
	bool operator()(const pair<long long, long long>& p1, const pair<long long, long long>& p2) const {
		return p1.second < p2.second;
	}
};

void process(set<pair<long long, long long>, CompareBySecond>& S, const pair<long long, long long>& num) {
	// 尝试插入新元素
	auto it = S.lower_bound(num);

	if (it != S.end() && it->second == num.second && it->first < num.first) {
		// 如果找到相同 second 的元素且 first 更小，删除旧的并插入新的
		S.erase(it);
		S.insert(num);
	}
	else if (it == S.end() || it->second > num.second) {
		// 如果新元素的 second 小于现有元素的 second，直接插入
		S.insert(num);
	}
}

int main() {
	long long size, n;
	cin >> size >> n;

	vector<pair<long long, long long>> _V(size);
	for (long long i = 0; i < size; i++) {
		long long first;
		cin >> first;
		_V[i].first = first;
	}

	for (long long i = 0; i < size; i++) {
		long long second;
		cin >> second;
		_V[i].second = second;
	}

	set<pair<long long, long long>, CompareBySecond> S;

	long long swt = 0;
	long long sour = 0;
	for (long long i = 0; i < n; i++) {
		S.insert(_V[i]);
		swt += _V[i].second;
		sour += _V[i].first;
	}

	S.insert(make_pair(sour, swt));

	for (long long i = n; i < _V.size(); i++) {
		process(S, _V[i]);
	}

	auto last = S.rbegin();  // 获取 set 中的最大元素
	cout << last->first << " " << last->second << endl;

	return 0;
}
