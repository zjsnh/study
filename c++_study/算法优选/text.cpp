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