#include <iostream>
using namespace std;
#include <vector>




//冒泡排序
void bubble(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}

}

//插入排序
void insert(vector<int>& arr)
{
	int size = arr.size();

	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];

		int end = i - 1;

		while (end >= 0 && arr[end] > temp)
		{
			arr[end + 1] = arr[end]; //数组后移
			end--;
		}

		arr[end + 1] = temp; //此时end的位置就是插入的位置
	}

}


//希尔排序
void shell(vector<int>& arr)
{
	int size = arr.size();
	int gal = size;

	while (gal > 1)
	{
		gal = gal / 3 + 1;
		for (int i = gal; i < size; i++)  //将数据分组
		{
			int temp = arr[i];

			int end = i - gal;

			while (end >= 0 && arr[end] > temp)
			{
				arr[end + gal] = arr[end]; //数组后移
				end -= gal;
			}

			arr[end + gal] = temp; //此时end的位置就是插入的位置
		}



	}

}

int _point(int left, int right, vector<int>& arr)
{
	int key = left;

	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}

		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}

		swap(arr[left], arr[right]);
	}

	swap(arr[left], arr[key]);  //就是找一个个基准所在的位置

	return left;
}





//归并排序
//忘了，明天再写


void _sort(int left,int right, vector<int>& arr)
{
	if (left <= right)
	{
		int point = _point(left, right, arr);

		_sort(left, point - 1, arr);
		_sort(point + 1, right, arr);
	}

}

//快速排序
void sort(vector<int>& arr)
{
	_sort(0, arr.size() - 1, arr);
}


int main()
{
	vector<int> s{ 5,4,7,1,3 };

	//bubble(s);
	//insert(s);
	//shell(s);

	sort(s);
	for (const auto&e : s)
	{
		cout << e << " ";
	}


	return 0;
}





