#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m));
	for (int i = 1; i <= n; i++)
	{
		for (auto& x : v[i])
		{
			cin >> x;
		}
	}

	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			int flag = 0;
			for (int k = 0; k < m; k++)
			{
				flag += (v[i][k] < v[j][k]);
				
			}

			if (flag == m)
				break;
		}
		cout << (j > n ? 0 : j) << endl;
	}

}