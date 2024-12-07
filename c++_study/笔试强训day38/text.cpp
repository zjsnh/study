//#include <iostream>
//#include <vector>
//using namespace std;
//using ll = long long;
//
//int main() {
//    ll n;
//    cin >> n;
//    vector<ll> a(n);
//    vector<ll> num(n);
//
//    cin >> a[0];
//    ll num1 = a[0], num2 = a[0];
//    num[0] = num2;
//
//    for (int i = 1; i < n; i++) {
//        cin >> a[i];
//
//        if (a[i] >= num1) {
//            num2 = num1;
//            num1 = a[i];
//            num[i] = num2;
//        }
//        else if (a[i] > num2 && a[i] < num1) {
//            num2 = a[i];
//            num[i] = num2;
//        }
//        else {
//            num[i] = num2;
//        }
//    }
//
//    ll size;
//    cin >> size;
//    for (ll i = 0; i < size; i++) {
//        int idx;
//        cin >> idx;
//        cout << num[idx] << endl;
//       
//    }
//
//    return 0;
//}

//2
//1 2
//3 4
//1
//1

//2
//1 2
//3 4


//#include <iostream>
//using namespace std;
//#include <vector>
//
//void overturning(vector<vector<int> >& matrix)
//{
//	int size = matrix.size();
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - i; j++)
//		{
//			std::swap(matrix[i][j], matrix[size - i - 1][size - j - 1]);
//		}
//	}
//
//	return;
//	
//}
//
//void mirror(vector<vector<int> >& matrix)
//{
//	int size = matrix.size();
//
//	for (int i = 0; i < size / 2; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			std::swap(matrix[i][j], matrix[size - i - 1][j]);
//		}
//	}
//
//}
//
//
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	vector<vector<int> > matrix(n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int a = 0;
//			cin >> a;
//			matrix[i].push_back(a);
//		}
//	}
//
//	int num;
//	cin >> num;
//
//	int overturning_ = 0;
//	int mirror_ = 0;
//
//	while (num--)
//	{
//		int a;
//		cin >> a;
//
//		if (a == 1)
//		{
//			overturning_++;
//			overturning_ % 2;
//		}
//		else
//		{
//			mirror_++;
//			mirror_ % 2;
//		}
//		
//	}
//
//	if (overturning_)
//	{
//		overturning(matrix);
//	}
//
//	if (mirror_)
//	{
//		mirror(matrix);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << matrix[i][j] <<" ";
//		}
//		cout << endl;
//	}
//
//	
//	return 0;
//}


//
//
//#include <iostream>
//using namespace std;
//#include <vector>
//using ll = long long;
//
//ll dp[1005][1005] = {0};
//
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<ll> a(n+1);
//	a[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[n];
//	}
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			if()
//		}
//	}
//	
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//#include <algorithm>
//
//class Solution {
//public:
//
//    bool verify(const string& s1,const string& s2)
//    {
//        if (s1 == s2)
//            return true;
//
//        s1.c_str() - '0';
//        s2.c_str() - '0';
//
//        if (abs(s1.c_str() - s2.c_str()) == 32)
//            return true;
//
//        return false;
//
//    }
//
//    bool isPalindrome(string s) {
//
//        if (s.size() == 0)
//            return false;
//
//        int left = 0;
//        int right = s.size() - 1;
//
//        while (right > left)
//        {
//
//        }
//
//
//    }
//};
//
//int main()
//{
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        if (nums.size() == 0)
//        {
//            return 0;
//        }
//
//        int right = 0;
//        int left = 0;
//
//        int len = INT_MAX;
//
//        int sum = 0;;
//        while (right < nums.size())
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                len = min(len, right - left + 1);//最短的大于等于target的数组长度
//
//                sum -= nums[left]; 
//                left++;
//            }
//            right++;
//        }
//
//        return len == INT_MAX ? 0 : len;
//    }
//};

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
#include <algorithm>

//class Solution {
//public:
//    bool canConstruct(std::string ransomNote, std::string magazine) {
//
//        std::unordered_map<char, int> _ransomNote;
//        std::unordered_map<char, int> _magazine;
//        for (auto& e : ransomNote)
//        {
//            _ransomNote[e]++;
//        }
//
//        for (auto& e : magazine)
//        {
//            _magazine[e]++;
//        }
//
//        for (auto& s : _ransomNote)
//        {
//            if (_magazine[s.first] < s.second)
//                return false;
//        }
//        return true;
//
//
//    }
//};

//class Solution {
//public:
//    static bool isIsomorphic(string t, string s) {
//        if (s.size() != t.size())
//            return false;
//        std::unordered_map<char, char> _map;
//
//        int size = s.size();
//        for (int i = 0; i < size; i++)
//        {
//            int it = _map.count(s[i]);
//            if ( it == 0)
//            {
//                _map[s[i]] = t[i];
//            }
//            else
//            {
//                if (_map[s[i]] != t[i])
//                    return false;
//            }
//            
//        }
//
//        return true;
//    }
//};
//
//int main()
//{
//    Solution::isIsomorphic("badc", "baba");
//    return 0;
//}


//
//class Solution {
//public:
//    /*static int removeElement(vector<int>& nums, int val) {
//
//        int right = (int)(nums.size() - 1);
//        int left = 0;
//        int  k = 0;
//        while (right > left)
//        {
//
//            k++;
//            if (nums[left] == val)
//            {
//                while (nums[right] == val && right > left)
//                {
//                    right--;
//                }
//
//                std::swap(nums[left], nums[right]);
//
//                left++;
//
//                continue;
//            }
//            left++;
//        }
//
//        return k;
//
//    }*/
//
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//
//        nums1.emplace_back(nums2.begin(), nums2.end());
//
//        sort(nums1.begin(), nums1.end());
//    }
//};
//
//
//int main()
//{
//  /*  vector<int> nums = { 0,1,2,2,3,0,4,2 };
//    std::cout << Solution::removeElement(nums, 2) << std::endl;*/
//
//
//    return 0;
//}
//
//struct ListNode
//{
//	int val;
//	ListNode* _next;
//};
//
//ListNode* reverseList(ListNode* head) {
//
//	ListNode* temp = head;
//	ListNode* prev = nullptr;
//
//	while (temp->_next != nullptr)
//	{
//		ListNode* next = temp->_next;
//
//		temp->_next = prev;
//		prev = temp;
//		temp = next;
//
//	}
//
//	return head;
//}
//
////
////ListNode* removeElements(ListNode* head, int val) {
////    ListNode* temp = head;
////    ListNode* prev = nullptr;
////
////    while (temp != nullptr) {
////        if (temp->val == val) {
////            ListNode* cur = temp->next; 
////            delete temp;              
////            if (prev == nullptr) {  
////                head = cur;
////            }
////            else {
////                prev->next = cur;      
////            }
////            temp = cur;            
////        }
////        else {
////            prev = temp;            
////            temp = temp->next;          
////        }
////    }
////
////    return head;
////}

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

//bool isUnivalTree(TreeNode* root) {
//    if (!root)
//    {
//        return true;
//    }
//
//    if (root->right) {
//        if (root->val != root->right->val || !isUnivalTree(root->right))
//            return false;
//        //isUnivalTree(root->right); //忽略往下传递的bool值
//    }
//
//    if (root->left) {
//        if (root->val != root->left->val || !isUnivalTree(root->left))
//            return false;
//
//    }
//
//    return true;
//}



//bool isSameTree(TreeNode* p, TreeNode* q) {
//	if (p == nullptr && q == nullptr)
//		return true;
//	else if (p == nullptr || q == nullptr)
//		return false;
//	else if (p->val != q->val)
//		return false;
//	else
//		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//
//}

//bool isSame(TreeNode* p, TreeNode* q)
//{
//	if (p == nullptr && q == nullptr)
//		return true;
//	else if (p == nullptr || q == nullptr)
//		return false;
//	else if (p->val != q->val)
//		return false;
//	else
//		return isSame(p->left, q->right) && isSame(p->right, q->left);
//}
//
//bool isSymmetric(TreeNode* root) {
//
//	if (root)
//		return;
//	return isSame(root->left, root->right);
//}
#include <stack>
//vector<int> preorderTraversal(TreeNode* root) {
//
//	vector<int> n;
//
//	if (root == nullptr)
//		return n;
//
//	//非递归
//	stack<TreeNode*> sk;
//	TreeNode* node = root;
//	while (!sk.empty() || node != nullptr)
//	{
//		while (node != nullptr)
//		{
//			n.push_back(node->val);
//			sk.push(node); //把本身加进去
//
//			node = node->left;
//		}
//
//		node = sk.top();
//		sk.pop();
//		node = node->right;
//
//
//	}
//	return n;
//}


//vector<int> inorderTraversal(TreeNode* root) {
//	vector<int> n;
//
//	if (root == nullptr)
//		return n;
//
//	//非递归
//	stack<TreeNode*> sk;
//	TreeNode* node = root;
//
//	while (!sk.empty() || node != nullptr)
//	{
//		while (node)
//		{
//			sk.push(node);
//			node = node->left;
//		}
//
//		node = sk.top();
//		sk.pop();
//		n.push_back(node->val);
//
//		node = node->right;
//	}
//
//	return n;
//
//}

//#include<queue>
//
//vector<vector<int>> levelOrder(TreeNode* root) {
//    vector<vector<int>> result;
//    if (root == nullptr)
//        return result;
//
//    queue<TreeNode*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int size = q.size();
//        vector<int> tier;
//
//        for (int i = 0; i < size; ++i) {
//            TreeNode* node = q.front();
//            q.pop();
//            tier.push_back(node->val);
//
//            if (node->left)
//                q.push(node->left);
//            if (node->right)
//                q.push(node->right);
//        }
//
//        result.push_back(tier);
//    }
//
//    return result;
//}
//
//bool inorderTraversal(TreeNode* root) {
//	int n = INT_MIN;
//
//	if (root == nullptr)
//		return false;
//
//	//非递归
//	stack<TreeNode*> sk;
//	TreeNode* node = root;
//
//	while (!sk.empty() || node != nullptr)
//	{
//		while (node)
//		{
//			sk.push(node);
//			node = node->left;
//		}
//
//		node = sk.top();
//		sk.pop();
//		if (node->val <= n)
//			return false;
//		std::swap(n, node->val);
//
//		node = node->right;
//	}
//
//	return true;
//
//}
//
//bool isValidBST(TreeNode* root) {
//	return inorderTraversal(root);
//}

//#include <queue>
//
//vector<int> inorderTraversal(TreeNode* root) {
//	vector<int> n;
//
//	if (root == nullptr)
//		return n;
//
//	//非递归
//	stack<TreeNode*> sk;
//	TreeNode* node = root;
//
//	while (!sk.empty() || node != nullptr)
//	{
//		while (node)
//		{
//			sk.push(node);
//			node = node->left;
//		}
//
//		node = sk.top();
//		sk.pop();
//		n.push_back(node->val);
//
//		node = node->right;
//	}
//
//	return n;
//
//}
//
//
//struct Less
//{
//	bool operator()(const int& p1, const int& p2)
//	{
//		return p1 < p2;
//	}
//};
//
//
//int kthSmallest(TreeNode* root, int k) {
//	priority_queue<int, deque<int>,Less()> heap;
//
//	vector<int> n = inorderTraversal(root);
//
//	for (const auto& e : n)
//	{
//		if (heap.size() < k)
//			heap.push(e);
//
//		if (e < heap.top())
//		{
//			heap.push(e);
//			heap.pop();
//		}
//	}
//
//	
//	return heap.top();
//	
//}
//
//
//int main()
//{
//
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//// 去掉空行的辅助函数
//int remove_empty_lines(char* lines[], int count, char* result[]) {
//    int index = 0;
//    for (int i = 0; i < count; i++) {
//        if (lines[i][0] != '\0' && strspn(lines[i], " \t\r\n") != strlen(lines[i])) {
//            result[index++] = lines[i];
//        }
//    }
//    return index;
//}
//
//// 比较文本块的函数
//const char* compare_text_blocks(char* input_lines[], int total_lines) {
//    // 找到标志行 "strA 4 strB 5"
//    int marker_index = -1;
//    for (int i = 0; i < total_lines; i++) {
//        if (strcmp(input_lines[i], "strA 4 strB 5") == 0) {
//            marker_index = i;
//            break;
//        }
//    }
//    if (marker_index == -1 || total_lines < marker_index + 9) {
//        return "Error: Invalid input format or insufficient lines.";
//    }
//
//    // 分割文本块
//    char* block_a[4];
//    char* block_b[4];
//    for (int i = 0; i < 4; i++) {
//        block_a[i] = input_lines[marker_index + 1 + i];
//        block_b[i] = input_lines[marker_index + 5 + i];
//    }
//
//    char* filtered_a[4];
//    char* filtered_b[4];
//    int len_a = remove_empty_lines(block_a, 4, filtered_a);
//    int len_b = remove_empty_lines(block_b, 4, filtered_b);
//
//    if (len_a != len_b) {
//        return "strA != strB";
//    }
//    for (int i = 0; i < len_a; i++) {
//        if (strcmp(filtered_a[i], filtered_b[i]) != 0) {
//            return "strA != strB";
//        }
//    }
//    return "strA==strB";
//}




vector<int> path;
vector<vector<int>> ret;

void traceback(vector<int>& nums, vector<int>& res)
{
	if (path.size() == nums.size())
		ret.push_back(path);


	for (int i = 0; i < nums.size(); i++)
	{
		if (res[i] == 0)
		{
			path.push_back(nums[i]);
			res[i] = 1;

			//回溯
			traceback(nums, res);
			path.pop_back();

			res[i] == 0;
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> res(nums.size());

    traceback(nums, res);

    return ret;
}








