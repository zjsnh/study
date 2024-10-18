//#include<iostream>
//using namespace std;
//#include<list>
//
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		list<int> l;
//
//		for (int i = 0; i <= n; i++)
//		{
//			l.push_back(i);
//		}
//
//		while (l.size() != 1)
//		{
//			int num = 1;
//			list<int>::iterator it = l.begin();
//			while (it != l.end())
//			{
//				if (num)
//				{
//					it = l.erase(it);
//					num = 0;
//					continue;
//				}
//
//				num = 1;
//				it++;
//			}
//		}
//
//		cout << l.front() << endl;
//	}
//
//	return 0;
//}




#include <iostream>
#include <vector>

using namespace std;


void find_combinations(int n, int m, int start, vector<int>& combination, vector<vector<int>>& result) {
    if (m == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i <= n; ++i) {
        if (i > m) break;
        combination.push_back(i);

        find_combinations(n, m - i, i + 1, combination, result);

        combination.pop_back();
    }
}

int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;


    vector<vector<int>> result;
    vector<int> combination;

    find_combinations(n, m, 1, combination, result);
    cout << "Combinations that sum to " << m << " are: " << endl;
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}



//
//
//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//
//void longest_length(const string& _long, const string& _short)
//{
//	int l_pos = 0, s_pos = 0, last_pos = 0;
//	int num = 0;
//	int _num;
//
//	while (l_pos + _short.size() < _long.size())   //中间
//	{
//		last_pos++;
//
//		while (l_pos < _long.size() && s_pos < _short.size())
//		{
//			if (_long[l_pos] == _short[s_pos])
//			{
//				_num++;
//			}
//
//			l_pos++;
//			s_pos++;
//		}
//
//		l_pos = last_pos;
//		s_pos = 0;
//		num = max(_num, num);
//
//	}
//
//
//	cout << num << endl; // 最长匹配的长度
//
//	cout << _long.size() + _short.size() - num << endl;
//
//	return;
//}
//
//
//int main()
//{
//	string _str1, _str2;
//	cin >> _str1;
//	cin >> _str2;
//
//	(_str1.size() > _str2.size()) ? 
//		(longest_length(_str1, _str2)) : (longest_length(_str2, _str1));
//
//	return 0;
//}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string& str1, const string& str2)
{
    int m = str1.size();
    int n = str2.size();

    // 创建一个二维动态规划表，大小为 (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 初始化 base cases
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;  // 把 str1 的前 i 个字符变成空字符串
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;  // 把空字符串变成 str2 的前 j 个字符

    // 填充动态规划表
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];  // 相等时，无需编辑
            else
                dp[i][j] = min({ dp[i - 1][j] + 1,    // 删除
                                 dp[i][j - 1] + 1,    // 插入
                                 dp[i - 1][j - 1] + 1 // 替换
                    });
        }
    }

    // dp[m][n] 是最终的编辑距离
    return dp[m][n];
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int distance = edit_distance(str1, str2);
    cout << "The edit distance is: " << distance << endl;

    return 0;
}
