# 笔试强训 DAY -10

## 最长回文子串

![image-20240724215017448](picture/image-20240724215017448.png)

```C++
bool palindromic(string str) {
        string copy = str;

        reverse(str.begin(), str.end());

        if (copy == str)
            return true;

        return false;
    }
    int getLongestPalindrome(string Str) {

        int max_distance = 1;

        for (int i = 1; i < Str.size(); i++) {
            int left = 1;
            int right = i;
            string str = Str.substr(0, i + 1);
            if (palindromic(str))
                max_distance = i + 1;

            for (; left < right; left++) {
                if (right - left + 1 > max_distance) {
                    str = Str.substr(left, right - left + 1);
                    if (palindromic(str))
                        max_distance = right - left + 1;
                }
            }

        }

        return max_distance;
    }
```

**使用最佳排列的组合循环，同时判断当前最长字符串长度，如果小于，就直接跳过该循环**

## 买卖股票的最佳时机

![](picture/image-20240724215129347.png)

```C++
#include <iostream>
using namespace std;
#include<vector>

int main()
{
    int i=0;
    cin>>i;

    int b=0;
    vector<int> prices;
    while(cin>>b)
    {
        prices.push_back(b);
    }
    int maxprices = 0;
    int minprice = 1e5;

    for (auto price : prices)
    {
        if (minprice > price)
        {
            minprice = price;
        }

        maxprices = max(maxprices, price - minprice );

    }
    cout << maxprices << endl;

    return 0;
}
```

记录最小价格，和最佳买差距价格，同时进行更新

## 过河卒

![image-20240724215150082](picture/image-20240724215150082.png)

```C++
#include <iostream>
using namespace std;
#include<vector>

bool horse_board(vector<pair<int, int>>& horse, int x, int y);

int path(int x, int y, vector<pair<int, int>>& horse, pair<int, int>& soldier) {
    if (x < 0 || x > soldier.first || y < 0 || y > soldier.second) {
        return 0;
    }

    if (x == soldier.first && y == soldier.second)
        return 1;

    if (horse_board(horse, x, y))
        return 0;

    return path(x + 1, y, horse, soldier) + path(x, y + 1, horse, soldier);

}

bool horse_board(vector<pair<int, int>>& horse, int x, int y) {
    for (const auto& h : horse) {
        if (h.first == x && h.second == y) {
            return true;
        }
    }
    return false;
}

int main() {
    pair<int, int> soldier;
    cin >> soldier.first >> soldier.second;
    //soldier.first = 5;
    //soldier.second = 4;
    int a ;
    int b;
    cin>>a>>b;
    vector<pair<int, int>> horse;
    horse.push_back(make_pair(a, b));
    //先存入本身位置
    int dx_horse[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy_horse[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

    for (int i = 0; i < 8; i++) {
        int x = horse[0].first + dx_horse[i];
        int y = horse[0].second + dy_horse[i];

        if (x >= 0 && x <= soldier.first && y >= 0 && y <= soldier.second) {
            horse.push_back(make_pair(x, y));
        }
    }

    cout << path(0, 0, horse, soldier) << endl;

    return 0;
}
```

![image-20240724215319248](picture/image-20240724215319248.png)

**我将第一位设为 1 到达最后就是把所有路径上可到达该位置的 1 加到一起**

![image-20240725221543235](picture/image-20240725221543235.png)

```c++
#include<bits/stdc++.h>
using namespace std;
int n, m, x, y;
long long dp[50][50];
int lab[50][50];
int dir[8][2] = { -1,-2,1,-2,-2,-1,2,-1,-2,1,-1,2,1,2,2,1 };
int main()
{
    cin >> n >> m >> x >> y;
    dp[0][0] = 1;
    lab[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        lab[xx][yy] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (lab[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
```

