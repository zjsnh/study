#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;




/*
* topic : �ƶ���
* URL: https://leetcode-cn.com/problems/move-zeroes/
*/



void moveZeroes(vector<int>& nums) {

    int fast = 0;
	int slow = 0;

	//  slow��0��λ��
	while (fast < nums.size()) {
		if (nums[fast] != 0) {
			swap(nums[slow], nums[fast]);
			slow++;
		}
		fast++;
	}

	return;

}



/*
* topic : ��д��
* URL: https://leetcode-cn.com/problems/duplicate-zeros/
*/

void duplicateZeros(vector<int>& arr) {

	// ԭ���޸�,�ҵ����һλ��д��λ��
	int n = arr.size();
	int i = 0;

	int count = 0;
	while (i + count < n) {
		if (arr[i] == 0) {
			count++;
		}
		i++;  // i �������һ����д��λ��
	}

	int fast = i;
	int slow = n - 1;

	while (fast >= 0) {
		if (arr[fast] == 0) {
			if (slow < n) {
				arr[slow] = 0;
			}
			slow--;
			if (slow < n) {
				arr[slow] = 0;
			}
		}
		else {
			if (slow < n) {
				arr[slow] = arr[fast];
			}
		}
		fast--;
		slow--;
	}

}




/*
* topic : ������
* URL: https://leetcode-cn.com/problems/happy-number/
*/

int bitSquareSum(int n) {
	int sum = 0;
	while (n > 0) {
		int bit = n % 10;
		sum += bit * bit;
		n /= 10;
	}
	return sum;
}


bool isHappy(int n) {
	int slow = n;
	int fast = n;
	do {
		slow = bitSquareSum(slow);
		fast = bitSquareSum(fast);
		fast = bitSquareSum(fast);
	} while (slow != fast);


	return slow == 1; //�ж�������ʱ�� �Ƿ�Ϊ1
}


/*
* topic : ʢˮ��������
* URL:	https://leetcode-cn.com/problems/container-with-most-water/
*/


int maxArea(vector<int>& height) {

	// ����λ�ö��ڸߵ�λ�ý���ö�٣����һ����С�ģ����Կ�������С��λ�ã������ƶ�

	int l = 0;
	int r = height.size() - 1;
	int max_area = 0;
	while (r > l)
	{
		int area = min(height[l], height[r]) * (r - l);
		max_area = max(max_area, area);
		if (height[l] < height[r]) {
			l++;
		}
		else {
			r--;
		}
	}

	return max_area;

}


/*
* topic : ��Ч�����εĸ���
* URL:	https://leetcode.cn/problems/valid-triangle-number/description/
*/


int triangleNumber(vector<int>& nums) {

	int  n = nums.size();
	int l = n - 1;
	int r = 0;
	int tragial_count = 0;
	sort(nums.begin(), nums.end());

	while (l > r + 1)
	{ // ��֤�����γ������Σ���ʹ���ظ��±�
		int left = r;
		int right = l - 1;
		while (left < right)
		{
			if (nums[left] + nums[right] > nums[l]) {
				tragial_count += right - left;
				right--;
			}
			else {
				left++;
			}
		}
		l--;

	}

	return tragial_count;
}



/*
* topic : ����֮��
* URL:	https://leetcode.cn/problems/3sum/description/
*/


vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> res;
	int n = nums.size();
	if (n < 3) {
		return res;
	}
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < n - 2; i++)
	{

		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int l = i + 1;
		int r = n - 1;

		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (sum == 0) {
				res.push_back({ nums[i], nums[l], nums[r] });

				// ֱ���ҵ���ͬ����
				while (l < r && nums[l] == nums[l + 1]) {
					l++;
				}
				while (l < r && nums[r] == nums[r - 1]) {
					r--;
				}
				l++;
				r--;
			}
			else if (sum < 0) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	return res;


}



/*
* topic : ����֮��
* URL:	https://leetcode.cn/problems/4sum/description/
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {

	vector<vector<int>> res;
	int n = nums.size();
	if (n < 4) {
		return res;
	}
	long long sum = 0;
	long long _target = target;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 3; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < n - 2; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) {
				continue;
			}
			long long aim = _target - nums[i] - nums[j];
			int l = j + 1;
			int r = n - 1;
			while (l < r) {
				sum = nums[l] + nums[r];
				if (sum == aim) {
					res.push_back({ nums[i], nums[j], nums[l], nums[r] });
					while (l < r && nums[l] == nums[l + 1]) {
						l++;
					}
					while (l < r && nums[r] == nums[r - 1]) {
						r--;
					}
					l++;
					r--;
				}
				else if (sum < aim) {
					l++;
				}
				else {
					r--;
				}
			}
		}
	}
	return res;
}



/*
* topic : ������С��������
* URL:	http://leetcode-cn.com/problems/minimum-size-subarray-sum/
*/


