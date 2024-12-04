#include <iostream>
using namespace std;
#include <vector>




//ð������
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

//��������
void insert(vector<int>& arr)
{
	int size = arr.size();

	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];

		int end = i - 1;

		while (end >= 0 && arr[end] > temp)
		{
			arr[end + 1] = arr[end]; //�������
			end--;
		}

		arr[end + 1] = temp; //��ʱend��λ�þ��ǲ����λ��
	}

}


//ϣ������
void shell(vector<int>& arr)
{
	int size = arr.size();
	int gal = size;

	while (gal > 1)
	{
		gal = gal / 3 + 1;
		for (int i = gal; i < size; i++)  //�����ݷ���
		{
			int temp = arr[i];

			int end = i - gal;

			while (end >= 0 && arr[end] > temp)
			{
				arr[end + gal] = arr[end]; //�������
				end -= gal;
			}

			arr[end + gal] = temp; //��ʱend��λ�þ��ǲ����λ��
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

	swap(arr[left], arr[key]);  //������һ������׼���ڵ�λ��

	return left;
}





//�鲢����
//���ˣ�������д


void _sort(int left,int right, vector<int>& arr)
{
	if (left <= right)
	{
		int point = _point(left, right, arr);

		_sort(left, point - 1, arr);
		_sort(point + 1, right, arr);
	}

}

//��������
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





