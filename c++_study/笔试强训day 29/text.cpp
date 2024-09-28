//#include<iostream>
//using namespace std;
//#include<stack>
//
//using ll = long long;
//
//stack<ll> sum;
//ll compute(ll& H, int& num)
//{
//    ll n = 2;
//    while (H >= n)
//    {
//        H -= n;
//        num++;
//        sum.push(n * 2);
//        n = n + n * 2;
//    }
//    return n;
//}
//
//void _compute(ll& H, int& num)
//{
//
//    while (H > 0)
//    {
//        if (H >= sum.top())
//        {
//            H -= sum.top();
//            num++;
//        }
//        sum.pop();
//    }
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//
//
//
//    while (T--)
//    {
//
//        sum.push(2);
//
//        ll H;
//        cin >> H;
//
//        int num = 0;
//        int flag = 2;
//
//        if ((H - 1) % 2 == 0)
//        {
//            H -= 1;
//            flag = 1;
//        }
//        else
//        {
//            H -= 2;
//            flag = 2;
//        }
//
//        ll n = compute(H, num);
//        _compute(H, num);
//
//        num += flag;
//        cout << num << endl;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<vector>
//
//using ll = long long;
//
//int main()
//{
//	int size;
//	cin >> size;
//
//	vector<ll> v(size);
//	for (int i = 0; i < size; i++)
//	{
//		cin >> v[i];
//	}
//
//	int num = 1;
//	int flag = 1;// -> 1  ����  -1  �ݼ�
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] == v[i - 1])
//		{
//			continue;
//		}
//
//		if (v[i] > v[i - 1])
//		{
//			int _flag = 1;
//			if (flag == _flag)
//			{
//				continue;
//			}
//			else
//			{
//				flag = _flag;
//				num++;
//			}
//		}
//		else
//		{
//			int _flag = -1;
//			if (flag == _flag)
//			{
//				continue;
//			}
//			else
//			{
//				flag = _flag;
//				num++;
//			}
//		}
//
//	}
//
//	cout << num << endl;
//
//	return 0;
//}

//13
//1 1 2 2 1 1 2 2 1 1 2 2 3


#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

//int min_sorted_subsequences(const std::vector<ll>& arr) {
//    if (arr.size() <= 1) return 1;
//
//    int count = 1;
//    int n = arr.size();
//    bool increasing = false;  // �жϵ�ǰ�����ǵ������ǵݼ�
//    bool defined = false;     // �ж��Ƿ��Ѿ�ȷ���˵�ǰ����
//
//    for (int i = 1; i < n; ++i) {
//        if (arr[i] > arr[i - 1]) {
//            // ��ǰ�ǵ���
//            if (defined && !increasing) {
//                count++;  // �ӵݼ���Ϊ�������ֶ�
//                defined = false;  // �������ƶ���
//            }
//            increasing = true;
//            defined = true;
//        }
//        else if (arr[i] < arr[i - 1]) {
//            // ��ǰ�ǵݼ�
//            if (defined && increasing) {
//                count++;  // �ӵ�����Ϊ�ݼ����ֶ�
//                defined = false;  // �������ƶ���
//            }
//            increasing = false;
//            defined = true;
//        }
//        // ��� arr[i] == arr[i - 1]������Ҫ�ı����ƣ���������
//    }
//    return count;
//}

//int main()
//{
//    int size;
//    cin >> size;
//
//    if (size == 1)
//    {
//        cout << 1 << endl;
//        return 0;
//    }
//
//    vector<ll> v(size);
//    for (int i = 0; i < size; i++)
//    {
//        cin >> v[i];
//    }
//
//    //cout << min_sorted_subsequences(v) << endl;
//
//    //int num = 0;
//    //int direction = 0;
//
//    //int flag = 0;
//    //for (int i = 1; i < size; i++)
//    //{
//    //    int new_direction = 0;
//    //    if (v[i] == v[i - 1])
//    //    {
//    //        new_direction = direction;
//    //    }
//    //    else
//    //    {
//    //        if (v[i] > v[i - 1])
//    //        {
//    //            new_direction = 1;
//    //        }
//    //        else
//    //        {
//    //            new_direction = -1;
//    //        }
//
//    //    }
//
//    //    if (new_direction != direction && !flag)//ת����  ->   flag == 1   
//    //    {
//    //        flag = 1;
//    //        continue;
//    //    }
//
//    //    if (flag == 1)
//    //    {
//    //        num++;
//    //        flag = 0;
//    //        direction = new_direction;
//    //    }
//    //}
//
//    //if (flag == 1)
//    //{
//    //    num++;
//    //}
//
//    //cout << num << endl;
//    return 0;
//}




#include<algorithm>
int LIS(vector<int>& a) {
    // write code here

    vector<int> dp;

    for (int i = 0; i < a.size(); i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        if (it == dp.end())
        {
            dp.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }
    }

    return dp.size();
}
