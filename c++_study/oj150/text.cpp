#include <vector>
#include <iostream>

using namespace std;

//bool Reachable(vector<int>& gas, vector<int>& cost,int pos)
//{
//	int count = gas.size();
//	int _gas = gas[pos];
//	while (count--)
//	{
//		_gas -= cost[pos];
//		pos++;
//		pos %= gas.size();
//
//		if (_gas < 0)
//		{
//			return false;
//		}
//
//		_gas += gas[pos];
//
//	}
//
//	return true;
//}


//
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//
//	int nums = 0, tnums = 0, pos = 0;
//
//	for (int i = 0; i < gas.size(); i++)
//	{
//		nums += gas[i] - cost[i];
//		tnums += gas[i] - cost[i];
//
//		if (nums < 0)
//		{
//			nums = 0;
//			pos = i + 1;
//		}
//	}
//
//	if (tnums < 0)
//	{
//		return -1;
//	}
//
//	return pos;
//
//
//}
//
//int main()
//{
//	vector<int> gas = { 1, 2, 3, 4, 5 };
//	vector<int> cost = { 3,4,5,1,2 };
//
//	canCompleteCircuit(gas, cost);
//	return 0;
//}
//
//int lengthOfLastWord(string s) {
//    int pos = s.size() - 1;
//
//
//    while (pos >= 0 && s[pos] == ' ') {
//        pos--;
//    }
//
//    int length = 0;
//    while (pos >= 0 && s[pos] != ' ') {
//        length++;
//        pos--;
//    }
//
//    return length;
//}
//
//int main()
//{
//    cout << lengthOfLastWord("a");
//    return 0;
//}

//int _same(string& str1, string& str2)
//{
//	int same = 0;
//	int size = str1.size();
//	if (str1.size() > str2.size())
//	{
//		size = str2.size();
//	}
//
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (str1[i] == str2[i])
//		{
//			same++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	return same;
//}
//
//
//
//string longestCommonPrefix(vector<string>&strs) {
//	int same = strs[0].size();
//
//	for (int i = 1; i < strs.size(); i++)
//	{
//		same = _same(strs[0], strs[i]);
//		if (same == 0)
//		{
//			return " ";
//		}
//	}
//
//	return strs[0].substr(0, same);
//}

#include<sstream>
//string reverseWords(string s) {
//	std::stringstream ss(s);
//	std::string str;
//
//	std::string temp;
//
//	ss >> temp;
//	reverse(temp.begin(),temp.end());
//	str = temp;
//	while (ss >> temp)
//	{
//		str += " ";
//		reverse(temp.begin(), temp.end());
//		str += temp;
//	} 
//	reverse(str.begin(), str.end());
//
//	return str;
//}

//int Vlaue(char c)
//{
//	switch (c)
//	{
//	case 'I':
//		return 1;
//	case 'V':
//		return 5;
//	case 'X':
//		return 10;
//	case 'L':
//		return 50;
//	case 'C':
//		return 100;
//	case 'D':
//		return 500;
//	case 'M':
//		return 1000;
//	default:
//		return 0;
//	}
//}
//
//int romanToInt(string s) {
//
//	int sum = 0;
//	int pre = Vlaue(s[0]);
//
//	for (int i = 1; i < s.size(); i++)
//	{
//		int cur = Vlaue(s[i]);
//		if (pre < cur)
//		{
//			sum -= pre;
//		}
//		else
//		{
//			sum += pre;
//		}
//		pre = cur;
//
//	}
//	return sum + pre;
//
//}



//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//
//
//	int row = matrix.size();
//	int col = matrix[0].size();
//
//	for (int i = 0; i < row; i++)
//	{
//		if (target <= matrix[i][col - 1])
//		{
//			for (int j = 0; j < col; j++)
//			{
//				if (target == matrix[i][j])
//				{
//					return true;
//				}
//			}
//		}
//	
//	}
//
//	return false;
//
//}

//#include <algorithm>
//
//void _combinationSum(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res)
//{
//	if (target == 0)
//	{
//		res.push_back(path);
//		return;
//	}
//	for (int i = start; i < candidates.size(); i++)
//	{
//		if (target < candidates[i])
//		{
//			break;
//		}
//		path.push_back(candidates[i]);
//		// 不用判断是否已经用过
//		_combinationSum(candidates, target - candidates[i], i, path, res);  // 只需要获取新的target 
//		path.pop_back();
//	}
//}
//
//
//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//
//	vector<vector<int>> res;
//	vector<int> path;
//	sort(candidates.begin(), candidates.end());
//	_combinationSum(candidates, target, 0, path, res);
//	return res;
//}

//void _setZeroes(vector<vector<int>>& matrix, int row, int col)
//{
//	// 上下左右
//
//	//  列
//	for (int i = 0; i < matrix.size(); i++)
//	{
//		if (matrix[i][col] != 0)
//		{
//			matrix[i][col] = 0;
//		}
//	}
//
//	// 行
//	for (int i = 0; i < matrix[0].size(); i++)
//	{
//		if (matrix[row][i] != 0)
//		{
//			matrix[row][i] = 0;
//		}
//	}
//
//}
//
//
//void setZeroes(vector<vector<int>>& matrix) {
//
//	vector<vector<int>> temp = matrix;  //  设置为0之后，需要从temp中获取值
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		for (int j = 0; j < temp[0].size(); j++)
//		{
//			if (temp[i][j] == 0)
//			{
//				_setZeroes(matrix, i, j);
//			}
//		}
//	}
//
//
//}

//
//int singleNumber(vector<int>& nums) {
//
//	int res = 0;
//
//	for (const auto& e : nums)
//	{
//		res ^= e;
//	}
//
//	return res;
//}


bool isPalindrome(string str) {
	
	int left = 0;
	int right = str.size() - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;

}

string longestPalindrome(string s) {

	int length = 0;
	string str = "";
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			if (j - i + 1 > length)
			{
				string _str = s.substr(i, j - i + 1);
				if (isPalindrome(_str))
				{
					length = max(length, j - i + 1);
					str = _str;
				}
			}
			else
			{
				break;
			}
		}
	}
	
	return str;
}

int mian()
{
	string str = "cbbd";
	cout << longestPalindrome(str);
	return 0;
}

