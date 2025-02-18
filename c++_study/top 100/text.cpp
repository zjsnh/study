
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//bool isPalindrome(string str) {
//
//	int left = 0;
//	int right = str.size() - 1;
//	while (left < right)
//	{
//		if (str[left] != str[right])
//		{
//			return false;
//		}
//		left++;
//		right--;
//	}
//	return true;
//
//}
//
//string longestPalindrome(string s) {
//
//	int length = 0;
//	string str = "";
//	for (int i = 0; i < s.size(); i++)
//	{
//		for (int j = i; j < s.size(); j++)
//		{
//			if (j - i + 1 >= length)
//			{
//				string _str = s.substr(i, j - i + 1);
//				if (isPalindrome(_str))
//				{
//					length = max(length, j - i + 1);
//					str = _str;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//
//	return str;
//}
//
//int main()
//{
//	string str = "cbbd";
//	cout << longestPalindrome(str);
//	return 0;
//}


//int strStr(string haystack, string needle) {
//
//	size_t found = haystack.find(needle);
//
//	return found;
//
//}


//int findMin(vector<int>& nums) {
//
//	int min = 0x7fffffff;
//	
//	// 复杂度 o(logn)
//	int left = 0;
//	int right = nums.size() - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (nums[mid] < min)
//		{
//			min = nums[mid];
//		}
//		if (nums[mid] < nums[right])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//
//	return min;
//}

//// 深度优先
//bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& visited)
//{
//	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
//	{
//		return false;
//	}
//	if (k == word.size() - 1)
//	{
//		return true;
//	}
//	visited[i][j] = true; // 标记为已访问
//
//	//上下左右
//	if (dfs(board, word, i + 1, j, k + 1, visited) 
//		|| dfs(board, word, i - 1, j, k + 1, visited) 
//		|| dfs(board, word, i, j + 1, k + 1, visited) 
//		|| dfs(board, word, i, j - 1, k + 1, visited))
//	{
//		return true;
//	}
//	visited[i][j] = false; // 回溯
//	return false;
//}
//
//
//
//bool exist(vector<vector<char>>& board, string word) {
//
//	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));  // 初始化为false
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[0].size(); j++)
//		{
//			if (dfs(board, word, i, j, 0, visited))
//			{
//				return true;
//			}
//		}
//	}
//
//	return false;
//}



//double myPow(double x, int n) {
//
//	if (n == 0)
//	{
//		return 1;
//	}
//
//	if (n >= 1)
//	{
//		return x * myPow(x, n - 1);
//	}
//	else
//	{
//		return 1 / x * myPow(x, n + 1);
//	}
//}
//
//
//int main()
//{
//
//	std::cout << myPow(2, 10);
//
//	return 0;
//}


//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//
//	vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
//
//	for (int i = 1; i <= obstacleGrid.size(); i++)
//	{
//		for (int j = 1; j <= obstacleGrid[0].size(); j++)
//		{
//			if (obstacleGrid[i - 1][j - 1] == 1)
//			{
//				dp[i][j] = 0;
//			}
//			else
//			{
//				if (i == 1 && j == 1)
//				{
//					dp[i][j] = 1;
//				}
//				else
//				{
//					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//				}
//			}
//		}
//	}
//
//	return dp[obstacleGrid.size()][obstacleGrid[0].size()];
//}



//int searchInsert(vector<int>& nums, int target) {
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] >= target)
//		{
//			return i;
//		}
//	}
//
//	return nums.size();
//}

//void _gridToZero(vector<vector<char>>& grid, vector<vector<char>>& _grid, int i, int j)
//{
//	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || _grid[i][j] == '1')
//	{
//		return;
//	}
//	_grid[i][j] = '1';
//	_gridToZero(grid, _grid, i + 1, j);
//	_gridToZero(grid, _grid, i - 1, j);
//	_gridToZero(grid, _grid, i, j + 1);
//	_gridToZero(grid, _grid, i, j - 1);
//}
//
//
//int numIslands(vector<vector<char>>& grid) {
//	vector<vector<char>> _grid(grid.size(), vector<char>(grid[0].size(), '0'));
//	int num = 0;
//
//	for (int i = 0; i < grid.size(); i++)
//	{
//		for (int j = 0; j < grid[0].size(); j++)
//		{
//			if (grid[i][j] == '1' && _grid[i][j] == '0')
//			{
//				num++;
//				_gridToZero(grid, _grid, i, j);
//			}
//		}
//	}
//
//	return num;
//
//}

//int main()
//{
//	vector<vector<char>> grid = { {'1','1','1','1','0'},
//								  {'1','1','0','1','0'},
//								  {'1','1','0','0','0'},
//								  {'0','0','0','0','0'} };
//
//	cout << numIslands(grid);
//
//
//	return 0;
//}

//void spiral(const vector<vector<int>>& matrix, vector<vector<int>>& _matrix, vector<int>& res, int dir)
//{
//	vector<int> dx = { 0, 1, 0, -1 };
//	vector<int> dy = { 1, 0, -1, 0 };
//
//	int x = 0;
//	int y = 0;
//
//	// 右 下 左 上
//
//	for (int i = 0; i < matrix.size() * matrix[0].size(); i++)
//	{
//		res.push_back(matrix[x][y]);
//		_matrix[x][y] = 1;
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() || _matrix[nx][ny] == 1)
//		{
//			dir = (dir + 1) % 4;
//			nx = x + dx[dir];
//			ny = y + dy[dir];
//		}
//		x = nx;
//		y = ny;
//	}
//
//
//}
//
//
//vector<int> spiralOrder(vector<vector<int>>& matrix) {
//
//	vector<int> res;
//	vector<vector<int>> _matrix(matrix.size(), vector<int>(matrix[0].size(), 0));
//
//	// 右 下 左 上
//	spiral(matrix, _matrix, res, 0);
//	return res;
//}


//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
 
//void reverse(ListNode* head, ListNode* tail)
//{
//	ListNode* prev = nullptr;
//	ListNode* cur = head;
//	while (cur != tail)
//	{
//		ListNode* next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//}
//
//ListNode* rotateRight(ListNode* head, int k) {
//
//	int num = 0;
//	ListNode* cur = head;
//	while (cur != nullptr)
//	{
//		num++;
//		cur = cur->next;
//	}
//
//	k = k % num;
//	int m = num - k;
//
//	// 第一部分 1 - m
//	ListNode* first = head;
//	ListNode* first_tail = head;
//	for (int i = 0; i < m - 1; i++)
//	{
//		first_tail = first_tail->next;
//	}
//
//	// 第二部分 m+1 - num
//	ListNode* second = first_tail->next;
//	ListNode* second_tail = head;
//	for (int i = 0; i < k - 1; i++)
//	{
//		second_tail = second_tail->next;
//	}
//
//	// 旋转
//	reverse(first, first_tail);
//	reverse(second, second_tail);
//	reverse(first, second_tail);
//
//	return head;
//}


int hIndex(vector<int>& citations) {

	sort(citations.begin(), citations.end());
	int first = 0;
	int last = citations.size() - 1;

	return citations[first + (last - first) / 2];
}