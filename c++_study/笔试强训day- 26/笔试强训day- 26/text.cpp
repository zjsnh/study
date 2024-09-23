//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//#include<algorithm>
//
//
//bool palindrome(string _s)
//{
//	string s = _s;
//	reverse(_s.begin(), _s.end());
//	
//
//	if (s == _s)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//int main()
//{
//	string s = "abcca";
//
//    /*vector<typename std::string::iterator> _va, _vb, _vc;
//	
//	int _max = 1;
//
//    cout << palindrome("abccba") << endl;*/
//    //最长的
//    //for(auto it = s.begin(); it != s.end(); ++it) {
//    //    if (*it == 'a') {
//    //        _va.push_back(it);
//    //        // 只有在 _va 的大小大于 1 时才进行回文判断
//    //        if (_va.size() > 1) {
//    //            for (size_t i = 0; i < _va.size() - 1; ++i) {
//    //                string substring(_va[i], it); // 获取 'a' 之间的子串
//    //                if (palindrome(substring)) {
//    //                    _max = max(_max, (static_cast<int>(it - _va[i])) + 1);
//    //                }
//    //            }
//    //        }
//    //    }
//    //    else if (*it == 'b') {
//    //        _vb.push_back(it);
//    //        if (_vb.size() > 1) {
//    //            for (size_t i = 0; i < _vb.size() - 1; ++i) {
//    //                string substring(_vb[i], it); // 获取 'b' 之间的子串
//    //                if (palindrome(substring)) {
//    //                    _max = max(_max, (static_cast<int>(it - _vb[i])) + 1);
//    //                }
//    //            }
//    //        }
//    //    }
//    //    else if (*it == 'c') {
//    //        _vc.push_back(it);
//    //        if (_vc.size() > 1) {
//    //            for (size_t i = 0; i < _vc.size() - 1; ++i) {
//    //                string substring(_vc[i], it); // 获取 'c' 之间的子串
//    //                if (palindrome(substring)) {
//    //                    _max = max(_max, (static_cast<int>(it - _vc[i])) + 1);
//    //                }
//    //            }
//    //        }
//    //    }
//    //}
//
//    for (int i = 0; i < s.size()-1; i++)
//    {
//        if (s[i] = s[i + 1])
//        {
//            cout << 2 << endl;
//            return 0;
//        }
//    }
//
//    for (int i = 0; i < s.size() - 2; i++)
//    {
//        if (s[i] = s[i + 2])
//        {
//            cout << 3 << endl;
//            return 0;
//        }
//        
//    }
//
//    //如果存在回文子串，就一定有上面两种情况    如果没有  -1
//
//    cout << -1 << endl;
//	return 0;
//}



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//int main()
//{
//    int size, K;
//    cin >> size >> K;
//    map<int, int> M;
//
//    // 输入数据到map中
//    for (int i = 0; i < size; i++)
//    {
//        int a;
//        cin >> a;
//        M[a]++;
//    }
//
//    int _begin = M.begin()->first;
//    int _end = M.rbegin()->first;
//
//    _begin = _begin + 2 * K;
//    int num = 0;
//
//    for (auto it = M.begin(); it != M.end() && it->first <= _begin; ++it)
//    {
//        num += it->second;
//    }
//
//    int _max = num;
//
//    while (_begin < _end)
//    {
//        if (M.count(_begin - 2 * K))
//        {
//            num -= M[_begin - 2 * K];
//        }
//
//        _begin++;
//        if (M.count(_begin))
//        {
//            num += M[_begin];
//        }
//
//
//        _max = max(_max, num);
//    }
//
//    cout << _max << endl;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll size;
    cin >> size;
    vector<ll> v(size);
    vector<ll> dp(size + 1, 0);  

    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= size; i++)
    {
        if (i - 2 >= 0)
        {
            dp[i] = max(dp[i - 2] + v[i - 1], dp[i - 1]); 
        }
        else
        {
            dp[i] = v[i - 1];  
        }
    }

    cout << dp[size] << endl;  
    return 0;
}
