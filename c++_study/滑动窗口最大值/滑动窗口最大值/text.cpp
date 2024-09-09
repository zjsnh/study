#include<iostream>
using namespace std;
#include<queue>

struct com
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		return p1.first < p2.first;
	}
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> Nums;
	priority_queue<pair<int, int>, deque<pair<int, int>>, com > PQ;
	for (int i = 0; i < k; i++)
	{
		PQ.push(make_pair(nums[i], i));
	}

	Nums.push_back(PQ.top().first);
	for (int i = k; i <= nums.size(); i++)
	{
		
		PQ.emplace(nums[i], i);
		while (PQ.top().second < i - k)
		{
			PQ.pop();
		}
		Nums.push_back(PQ.top().first);
	}

	return Nums;
}

int main()
{
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	maxSlidingWindow(nums, k);

	return 0;
}