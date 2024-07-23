# 笔试强训Day—8

## 最小公倍数

![image-20240723102729555](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240723102729555.png)

```C++
#include <iostream>
using namespace std;
#include<unordered_map>
#include<vector>

int main() {
    long long a, b;
    cin >> a;
    cin >> b;

    long long least_com_mul = a * b;

    vector<long long> a_mul;
    for (long long i = 1; i <= least_com_mul / a; i++) {
        a_mul.push_back(i * a);
    }

    vector<long long> b_mul;
    for (long long i = 1; i <= least_com_mul / b; i++) {
        b_mul.push_back(i * b);
    }


    unordered_map<long long, int> com_mul;

    for (const auto& e : a_mul) {
        com_mul[e]++;
    }

    for (const auto& e : b_mul) {
        if (com_mul.find(e) != com_mul.end()) {
            cout << e << endl;
            break;
        }
    }

    return 0;
}
```

**ps：注意题目 a b的范围，如果使用int范围太小**

## 数组中最长连续的子序列

![image-20240723110432587](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240723110432587.png)

有重复的，排完序，需要跳过重复的

```C++
int MLS(vector<int>& arr) {
    // write code here

    sort(arr.begin(), arr.end());

    int right = 1;
    int count = 1;
    int max_str = 1;

    while (right < arr.size())
    {
        if (arr[right] == arr[right - 1])
            continue;

        if (arr[right] == arr[right - 1] + 1)
            count++;
        else
            count = 1;

        max_str = max(count, max_str);

        right++;
    }

    return max_str;
}
```

![image-20240723122421390](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240723122421390.png)

![image-20240723122426068](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240723122426068.png)

**使用路径递归 超时**

![image-20240723170708418](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240723170708418.png)

**动态规划**