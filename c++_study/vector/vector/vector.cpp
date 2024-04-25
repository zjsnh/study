#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> vv(numRows);

	for (int i = 0; i < numRows; i++)
	{
		vv[i].resize(i + 1, 1);
	}

	for (int i = 2; i < numRows; i++)
	{
		for (int j = 1; j < i; j++)
		{
			vv[i][j] = vv[i - 1][j] + vv[i-1][j - 1];
		}
	}

	return vv;
}


int main()
{
	vector<vector<int>> W = generate(8);

	/*for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < W[i].size(); i++)
		{
			cout << W[i][j];
		}
	}*/

	for (int i = 0; i < W.size(); i++)
	{
		for (int j = 0; j < W[i].size(); j++)
		{
			cout << W[i][j]<<" ";
			
		}
		cout << endl;
	}

	

	return 0;

}