 // ����ͷ�ļ�
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <utility>


/*  
	topic:����ˮ���� 
	URL: https://leetcode-cn.com/problems/lemonade-change/
 */

bool lemonadeChange(vector<int>& bills) {

	if (bills[0] != 5)
		return false;
	// ֻ�� 5 �� 10���ܽ������� ,ͬʱ����ʹ�ýϴ�����������

	int five = 0;
	int ten = 0;

	for (int i = 0; i < bills.size(); i++)
	{
		if (bills[i] == 5)
			five++;
		else if (bills[i] == 10)
		{
			if (five == 0)
				return false;
			five--;
			ten++;
		}
		else
		{
			if (ten > 0 && five > 0)
			{
				ten--;
				five--;
			}
			else if (five >= 3)
			{
				five -= 3;
			}
			else
				return false;
		}
	}

	return true;

}


/*
	topic:�������������ٲ�������
	URL: https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
*/

int halveArray(vector<int>& nums) {

	// priority_queue  С��

	priority_queue<double> q;
	double sum = 0.0;
	for (auto num : nums)
	{
		q.push(num);
		sum += num;
	}

	double half = sum / 2.0;
	int res = 0;

	while (half > 0)
	{
		double t = q.top() / 2.0;
		q.pop();
		half -= t;
		q.push(t);
		res++;
	}

	return res;
}


/*
	topic:�����
	URL: https://leetcode-cn.com/problems/largest-number/
*/

// ȷ���������

bool cmp(string& a, string& b)
{
	return a + b >= b + a;
}


//����
void quickSort(vector<string>& str, int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	string key = str[left];
	while (i < j)
	{
		while (i < j && str[j] + key >= key + str[j])
			j--;
		str[i] = str[j];
		while (i < j && str[i] + key <= key + str[i])
			i++;
		str[j] = str[i];
	}
	str[i] = key;
	quickSort(str, left, i - 1);
	quickSort(str, i + 1, right);
}

string largestNumber(vector<int>& nums) {
	vector<string> str;
	for (auto num : nums)
	{
		str.push_back(to_string(num));
	}

	/*sort(str.begin(), str.end(), 
		[](string& a, string& b)
			{return a + b > b + a; });*/
	// �ĳ� ��дsort
	quickSort(str, 0, str.size() - 1);

	string res;
	for (auto s : str)
	{
		res += s;
	}
	if (res[0] == '0')
		return "0";
	return res;
}



/*
	topic:�ڶ�����
	URL: https://leetcode-cn.com/problems/wiggle-subsequence/
*/