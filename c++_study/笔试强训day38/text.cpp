//#include <iostream>
//#include <vector>
//using namespace std;
//using ll = long long;
//
//int main() {
//    ll n;
//    cin >> n;
//    vector<ll> a(n);
//    vector<ll> num(n);
//
//    cin >> a[0];
//    ll num1 = a[0], num2 = a[0];
//    num[0] = num2;
//
//    for (int i = 1; i < n; i++) {
//        cin >> a[i];
//
//        if (a[i] >= num1) {
//            num2 = num1;
//            num1 = a[i];
//            num[i] = num2;
//        }
//        else if (a[i] > num2 && a[i] < num1) {
//            num2 = a[i];
//            num[i] = num2;
//        }
//        else {
//            num[i] = num2;
//        }
//    }
//
//    ll size;
//    cin >> size;
//    for (ll i = 0; i < size; i++) {
//        int idx;
//        cin >> idx;
//        cout << num[idx] << endl;
//       
//    }
//
//    return 0;
//}

//2
//1 2
//3 4
//1
//1

//2
//1 2
//3 4


//#include <iostream>
//using namespace std;
//#include <vector>
//
//void overturning(vector<vector<int> >& matrix)
//{
//	int size = matrix.size();
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - i; j++)
//		{
//			std::swap(matrix[i][j], matrix[size - i - 1][size - j - 1]);
//		}
//	}
//
//	return;
//	
//}
//
//void mirror(vector<vector<int> >& matrix)
//{
//	int size = matrix.size();
//
//	for (int i = 0; i < size / 2; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			std::swap(matrix[i][j], matrix[size - i - 1][j]);
//		}
//	}
//
//}
//
//
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	vector<vector<int> > matrix(n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int a = 0;
//			cin >> a;
//			matrix[i].push_back(a);
//		}
//	}
//
//	int num;
//	cin >> num;
//
//	int overturning_ = 0;
//	int mirror_ = 0;
//
//	while (num--)
//	{
//		int a;
//		cin >> a;
//
//		if (a == 1)
//		{
//			overturning_++;
//			overturning_ % 2;
//		}
//		else
//		{
//			mirror_++;
//			mirror_ % 2;
//		}
//		
//	}
//
//	if (overturning_)
//	{
//		overturning(matrix);
//	}
//
//	if (mirror_)
//	{
//		mirror(matrix);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << matrix[i][j] <<" ";
//		}
//		cout << endl;
//	}
//
//	
//	return 0;
//}


//
//
//#include <iostream>
//using namespace std;
//#include <vector>
//using ll = long long;
//
//ll dp[1005][1005] = {0};
//
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<ll> a(n+1);
//	a[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[n];
//	}
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			if()
//		}
//	}
//	
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//#include <algorithm>
//
//class Solution {
//public:
//
//    bool verify(const string& s1,const string& s2)
//    {
//        if (s1 == s2)
//            return true;
//
//        s1.c_str() - '0';
//        s2.c_str() - '0';
//
//        if (abs(s1.c_str() - s2.c_str()) == 32)
//            return true;
//
//        return false;
//
//    }
//
//    bool isPalindrome(string s) {
//
//        if (s.size() == 0)
//            return false;
//
//        int left = 0;
//        int right = s.size() - 1;
//
//        while (right > left)
//        {
//
//        }
//
//
//    }
//};
//
//int main()
//{
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        if (nums.size() == 0)
//        {
//            return 0;
//        }
//
//        int right = 0;
//        int left = 0;
//
//        int len = INT_MAX;
//
//        int sum = 0;;
//        while (right < nums.size())
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                len = min(len, right - left + 1);//最短的大于等于target的数组长度
//
//                sum -= nums[left]; 
//                left++;
//            }
//            right++;
//        }
//
//        return len == INT_MAX ? 0 : len;
//    }
//};

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

//class Solution {
//public:
//    bool canConstruct(std::string ransomNote, std::string magazine) {
//
//        std::unordered_map<char, int> _ransomNote;
//        std::unordered_map<char, int> _magazine;
//        for (auto& e : ransomNote)
//        {
//            _ransomNote[e]++;
//        }
//
//        for (auto& e : magazine)
//        {
//            _magazine[e]++;
//        }
//
//        for (auto& s : _ransomNote)
//        {
//            if (_magazine[s.first] < s.second)
//                return false;
//        }
//        return true;
//
//
//    }
//};

class Solution {
public:
    static bool isIsomorphic(string t, string s) {
        if (s.size() != t.size())
            return false;
        std::unordered_map<char, char> _map;

        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            int it = _map.count(s[i]);
            if ( it == 0)
            {
                _map[s[i]] = t[i];
            }
            else
            {
                if (_map[s[i]] != t[i])
                    return false;
            }
            
        }

        return true;
    }
};

int main()
{
    Solution::isIsomorphic("badc", "baba");
    return 0;
}