//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//bool isPrime(int n) {
//	if (n <= 1) return false; // 0和1不是素数
//	for (int i = 2; i * i <= n; ++i) {
//		if (n % i == 0) return false; // 找到因子则不是素数
//	}
//	return true; // 没有因子则是素数
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//
//	map<char, int> u;
//	for (const auto& e : s)
//	{
//		u[e]++;
//	}
//
//	int maxnum = 0;
//	int minnum = 0xfffffff;
//
//	for (const auto& e : u)
//	{
//		if (e.second > maxnum)
//			maxnum = e.second;
//		else if (e.second < minnum)
//			minnum = e.second;
//	}
//
//	//Lucky Word
//	//2	
//
//	/*No Answer
//		0*/
//	if (isPrime(maxnum - minnum))
//	{
//		cout << "Lucky Word" << endl;
//		cout << maxnum - minnum << endl;
//	}
//	else
//	{
//		cout << "No Answer" << endl;
//		cout <<  0 << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<map>
//#include<string>
//#include<vector>
//using namespace std;
//#include<algorithm>

//struct _less
//{
//    bool operator()(const vector<int> v1, const vector<int> v2)
//    {
//        return v1[0] > v2[0];
//    }
//};
//
//
//bool hostschedule(vector<vector<int> >& schedule) {
//    // write code here
//
//
//    sort(schedule.begin(), schedule.end(), _less());
//
//    for (int i = 1; i < schedule.size(); i++)
//    {
//        if (schedule[i][0] < schedule[i - 1][1])
//        {
//            return false;
//        }
//    }
//
//    return true;
//
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int num = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num += arr[i];
    }

    if (num % 2 != 0) {
        cout << "false" << endl;
        return 0; 
    }

    int target = num / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true; 

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j]; 
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]]; 
            }
        }
    }

    if (dp[n][target]) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
