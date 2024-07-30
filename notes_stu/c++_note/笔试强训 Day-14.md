# 笔试强训 Day-14

![image-20240730131309686](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240730131309686.png)

![image-20240730165037289](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240730165037289.png)![image-20240730165627663](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240730165627663.png)

```C++
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
    int a=0;
    cin>>a;
    int b;
    vector<int> V;
    while(cin>>b)
    {
        V.push_back(b);
    }

    sort(V.begin(),V.end());

    int i=V.size()-1;
    long long num=0;
    while(a)
    {
        num+=V[i-1];
        i-=2;
        --a;
    }

    cout<<num<<endl;
    return 0;

}
```

