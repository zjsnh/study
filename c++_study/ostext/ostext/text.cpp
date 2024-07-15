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


bool Jump(vector<int>& nums, int i)
{
    if (i >= nums.size()-1)
    {
        return true;
    }

    int nextPos = -1;
    for (int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1); j++)
    {
        if (nums[j] > nums[i])
        {
            nextPos = j;
            break;
        }
    }

    if (nextPos == -1) // 如果没有找到比当前数大的数，则无法前进
    {
        return false;
    }

    return Jump(nums, nextPos); // 递归跳到下一个位置

}

bool canJump(vector<int>& nums) {
    
    int i = 0;
    return Jump(nums, i);
}


int main()
{
    vector<int> nums = { 2,3,1,1,4 };
    cout<< canJump(nums);
    return 0;
}