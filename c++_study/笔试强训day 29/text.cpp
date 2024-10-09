//#include<iostream>
//using namespace std;
//#include<stack>
//
//using ll = long long;
//
//stack<ll> sum;
//ll compute(ll& H, int& num)
//{
//    ll n = 2;
//    while (H >= n)
//    {
//        H -= n;
//        num++;
//        sum.push(n * 2);
//        n = n + n * 2;
//    }
//    return n;
//}
//
//void _compute(ll& H, int& num)
//{
//
//    while (H > 0)
//    {
//        if (H >= sum.top())
//        {
//            H -= sum.top();
//            num++;
//        }
//        sum.pop();
//    }
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//
//
//
//    while (T--)
//    {
//
//        sum.push(2);
//
//        ll H;
//        cin >> H;
//
//        int num = 0;
//        int flag = 2;
//
//        if ((H - 1) % 2 == 0)
//        {
//            H -= 1;
//            flag = 1;
//        }
//        else
//        {
//            H -= 2;
//            flag = 2;
//        }
//
//        ll n = compute(H, num);
//        _compute(H, num);
//
//        num += flag;
//        cout << num << endl;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//
//using ll = long long;
//
//int main()
//{
//	int size;
//	cin >> size;
//
//	vector<ll> v(size);
//	for (int i = 0; i < size; i++)
//	{
//		cin >> v[i];
//	}
//
//	int num = 1;
//	int flag = 1;// -> 1  递增  -1  递减
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] == v[i - 1])
//		{
//			continue;
//		}
//
//		if (v[i] > v[i - 1])
//		{
//			int _flag = 1;
//			if (flag == _flag)
//			{
//				continue;
//			}
//			else
//			{
//				flag = _flag;
//				num++;
//			}
//		}
//		else
//		{
//			int _flag = -1;
//			if (flag == _flag)
//			{
//				continue;
//			}
//			else
//			{
//				flag = _flag;
//				num++;
//			}
//		}
//
//	}
//
//	cout << num << endl;
//
//	return 0;
//}

//13
//1 1 2 2 1 1 2 2 1 1 2 2 3

//
//#include <iostream>
//#include <vector>
//using namespace std;
//using ll = long long;

//int min_sorted_subsequences(const std::vector<ll>& arr) {
//    if (arr.size() <= 1) return 1;
//
//    int count = 1;
//    int n = arr.size();
//    bool increasing = false;  // 判断当前序列是递增还是递减
//    bool defined = false;     // 判断是否已经确定了当前趋势
//
//    for (int i = 1; i < n; ++i) {
//        if (arr[i] > arr[i - 1]) {
//            // 当前是递增
//            if (defined && !increasing) {
//                count++;  // 从递减变为递增，分段
//                defined = false;  // 重置趋势定义
//            }
//            increasing = true;
//            defined = true;
//        }
//        else if (arr[i] < arr[i - 1]) {
//            // 当前是递减
//            if (defined && increasing) {
//                count++;  // 从递增变为递减，分段
//                defined = false;  // 重置趋势定义
//            }
//            increasing = false;
//            defined = true;
//        }
//        // 如果 arr[i] == arr[i - 1]，不需要改变趋势，继续遍历
//    }
//    return count;
//}

//int main()
//{
//    int size;
//    cin >> size;
//
//    if (size == 1)
//    {
//        cout << 1 << endl;
//        return 0;
//    }
//
//    vector<ll> v(size);
//    for (int i = 0; i < size; i++)
//    {
//        cin >> v[i];
//    }
//
//    //cout << min_sorted_subsequences(v) << endl;
//
//    //int num = 0;
//    //int direction = 0;
//
//    //int flag = 0;
//    //for (int i = 1; i < size; i++)
//    //{
//    //    int new_direction = 0;
//    //    if (v[i] == v[i - 1])
//    //    {
//    //        new_direction = direction;
//    //    }
//    //    else
//    //    {
//    //        if (v[i] > v[i - 1])
//    //        {
//    //            new_direction = 1;
//    //        }
//    //        else
//    //        {
//    //            new_direction = -1;
//    //        }
//
//    //    }
//
//    //    if (new_direction != direction && !flag)//转变了  ->   flag == 1   
//    //    {
//    //        flag = 1;
//    //        continue;
//    //    }
//
//    //    if (flag == 1)
//    //    {
//    //        num++;
//    //        flag = 0;
//    //        direction = new_direction;
//    //    }
//    //}
//
//    //if (flag == 1)
//    //{
//    //    num++;
//    //}
//
//    //cout << num << endl;
//    return 0;
//}



//
//#include<algorithm>
//int LIS(vector<int>& a) {
//    // write code here
//
//    vector<int> dp;
//
//    for (int i = 0; i < a.size(); i++)
//    {
//        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
//
//        if (it == dp.end())
//        {
//            dp.push_back(a[i]);
//        }
//        else
//        {
//            *it = a[i];
//        }
//    }
//
//    return dp.size();
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//bool canJump(vector<int>& nums) {
//
//    vector<int> dp;
//    dp.push_back(1);
//    int pos = 1;
//
//    for (int i = 0; i < nums.size(); i++)
//    {
//        if ((nums[i] + i + 1) > pos) 
//        {
//            pos = nums[i] + i + 1;
//            dp.resize(pos, 1);
//            
//        }
//
//        if (nums[i] == 0 && pos == i + 1)
//        {
//            break;
//        }
//        
//    }
//
//    if (pos >= nums.size())
//    {
//        return true;
//    }
//
//    return false;
//
//}
//
//int main()
//{
//
//    vector<int> text = { 3, 2, 1, 0, 4 };
//
//    cout << canJump(text);
//
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//
//
//int jump(vector<int>& nums) {
//    if (nums.size() < 2) return 0;
//
//    int pos = 0;
//    int jumps = 0;
//
//    while (pos < nums.size() - 1) {
//
//        int max_reach = pos + nums[pos];
//        if (max_reach >= nums.size() - 1) {
//            jumps++;
//            break;
//        }
//
//        pair<int, int> _max = { 0, pos };
//        for (int _pos = pos + 1; _pos <= max_reach; ++_pos) {
//            if (_pos < nums.size() && nums[_pos] + _pos > _max.first) {
//                _max.first = nums[_pos] + _pos;
//                _max.second = _pos;
//            }
//        }
//
//        pos = _max.second;
//        jumps++;
//    }
//
//    return jumps;
//}
//
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<unordered_set>
//using namespace std;
//
//
//class RandomizedSet {
//public:
//    RandomizedSet() {
//
//    }
//
//    bool insert(int val) {
//
//        return _set.insert(val).second;
//
//    }
//
//    bool remove(int val) {
//
//        return _set.erase(val);
//
//    }
//
//    int getRandom() {
//
//        int i = rand() % _set.size();
//        unordered_set<int>::iterator it = _set.begin();
//
//        while (i--)
//        {
//            it++;
//        }
//
//        return *it;
//
//    }
//
//    unordered_set<int> _set;
//
//};
//
//int main()
//{
//    unordered_set<int> i;
//}

#include<vector>
#include<iostream>
#include<string>
using namespace std;

//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//
//	
//
//
//}

bool isPalindrome(int x) {

    if (x < 0)
        return false;

    string s = to_string(x);
    string _s = s;
    reverse(s.begin(), s.end());

    if (s == _s )
        return true;

    return false;

}

