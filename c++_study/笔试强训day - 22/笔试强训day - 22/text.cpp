#include<iostream>
using namespace std;
#include<string>



//abe
//cabc

//int main()
//{
//	string _str("abe");
//	string str("cabc");
//
//	string variable;
//	int m = 0;
//	for (int i = _str.size(); i > 0; i--)
//	{
//		variable = _str.substr(0, i);
//
//		//int a = str.find(variable);
//		if (str.find(variable) != -1)
//		{
//			m = _str.size() - i;
//			break;
//		}
//	}
//	cout << m << endl;
//	return 0;
//}

//int main()
//{
//	/*string _str;
//	string str;*/
//
//	string _str("abe");
//	string str("cabc");
//
//	int m = 51;
//	int n = 0;
//	for (int i = 0; i <= str.size()-_str.size(); i++)
//	{
//		n = 0;
//		for (int j = 0; j < _str.size(); j++)
//		{
//			if (n > m)
//			{
//				continue;
//			}
//
//			if (i + j < str.size() && str[i + j] != _str[j])
//			{
//				n++;
//			}
//		}
//
//		m = min(m, n);
//	}
//
//	cout << m << endl;
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//int main() {
//
//    int size;
//    cin >> size;
//    int b;
//    vector<int> V;
//    while (cin >> b) {
//        V.push_back(b);
//    }
//
//    sort(V.begin(), V.end());
//
//    for (int i = 0; i < V.size(); i++) {
//
//        if (V[V.size() - 1] % V[i])
//        {
//            cout << "NO" << endl;
//            return 0;
//        }
//
//        if (((V[V.size() - 1] / V[i]) & ((V[V.size() - 1] / V[i]) - 1))) {
//            cout << "NO" << endl;
//            return 0;
//        }
//    }
//
//    cout << "YES" << endl;
//    return 0;
//}

#include<vector>
#include<algorithm>

const int M = 1e4 + 10;
int dp[35][M];

int main()
{

	int n, v;
	cin >> n >> v;

	vector<int> V(v + 1);
	for (int i = 1; i <= v; i++)
	{
		cin >> V[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			dp[i][j] = dp[i - 1][j];
			//j ÊÇÌå»ý

			if (v - dp[i - 1][j - V[i]])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + V[i]);
			}
		}
	}

	cout << v - dp[n][v] << endl;

	return 0;
}