//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string S = { "aabbaa" };
//
//
//    for (size_t i = 1; i < S.size();) {
//        if ( i != 0 && S[i] == S[i - 1]) {
//            S.erase(i - 1, 2);
//            --i;
//        }
//        else {
//            i++;
//        }
//    }
//
//    if (S.size() != 0)
//        cout << S << endl;
//    else
//        cout << "0" << endl;
//    return 0;
//}


//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	try
//	{
//        int a = 2, b = 22;
//        string num;
//
//        int nums = 0;
//
//        for (int i = a; i <= b; i++)
//        {
//            num += to_string(i);
//        }
//
//        for (auto e : num)
//        {
//            if (e == '2')
//            {
//                nums++;
//            }
//        }
//
//        cout << nums << endl;
//	}
//	catch (const std::exception& e)
//	{
//        cout << e.what() << endl;
//	}
//
//    return 0;
//}


#include<iostream>
using namespace std;
#include<vector>


//int maxProfit(vector<int>& prices) {
//
//    int Last_profit = 0;
//    int minprice = 1e5;
//    int New_profit = 0;
//    for (auto price : prices)
//    {
//        if (price - minprice > New_profit)
//        {
//            New_profit = max(price - minprice, New_profit);
//        }
//        else
//        {
//            Last_profit += New_profit;
//            New_profit = 0;
//            minprice = price;
//        }
//    }
//
//    return Last_profit + New_profit;
//
//}
//
//
//int main()
//{
//    vector<int> prices = { 7,1,5,3,6,4 };
//    cout<< maxProfit(prices);
//
//    return 0;
//}


//bool Jump(vector<int>& nums, int i)
//{
//    if (i >= nums.size()-1)
//    {
//        return true;
//    }
//
//    int nextPos = -1;
//    for (int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1); j++)
//    {
//        if (nums[j] > nums[i])
//        {
//            nextPos = j;
//            break;
//        }
//    }
//
//    if (nextPos == -1) // 如果没有找到比当前数大的数，则无法前进
//    {
//        return false;
//    }
//
//    return Jump(nums, nextPos); // 递归跳到下一个位置
//
//}
//
//bool canJump(vector<int>& nums) {
//    
//    int i = 0;
//    return Jump(nums, i);
//}
//
//
//int main()
//{
//    vector<int> nums = { 2,3,1,1,4 };
//    cout<< canJump(nums);
//    return 0;
//}


#include <iostream>
#include<vector>
using namespace std;
//int main() {
//    vector<int> V = { 1,100, 1, 1, 1, 90, 1, 1, 80, 1 };
//    int a = 10;
//
//    if (V.empty()) {
//        cout << 0;
//        return 0;
//    }
//
//    int budget = V[0];
//    int c = 0;
//
//    if (V.size() > 1) {
//        if (V[0] < V[1]) {
//            budget = V[0];
//            c = 0;
//        }
//        else {
//            budget = V[1];
//            c = 1;
//        }
//    }
//
//    for (int i = c; i < V.size();) {
//        if (i + 1 >= V.size()) {
//            cout << budget;
//            return 0;
//        }
//
//        if (i + 2 >= V.size()) {
//            cout << budget;
//            return 0;
//        }
//
//        if (V[i + 1] < V[i + 2]) {
//            budget += V[i + 1];
//            i += 1;
//        }
//        else {
//            budget += V[i + 2];
//            i += 2;
//        }
//    }
//
//    cout << budget;  // 确保输出最终预算值
//    return 0;
//}

//#include<queue>
//
//int main() {
//
//   /* int c;
//    cin >> c;*/
//    int a = 3, b;
// /*   cin >> a;*/
//
//    priority_queue<int> Q;
//    vector<int> V = { 2, 4, 8, 10, 11 };
//
//
//    //while (cin >> b) {
//    //    V.push_back(b);
//    //}
//
//    int num = 0;
//
//    for (auto e : V)
//    {
//        if ((e & 1) == 0)
//        {
//            Q.push(e);
//        }
//        else
//        {
//            num += e;
//        }
//    }
//
//    for (int i = 0; i < a && !Q.empty(); i++)
//    {
//        while ((Q.top() & 1) != 0 && !Q.empty())
//        {
//            num += Q.top();
//            Q.pop();
//        }
//
//        if (Q.empty())
//        {
//            break;
//        }
//      
//        int temp = Q.top() / 2;
//        Q.pop();
//        Q.push(temp);
//      
//    }
//
//    while (!Q.empty())
//    {
//        num += Q.top();
//        Q.pop();
//    }
//
//    cout << num << endl;
//
//
//    return 0;
//}

int main() {
    //int L;
   // cin >> L;

    int critical = 20;
   // cin >> critical;

    vector<int> V = { 1, 1, 6, 10, 9, 3, 3, 5, 3, 7 };

    /*int b;
    while (cin >> b)
    {
        V.push_back(b);
    }*/

    int mindistance = V.size();
    int right = 0;
    int left = 0;

    pair<int, int> LR_Location;

    int num = 0;

    /*for (int i = 0; i < V.size(); )
    {
        if (num >= critical)
        {
            if (right - left + 1 < mindistance)
            {
                LR_Location = pair<int, int>(left, right);
                mindistance = right - left + 1;
            }

            while (left <= right && num > critical)
            {
                num -= V[left];
                if (num > critical)
                {
                    left++;

                    LR_Location = pair<int, int>(left, right);
                    --mindistance;
                }
            }
        }
        else
        {
            num += V[i];
            right = i;
            i++;
        }
    }*/

    while (right < V.size()) {
        num += V[right];

        while (num >= critical) {
            if (right - left + 1 < mindistance) {
                LR_Location = pair<int, int>(left, right);
                mindistance = right - left + 1;
            }
            num -= V[left];
            left++;
        }
        right++;
    }

    cout << LR_Location.first + 1 << " " << LR_Location.second + 1 << endl;
    return 0;


}