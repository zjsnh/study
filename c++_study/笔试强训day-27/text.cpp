//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//void combin(ll n, ll m, ll& num)
//{
//	if ((m-1) == 0)
//		return;
//
//	num *= (m - 1) * (n - 1);
//	combin(n - 1, m - 1, num);
//}
//
//int main()
//{
//	ll n, m;
//	cin >> n >> m;
//
//	if (m > n)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	//从n个中取m个  
//	ll num = 1;
//	combin(n, m, num);
//
//	num *= n;
//	cout << num % 109 << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//ll perm(ll n, ll m) {
//    if (m > n) return 0; 
//    ll num = 1;
//    for (ll i = 0; i < m; i++) {
//        num *= (n - i);
//        num%=109
//    }
//    return num;
//}
//
//int main() {
//    ll n, m;
//    cin >> n >> m;
//
//    cout << perm(n, m) << endl;
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _less {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
};

void compere_insert(vector<vector<int>>& compere, const vector<int>& time) {
    bool flag = true;
    for (int i = 0; i < compere.size(); i++) {

        if (compere[i].back() >= time[0]) {
            compere[i].push_back(time[1]);
            flag = false;
            break;
        }
    }


    if (flag) {
        compere.push_back({ time[0], time[1] });
    }
}

int minmumNumberOfHost(int n, vector<vector<int>>& startEnd) {
    sort(startEnd.begin(), startEnd.end(), _less());

    vector<vector<int>> compere;

    if (!startEnd.empty()) {
        compere.push_back(startEnd[0]);
    }

    for (int i = 1; i < startEnd.size(); i++) {
        compere_insert(compere, startEnd[i]);
    }

    return compere.size();
}

int main()
{
    return 0;
}
