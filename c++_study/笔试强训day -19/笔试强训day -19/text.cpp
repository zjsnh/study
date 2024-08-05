#include<iostream>
using namespace std;
#include<vector>



//int maxValue(vector<vector<int> >& grid) {
//    // write code here
//
//    int dp[201][201] = { 0 };
//
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[i].size(); j++)
//        {
//
//        
//            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
//        }
//    }
//
//    return dp[grid.size()][grid[0].size()];
//}
//
////[[1,3,1],[1,5,1],[4,2,1]]
//int main()
//{
//    vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
//    cout << maxValue(grid) << endl;
//    return 0;
//}

//#include<algorithm>
//#include<numeric> //C++ 17
//
//int main()
//{
//	int size;
//	cin >> size;
//	long long capacity;
//	cin >> capacity;
//
//	long long fight;
//
//
//	for (int i = 0; i < size; i++)
//	{
//		cin >> fight;
//
//		if (capacity > fight)
//		{
//			capacity += fight;
//		}
//		else
//		{
//			capacity = capacity + gcd(capacity, fight);
//		}
//	}
//
//	cout << capacity << endl;
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int cir;
    cin >> cir; // 输入测试用例数量

    while (cir--) {
        int size;
        cin >> size; // 输入每个测试用例的字符串数量

        vector<string> V(size);
        for (int i = 0; i < size; i++) {
            cin >> V[i]; // 输入每个字符串
        }

        int front = 0;
        int back = size - 1;
        bool common_char_found = false;
        while (back > front) {
            common_char_found = false;

            unordered_set<char> S1(V[front].begin(), V[front].end());
            unordered_set<char> S2(V[back].begin(), V[back].end());

            
            unordered_map<char, int> M;
            for (auto e : S1) {
                M[e]++;
            }

            for (auto e : S2) {
                M[e]++;
            }

            for (auto e : M) {
                if (e.second >= 2) {
                    back--;
                    front++;
                    common_char_found = true;
                    break;
                }
            }

            if (!common_char_found) {
                break;
            }
        }

        if (common_char_found)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }



    return 0;
}
