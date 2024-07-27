# 笔试强训 Day—12

![image-20240727190140633](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240727190140633.png)

使用暴力是一定超时的，时间限制只有1秒，也就是说，肯定是动态规划或者是算法只有0（n）的算法

```C++
int main()
{
    long long n;
    cin >> n;
    string str;
    cin >> str;

    vector<long long> s(str.size() + 1);
    auto sh = s;
    auto shy = s;

    for (int i = 1; i < str.size(); i++)
    {
        s[i] = str[i - 1] == 's' ? s[i - 1] + 1 : s[i - 1];
        sh[i] = str[i - 1] == 'h' ? s[i] + sh[i - 1] : sh[i - 1];
        shy[i] = str[i - 1] == 'y' ? sh[i] + shy[i - 1] : shy[i - 1];
    }

    cout << shy[str.size()] << endl;
    return 0;
}
```

**该序列需要顺序是shy一定的子列，但是可以不同的，位置，我们可以记录当前位置所有的s sh shy序列，因为 h 需要前面有s才能结合，也就是**

**只可意会不可言传**