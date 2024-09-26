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
//	int flag = 1;// -> 1  µÝÔö  -1  µÝ¼õ
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

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    int size;
    cin >> size; 

    if (size == 1) 
    {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int num = 0; 
    int direction = 0; 

    int flag = 1;
    for (int i = 1; i < size; i++)
    {
        flag = 1;

        if (v[i] == v[i - 1]) 
        {
            continue;
        }

        int new_direction = (v[i] > v[i - 1]) ? 1 : -1; 

        if (new_direction != direction )
        {
            flag = 0;
        }

        if(flag)
        {
            num++;
            direction = new_direction; 
        }
    }

    cout << num << endl;
    return 0;
}
