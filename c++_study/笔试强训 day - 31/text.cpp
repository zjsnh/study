//#include<iostream>
//using namespace std;
//#include<string>
//
//using ll = long long;
//
//
//bool precondition(const string& s,int& num)
//{
//	if (s.size() < 2)
//	{
//		return false;
//	}
//
//	for (auto& e : s)
//	{
//		num += e - '0';
//	}
//
//	if (num % 2 != 0)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//ll dp[19][163] = { 0 };
//
//int main()
//{
//	ll n;
//	cin >> n;
//	string s = to_string(n);
//
//	int num = 0;
//
//	if (!precondition(s,num))
//	{
//		cout << "NO" << endl;
//		return 0;
//	}
//	
//
//	for (int i = 1; i < s.size(); i++)
//	{
//		for (int j = 0; j <= num / 2; j++)
//		{
//
//			if (j - (s[i] - '0') >= 0)
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - (s[i] - '0')] + (s[i] - '0'));
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//
//	if (dp[s.size()-1][num/2] == num / 2)
//	{
//		cout << "YES" << endl;
//		
//	}
//	else
//	{
//		cout << "NO" << endl;
//	}
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//    int num = 0;
//    cin >> num;
//
//    while (num--) {
//        int pNumber, a, b;
//        cin >> pNumber >> a >> b;
//
//        int low_Price = (3 * a <= 2 * b) ? a : b;
//        int combo_size = (low_Price == a) ? 2 : 3;
//
//        int price = (pNumber / combo_size) * low_Price;
//        int residual = pNumber % combo_size;
//
//        //判断最后的值选2或者3的组合
//        if (residual != 0) {
//            if (combo_size == 3) {
//                price += min(residual * a, b);
//            }
//            else {
//                price += (residual == 1) ? a : min(2 * a, b);
//                price -= a;  
//            }
//        }
//
//        cout << price << endl;
//    }
//
//    return 0;
//}


#include<iostream>
using namespace std;
#include<queue>
#include<cstdbool>

struct more
{
	bool operator()(const int& p1, const int& p2)
	{
		return p1 > p2;
	}
};


int main()
{
	int n, k;
	cin >> n >> k;
	priority_queue<int,vector<int>,more> _d;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		_d.push(a);
	}

	int tolerate = 0;
	int days = 0;
	while (tolerate < k)
	{
		if (tolerate + _d.top() < k)
		{
			days++;
			tolerate += _d.top();

			int top = _d.top();
			_d.pop();
			_d.push(top*2);
		}
		else
		{
			break;
		}
	}

	cout << days << endl;

	return 0;
}