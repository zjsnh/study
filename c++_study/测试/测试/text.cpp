#include <iostream>
using namespace std;

void _merge_sort(int* temp, int* data, int begin, int end)
{
	if (end == begin)
		return;

	int mid = (begin + end) / 2;

	_merge_sort(temp, data, begin, mid);
	_merge_sort(temp, data, mid + 1, end);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	int i = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (data[begin1] < data[begin2])
		{
			temp[i++] = data[begin1++];
		}
		else
		{
			temp[i++] = data[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		temp[i++] = data[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = data[begin2++];
	}

	memcpy(data + begin, temp + begin, sizeof(int) * (end - begin + 1));//赋值到原数组

}

int main() {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int* temp = new int[n];
	_merge_sort(temp, arr, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
	}
	return 0;

}