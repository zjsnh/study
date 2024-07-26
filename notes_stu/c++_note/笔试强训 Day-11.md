# 笔试强训 Day-11

![image-20240726111326204](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240726111326204.png)



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

![image-20240726114024664](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240726114024664.png)