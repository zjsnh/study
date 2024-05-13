#include<iostream>
#include<vector>
#include<list>
using namespace std;


//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int left = 0;
//        int right = 1;
//        int subarray = 0;
//        while (left < nums.size())
//        {
//            int num = nums[left];
//            if (num == k)
//            {
//                subarray++;
//            }
//            while (right < nums.size())
//            {
//                num += nums[right];
//                if (num == k)
//                {
//                    subarray++;
//                }
//
//                right++;
//            }
//
//            left++;
//            right = left+1;
//
//        }
//
//        return subarray;
//
//    }
//};
//
//
//int main()
//{
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(-1);
//    nums.push_back(0);
//
//    Solution s;
//    cout << s.subarraySum(nums, 0);
//
//    return 0;
//
//}
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//};
//class Solution {
//public:
//    void swap(TreeNode*& p1, TreeNode*& p2)
//    {
//        TreeNode* temp = p1;
//        p1 = p2;
//        p2 = temp;
//    }
//
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr)
//            return root;
//
//        if (root->left)
//            invertTree(root->left);
//
//
//        if (root->right)
//            invertTree(root->right);
//
//    }
//};
//
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//
//void swap(ListNode*& p1, ListNode*& p2)
//{
//    ListNode* temp = p1;
//    p1 = p2;
//    p2 = temp;
//}
//
//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//    if (!list1)
//        return list2; // 如果 list1 为空，直接返回 list2
//    if (!list2)
//        return list1; // 如果 list2 为空，直接返回 list1
//
//    if (list1->val > list2->val)
//    {
//        swap(list1, list2);
//    }
//
//    ListNode* head = list1; // 选取头节点
//
//    while (list1 && list2)
//    {
//        while (list1->next && list1->next->val <= list2->val)
//        {
//            list1 = list1->next;
//        }
//
//        ListNode* cur = list1->next;
//        list1->next = list2;
//        list1 = list2;
//        list2 = cur;
//    }
//    if (list2 != nullptr)
//        list1->next = list2;
//
//    return head;
//}
//
//int main()
//{
//	ListNode* List1 = nullptr;
//	List1 = new ListNode;
//	List1->val = 2;
//	List1->next = new ListNode;
//	List1->next->val = 3;
//	List1->next->next = new ListNode;
//	List1->next->next->val = 5;
//	List1->next->next->next = nullptr;
//
//	ListNode* List2 = nullptr;
//	List2 = new ListNode;
//	List2->val = 1;
//	List2->next = new ListNode;
//	List2->next->val = 2;
//	List2->next->next = new ListNode;
//	List2->next->next->val = 3;
//	List2->next->next->next = nullptr;
//
//
//    ListNode* head=mergeTwoLists(List1, List2);
//    ListNode* cur = head;
//
//    while (cur != nullptr)
//    {
//        cout << cur->val << " ";
//        cur = cur->next;
//    }
//
//    return 0;
//
//
//
//}


//void swap(int& p1, int& p2)
//{
//    int temp = p1;
//    p1 = p2;
//    p2 = temp;
//}

//void moveZeroes(vector<int>& nums) {
//    int zero = 0;
//    int u_zero = 0;
//    while (u_zero < nums.size() && zero < nums.size())
//    {
//        if (nums[zero] == 0)
//        {
//            while (nums[u_zero] == 0 && u_zero < nums.size()-1)
//            {
//                u_zero++;
//            }
//            
//            swap(nums[zero], nums[u_zero]);
//        }
//
//        if (u_zero == nums.size() - 1)
//        {
//            break;
//        }
//
//        zero++;
//    }
//}

//int main()
//{
//    vector<int> v = { 0,1,3,0,12 };
//    moveZeroes(v);
//
//    for (auto it : v)
//    {
//        cout << it << " ";
//    }
//
//    return 0;
//}

//int sum(vector<int>& nums, int left, int right)
//{
//    int temp = 0;
//    while (left < right) // 修改为 left < right
//    {
//        temp += nums[left];
//        temp += nums[right];
//        left++;
//        right--;
//    }
//    if (left == right) // 处理奇数长度的子数组
//        temp += nums[left];
//    return temp;
//}
//
//void compare(vector<int>& nums, int& left, int& right)
//{
//    int right_max = sum(nums, left, right - 1);
//    int left_max = sum(nums, left - 1, right);
//
//    if (right_max > left_max)
//        --right;
//    else
//        ++left;
//}
//
//int maxSubArray(vector<int>& nums) {
//    int _max = nums[0];
//    int left = 0, right = nums.size() - 1;
//
//    while (left <= right) // 修改为 left <= right
//    {
//        int max_con = sum(nums, left, right);
//
//        if (max_con > _max)
//            _max = max_con;
//
//        if (nums[left] > nums[right])
//            --right;
//        else if (nums[left] == nums[right])
//            compare(nums, left, right);
//        else
//            ++left;
//    }
//
//    return _max > nums[left] ? _max : nums[left];
//}

//int maxSubArray(vector<int>& nums) {
//    int n = nums.size();
//    if (n == 0)
//        return 0; // 处理空数组的情况
//
//    int left = 0, right = n - 1; // 定义两个指针
//    int currentSum = 0;          // 当前子数组和
//    int maxSum = nums[0]; // 最大子数组和，初始化为数组的第一个元素
//
//    while (left <= right) {
//        // 如果当前子数组和小于等于0，就从下一个元素重新开始计算子数组和
//        if (currentSum <= 0) {
//            currentSum = nums[left];
//        }
//        else {
//            // 否则，将当前元素加入子数组
//            currentSum += nums[left];
//        }
//
//        // 更新最大子数组和
//        maxSum = max(maxSum, currentSum);
//
//        left++; // 向右移动左指针
//    }
//
//    // 返回最大子数组和
//    return maxSum;
//}
//
//
//
//int main()
//{
//    vector<int> v = { -2,1,-3,4,-1,2,1,-8,4 };
//
//    cout<<maxSubArray(v);
//
//    
//    return 0;
//}

int main()
{
	list<int> l = { 1,2,3,4,5 };

	list<int>::reverse_iterator it = l.rbegin();

	cout << *it << " ";
	//it++;

	it.operator--();
	cout << *it << " ";


	return 0;
}