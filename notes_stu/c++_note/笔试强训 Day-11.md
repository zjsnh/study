# 笔试强训 Day-11

![image-20240726111326204](picture/image-20240726111326204.png)



```c++
int main()
{
    pair<int, int> apple;
    pair<int, int> peach;

    //first -> price second -> quantity

    cin >> apple.first >> peach.first;
    cin >> apple.second >> peach.second;


    pair<int, int> expensive = apple;
    pair<int, int> cheap = peach;
 

    int real_first_E = expensive.first % 2 == 0 ? expensive.first : expensive.first - 1;
    int real_first_C = cheap.first % 2 == 0 ? cheap.first : cheap.first - 1;

    if (real_first_E * expensive.second < real_first_C * cheap.second)
    {
        expensive = peach;
        cheap = apple;
    }


    long long total = 0;

    while (expensive.first - 2 >= 0 && cheap.first - 1 >= 0)
    {
        expensive.first -= 2;
        cheap.first -= 2;

        total += expensive.second;
    }

    if (cheap.first == 0 || expensive.first == 0||(expensive.first == 1 && cheap.first==1))
        cout << total << endl;

    if (expensive.first == 1 && cheap.first - 2 >= 0)
    {
        total += cheap.second;
        cout << total << endl;
    }
   
    return 0;

}
```

![image-20240726114024664](picture/image-20240726114024664.png)

## 倒置字符串

![image-20240727172558399](picture/image-20240727172558399.png)

```C++
#include<algorithm>
int main() {
    string str;
    getline(cin, str);

    string _str;
    for (string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
        if (*it == ' ') {
            reverse(_str.begin(), _str.end());
            cout << _str << " ";
            _str.clear();
        }
        else {
            _str += *it;
        }
    }

    reverse(_str.begin(), _str.end());
    cout << _str << endl;

    return 0;
}
```

