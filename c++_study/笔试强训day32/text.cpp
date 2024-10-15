//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<cstdbool>
//
//struct _less
//{
//	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
//	{
//		return p1.second < p2.second;
//	}
//};
//
//int main()
//{
//	int size_;
//	cin >> size_;
//
//	vector<pair<int, int>> v(size_);
//
//	for (int i = 0; i < size_; i++)
//	{
//		cin >> v[i].first >> v[i].second;
//	}
//
//	
//
//	sort(v.begin(), v.end(), _less());
//	int num = 1;
//	int _begin = v[0].second;
//	for (int i = 1; i < size_; i++)
//	{
//		if (v[i].first >= _begin)
//		{
//			num++;
//			_begin = v[i].second;
//		}
//
//	}
//
//	cout << num << endl;
//
//	return 0;
//}



#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long n;
    cin >> n;

    long tmp = n / 10;
    while (tmp) {
        n = n * 10 + tmp % 10;
        tmp /= 10;
    }

    for (long i = 2; i <= (long)sqrt(n); ++i) {
        if (n % i == 0) {
            cout << "noprime";
            return 0;
        }
    }
    cout << "prime";
    return 0;
}