//#include <iostream>
//using namespace std;
//#include <algorithm>
//#include <string>
//#include <unordered_set>
//
//int main()
//{
//	string str;
//
//	sort(str.begin(), str.end());//保证全排列的开始
//
//	unordered_set<string> set;
//	set.insert(str);
//	while (next_permutation(str.begin(), str.end()))
//	{
//		string _str = str;
//		set.insert(_str);
//	}
//
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//#include <string>
//#include <unordered_map>
//
//int main()
//{
//	string s;
//    cin >> s;
//    unordered_map<char, int> freq;
//    int left = 0, right = 0, max_len = 0;
//
//    while (right < s.length()) {
//        freq[s[right]]++;
//
//        while (freq.size() > 2) {
//            freq[s[left]]--;
//            if (freq[s[left]] == 0) {
//                freq.erase(s[left]);
//            }
//            left++;
//        }
//
//        max_len = max(max_len, right - left + 1);
//        right++;
//    }
//
//    cout << max_len << endl;
//
//	return 0;
//}


#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[21] = { 0 };

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] += i - 2;
    }

    cout << dp[n] << endl;

    return 0;
}