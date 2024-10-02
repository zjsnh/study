//#include<iostream>
//using namespace std;
//using ll = long long;
//
//bool even(const ll& num) {
//    return (num % 2) == 0;
//}
//
//bool prime_num(const ll& num) {
//    if (num <= 1) return false; 
//    for (ll i = 2; i * i <= num; ++i) {
//        if (num % i == 0) return false; 
//    }
//    return true;
//}
//
//int main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        ll a, b;
//        cin >> a >> b;
//
//        if ((even(a) || even(b)) || (a != 1 && b != 1)) {
//            cout << "NO" << endl;
//            continue;
//        }
//        
//        if (prime_num(a * b)) {
//            cout << "YES" << endl;
//            continue;
//        }
//        else
//        {
//            cout << "NO" << endl;
//            continue;
//        }
//    }
//}




//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//// ->  ÅÅÐò ±éÀú
//using ll = long long;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	vector<ll> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	sort(v.begin(), v.end());
//
//	int fast = 0, slow = 0;
//
//	int num = 0;
//	int _num = 0;
//	while (fast < v.size()&& slow <= fast)
//	{
//		if (v[fast] - v[slow] <= k)
//		{
//			if ((fast - slow + 1) > num)
//			{
//				num = fast - slow + 1;
//			}
//
//			fast++;
//		}
//		else
//		{
//			slow++;
//		}
//	}
//
//	cout << num << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//#include<vector>
//
//
////else
////{
////	num = max(num, (int)v.size());
////	v.clear();
////	++_num;
////	i = _num;
////}
//
////¶ÌµÄÊÇs1
//int length_s(const string& s1, const string& s2) {
//    int num = 0;
//    vector<char> v;
//    int _num = 0;
//
//    int circulate = 0;
//    int pos = 0;
//
//    for (int i = 0; i < s1.size(); i++) {
//        v.push_back(s1[i]);
//
//        for (int j = pos; j < s2.size(); j++) {
//            if (s2[j] == v.back()) {
//                pos = j + 1;
//                _num++; 
//                break; 
//            }
//
//            if (i == s1.size() - 1 && j == s2.size() - 1)
//            {
//
//                num = max(_num, num);
//                if (++circulate == s1.size())
//                {
//                    return num;
//                }
//
//                i = circulate - 1;
//                _num = 0;
//                pos = 0;
//                v.clear();
//                break;
//            }
//
//        }
//
//    }
//
//    return num; 
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//    string _short;
//    string _long;
//
//
//    if (a > b)
//    {
//        cin >> _long >> _short;
//    }
//    else
//    {
//        cin >> _short >> _long;
//    }
//
//
//
//	cout << length_s(_short, _long) << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>

//vector<vector<int>> merge(vector<vector<int>>& intervals) {
//
//    sort(intervals.begin(), intervals.end(),
//        [](const vector<int>& p1, const vector<int>& p2) {
//            return p1[0] < p2[0];
//        });
//
//    for (int i = 1; i < intervals.size();) {
//        if (intervals[i - 1][1] >= intervals[i][0]) {
//            intervals[i - 1][1] = max(intervals[i][1], intervals[i - 1][1]);
//            i = (intervals.erase(intervals.begin() + i)) - intervals.begin();
//        }
//        else
//        {
//            i++;
//        }
//    }
//
//    return intervals;
//}

//void rotate(vector<int>& nums, int k) {
//
//    k %= nums.size();
//
//    reverse(nums.begin(), nums.begin() + k);
//    reverse(nums.begin() + k + 1, nums.end());
//
//    reverse(nums.begin(), nums.end());
//
//}



//vector<int> productExceptSelf(vector<int>& nums) {
//
//	int zero_num = 0;
//	int multiply = 1;
//
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] == 0 && !zero_num)
//		{
//			zero_num++;
//			continue;
//		}
//
//		
//		multiply *= nums[i];
//
//	}
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (zero_num && (nums[i] != 0))
//		{
//			nums[i] = 0;
//		}
//		else if(zero_num && (nums[i] == 0))
//		{
//			nums[i] = multiply;
//		}
//		else
//		{
//			nums[i] = multiply / nums[i];
//		}
//	}
//
//
//	return nums;
//
//}
//
//int main()
//{
//	vector<int> nums = { 0,4,0 };
//	productExceptSelf(nums);
//
//
//	return 0;
//}


//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int firstMissingPositive(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//
//    int expected = 1; 
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[i] == expected) {
//            expected++;
//        }
//    }
//
//    return expected; 
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//void setZeroes(vector<vector<int>>& matrix) {
//
//
//	vector<int> line;
//
//	for (int i = 0; i < matrix.size(); i++)
//	{
//		for (int j = 0; j < matrix[0].size(); j++)
//		{
//
//		}
//	}
//
//
//
//}


//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//
//
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    ListNode* root = head;
//    ListNode* _root = head;
//
//    while (n-- > 0 && _root != nullptr) {
//        _root = _root->next;
//    }
//
//    if (_root == nullptr) {
//        return head->next; 
//    }
//
//    while (_root->next != nullptr) {
//        root = root->next;
//        _root = _root->next;
//    }
//
//    if (root->next != nullptr) {
//        root->next = root->next->next;
//    }
//
//    return head;
//}
//
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//void _swap(ListNode*& root, ListNode*& _root)
//{
//    root->next = _root->next;
//    _root->next = root;
//
//    //swap(root, _root);
//}
//
//
//ListNode* swapPairs(ListNode* head) {
//
//    if (head == nullptr && head->next == nullptr)
//    {
//        return head;
//    }
//
//    ListNode* root = head;
//    ListNode* newhead = head->next;
//
//    while (root->next != nullptr)
//    {
//        _swap(root, root->next);
//        
//        root = root->next;
//    }
//
//    return newhead;
//
//}


#include<iostream>
using namespace std;