int minSubArrayLen(int target, vector<int>& nums) {
	if (nums.size() == 0) {
		return 0;
	}

	int n = nums.size();
	int right = 0;
	int left = 0;

	int len = n + 1;

	int sum = 0;
	;
	while (right < nums.size()) {
		sum += nums[right];
		while (sum >= target) {
			len = min(len, right - left + 1);
			sum -= nums[left];
			left++;
		}
		right++;
	}

	return len == (n + 1) ? 0 : len;
}


/*
* topic : ���ظ��ַ�����Ӵ�
* URL:	http://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/


int lengthOfLongestSubstring(string s) {

	// str_len ��¼��ǰ����ִ�  _str_len ��¼��ǰ���ִ�
	int l = 0;
	int r = 0;
	int str_len = 0;
	int _str_len = 0;

	int n = s.size();

	// find 
	while (r < n) {
		// find the same char
		int n = s.find_first_of(s[r], l);
		if (n < r) {
			_str_len = r - l;
			l = n + 1;
		}
		_str_len++;
		str_len = max(str_len, _str_len);
		r++;
	}

	return str_len;
}


/*
* topic : �� x ���� 0 ����С������
* URL:	https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
*/


int minOperations(vector<int>& nums, int x) {

	int n = nums.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}
	int target = sum - x;
	if (target < 0) {
		return -1;
	}
	if (target == 0) {
		return n;
	}
	int l = 0;
	int r = 0;
	int cur_sum = 0;
	int min_len = n + 1;
	while (r < n) {
		cur_sum += nums[r];
		while (cur_sum > target) {
			cur_sum -= nums[l];
			l++;
		}
		if (cur_sum == target) {
			min_len = min(min_len, r - l + 1);
		}
		r++;
	}
	return min_len == -1 ? -1 : n - min_len;

}


/*
* topic : �����������в���Ԫ�صĵ�һ�������һ��λ��
* URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/


vector<int> searchRange(vector<int>& nums, int target) {

	// ���ֲ���  Ȼ���������Ҳ���

	int n = nums.size();
	int l = 0;
	int r = n - 1;
	int mid = 0;
	vector<int> res = { -1,-1 };
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (nums[mid] == target) {
			break;
		}
		else if (nums[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	if (l > r) {
		return res;
	}

	// �Ҵ���߽�
	int left = mid;
	while (left >= 0 && nums[left] == target) {
		left--;
	}

	res[0] = left + 1;

	// �ҵ��ұ߽�

	int right = mid;
	while (right < n && nums[right] == target) {
		right++;
	}

	res[1] = right - 1;

	return res;
}



	
/*
* topic : ���ֲ����㷨_x ��ƽ����
* URL: https://leetcode-cn.com/problems/sqrtx/
*/

int mySqrt(int x) {

	 // 1 ~ x  mid^2

	int l = 0;
	int r = x;

	int mid = 0;
	int res = 0;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if ((long long)mid * mid <= x) {
			res = mid;  // ��¼��res  ��С�ķ�����
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return res;

}


/*
* topic : ��������λ��
* URL: https://leetcode-cn.com/problems/search-insert-position/
*/


int searchInsert(vector<int>& nums, int target) {

	int n = nums.size();
	int l = 0;
	int r = n - 1;
	int mid = 0;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return l;

}


/*
* topic : ɽ������ķ嶥����
* URL: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
*/

int peakIndexInMountainArray(vector<int>& arr) {

	int n = arr.size();
	int l = 0;
	int r = n - 1;
	int mid = 0;

	// ͨ���ж�mid �� mid+1�Ĵ�С��ϵ�����жϵ�ǰ��ɽ���λ�á�
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] < arr[mid + 1]) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;

}




/*
* topic : Ѱ�ҷ�ֵ
* URL: https://leetcode-cn.com/problems/find-peak-element/
*/

int findPeakElement(vector<int>& nums) {

	// ���
	int n = nums.size();
	int l = 0;
	int r = n - 1;
	int mid = 0;

	// ͨ���ж�mid �� mid+1�Ĵ�С��ϵ�����жϵ�ǰ��ɽ���λ�á�
	while (l < r) {
		mid = l + (r - l) / 2;
		if (nums[mid] < nums[mid + 1]) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;

}



/*
* topic : Ѱ����ת���������е���Сֵ
* URL: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
*/