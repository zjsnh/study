//#include<iostream>
//using namespace std;
//#include<queue>

//int maxPathSum(TreeNode* root) {
//    // write code here
//
//    if (root == nullptr)
//        return -1;
//
//    // num -> 记录循环到当前的最大值 初始值为 0
//    // _num -> 记录循环到当前的所有值的 总和 
//    queue<TreeNode*> _root;
//    _root.push(root);
//
//    int num = 0;
//    int _num = 0;
//    while (!_root.empty())
//    {
//        int n = _root.size();
//
//        for (int i = 0; i < n; i++)
//        {
//            _num += _root.front()->val;
//            num = max(_num, num);
//
//            if (_root.front()->left)
//                _root.push(_root.front()->left);// -> 子   左右必须选一边   numleft  numright —> 递归
//
//            if (_root.front()->right)
//                _root.push(_root.front()->right);
//
//            _root.pop();
//        }
//
//    }
//
//
//}

//#include <algorithm>  // for std::max
//#include <queue>      // for priority_queue
//#include <vector>     // for std::vector
//
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//
// struct more {
//     bool operator()(int p1, int p2) {
//         return p1 < p2;  
//     }
// };
//
///* int maxPath(TreeNode* root, std::priority_queue<int, std::vector<int>, more>& num)*/ 
// int maxPath(TreeNode* root, int& num) {
//
//     int left_max = 0, right_max = 0;
//
//     if (root->left)
//         left_max = maxPath(root->left, num);
//
//     if (root->right)
//         right_max = maxPath(root->right, num);
//
//     priority_queue<int,vector<int>,more> _max_sum;
//     int flag = -1;
//
//     _max_sum.push(root->val);
//
//     if (root->left)
//     {
//         _max_sum.push(left_max + root->val);
//         _max_sum.push(left_max);
//         flag++;
//     }
//
//     if (root->right)
//     {
//         _max_sum.push(right_max + root->val);
//         _max_sum.push(right_max);
//         flag++;
//     }
//
//     if (flag)
//     {
//         _max_sum.push(left_max + root->val + right_max);
//     }
//        
//     
//     //num.push(Max);
//     num = max(_max_sum.top(), num);
//
//     return std::max(left_max + root->val, std::max(right_max + root->val, root->val));
// }
//
// int maxPathSum(TreeNode* root) {
//     if (!root) return 0;  
//
//     int num = -0xfffffff;
//     maxPath(root, num);
//
//     return num;
// }
//
//
//int main()
//{
//
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//    root->left = nullptr;
//    root->val = -2;
//    root->right = (TreeNode*)malloc(sizeof(TreeNode));
//    root->right->left = nullptr;
//    root->right->right = nullptr;
//    root->right->val = -3;
//
//    cout << maxPathSum(root) << endl;
//
//	return 0;
//}




//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//
//using ll = long long;
//int main()
//{
//	int q;
//	while (q--)
//	{
//		ll x;
//		cin >> x;
//		string s = to_string(x);
//
//		int flag = 0;
//
//		char _s;
//		//-> 记录偶数的位置 包括0  我直接选择将偶数放到最后
//		//如果 第一个数是 0 ，让0跟最后一个偶数交换
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (!((s[i] - '0') % 2))
//			{
//				swap(s[i], s[s.size() - 1]);
//				flag = 1;
//				break;
//			}
//		}
//
//		if (s[0] == '0')
//		{
//			swap(s[0], s[s.size() - 1]);
//		}
//
//
//		// string -> ll
//
//		x = atoi(s.c_str());
//		if (flag)
//		{
//			cout << x << endl;
//		}
//
//	}
//
//	return 0;
//}

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
	int n;
	cin >> n;
	int v[15] = { 0 };
	int _v[15] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		_v[i] = i;
	}

	int flag = 0;

	do
	{
		int a = 1;
		for (int i = 1; i <= n; i++)//因为输入的数据比较是按照 1 ~ n
		{
			if (_v[v[i]] < _v[i])
			{
				a = 0;
				break;
			}
		}

		flag += a;


	} while (next_permutation(_v + 1, _v + 1 + n));

	cout << flag << endl;
}