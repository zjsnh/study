#include<iostream>
#include<vector>

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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

};
class Solution {
public:
    void swap(TreeNode*& p1, TreeNode*& p2)
    {
        TreeNode* temp = p1;
        p1 = p2;
        p2 = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        if (root->left)
            invertTree(root->left);


        if (root->right)
            invertTree(root->right);

    }
};

struct ListNode
{
	int val;
	ListNode* next;
};

void swap(ListNode*& p1, ListNode*& p2)
{
    ListNode* temp = p1;
    p1 = p2;
    p2 = temp;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1)
        return list2; // 如果 list1 为空，直接返回 list2
    if (!list2)
        return list1; // 如果 list2 为空，直接返回 list1

    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }

    ListNode* head = list1; // 选取头节点

    while (list1 && list2)
    {
        while (list1->next && list1->next->val <= list2->val)
        {
            list1 = list1->next;
        }

        ListNode* cur = list1->next;
        list1->next = list2;
        list1 = list2;
        list2 = cur;
    }
    if (list2 != nullptr)
        list1->next = list2;

    return head;
}

int main()
{
	ListNode* List1 = nullptr;
	List1 = new ListNode;
	List1->val = 2;
	List1->next = new ListNode;
	List1->next->val = 3;
	List1->next->next = new ListNode;
	List1->next->next->val = 5;
	List1->next->next->next = nullptr;

	ListNode* List2 = nullptr;
	List2 = new ListNode;
	List2->val = 1;
	List2->next = new ListNode;
	List2->next->val = 2;
	List2->next->next = new ListNode;
	List2->next->next->val = 3;
	List2->next->next->next = nullptr;


    ListNode* head=mergeTwoLists(List1, List2);
    ListNode* cur = head;

    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;



}