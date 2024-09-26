//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//void combin(ll n, ll m, ll& num)
//{
//	if ((m-1) == 0)
//		return;
//
//	num *= (m - 1) * (n - 1);
//	combin(n - 1, m - 1, num);
//}
//
//int main()
//{
//	ll n, m;
//	cin >> n >> m;
//
//	if (m > n)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	//从n个中取m个  
//	ll num = 1;
//	combin(n, m, num);
//
//	num *= n;
//	cout << num % 109 << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//ll perm(ll n, ll m) {
//    if (m > n) return 0; 
//    ll num = 1;
//    for (ll i = 0; i < m; i++) {
//        num *= (n - i);
//        num%=109
//    }
//    return num;
//}
//
//int main() {
//    ll n, m;
//    cin >> n >> m;
//
//    cout << perm(n, m) << endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct _less {
//    bool operator()(const vector<int>& v1, const vector<int>& v2) {
//        return v1[0] < v2[0];
//    }
//};
//
//void compere_insert(vector<vector<int>>& compere, const vector<int>& time) {
//    bool flag = true;
//    for (int i = 0; i < compere.size(); i++) {
//
//        if (compere[i].back() >= time[0]) {
//            compere[i].push_back(time[1]);
//            flag = false;
//            break;
//        }
//    }
//
//
//    if (flag) {
//        compere.push_back({ time[0], time[1] });
//    }
//}
//
//int minmumNumberOfHost(int n, vector<vector<int>>& startEnd) {
//    sort(startEnd.begin(), startEnd.end(), _less());
//
//    vector<vector<int>> compere;
//
//    if (!startEnd.empty()) {
//        compere.push_back(startEnd[0]);
//    }
//
//    for (int i = 1; i < startEnd.size(); i++) {
//        compere_insert(compere, startEnd[i]);
//    }
//
//    return compere.size();
//}
//
//int main()
//{
//    return 0;
//}


//
//
//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>

//int _min(int p1, int p2, int p3, int p4)
//{
//	int p1 = min(p1, p2);
//	int p2 = min(p3, p4);
//
//	return min(p1, p2);
//}
//
//int dfs(const vector<string>& v_s,int x,int y, int path, int trend)
//{
//	if (x == 5 && y == 5)
//	{
//		return path;
//	}
//
//	int p1, p2, p3, p4;
//	
//	if (x - 1 > 0 && trend != -2 && v_s[x - 1][y] != '*') {
//
//		p1 = dfs(v_s, x - 1, y, path + 1, 2);
//	}
//	
//
//	if (y + 1 > 0 && trend != -1 && v_s[x][y + 1] != '*'){
//		p2 = dfs(v_s, x, y + 1 , path + 1, 1);
//
//	}
//
//	if (x + 1 > 0 && trend != 2 && v_s[x + 1][y] != '*'){
//		p3 = dfs(v_s, x + 1, y, path + 1, -2);
//	}
//
//	if (y - 1 > 0 && trend != 1 && v_s[x][y - 1] != '*'){
//		p4 = dfs(v_s, x, y - 1, path + 1, -1);
//	}
//
//
//	// 上下左右  
//
//	return _min(p1, p2, p3, p4);
//	 
//}

//int dfs(const vector<string>& v_s, int x, int y, int path, vector<string>& path_board)
//{
//	if (x == 5 && y == 5)
//	{
//		return path;
//	}
//
//	int p1, p2, p3, p4;
//		
//	if (x - 1 > 0 && !path_board[x-1][y] && v_s[x - 1][y] != '*') {
//		path_board[x - 1][y] = 1;
//		p1 = dfs(v_s, x - 1, y, path + 1, path_board);
//	}
//		
//	
//	if (y + 1 > 0 && trend != -1 && v_s[x][y + 1] != '*'){
//		p2 = dfs(v_s, x, y + 1 , path + 1, 1);
//	
//	}
//	
//	if (x + 1 > 0 && trend != 2 && v_s[x + 1][y] != '*'){
//		p3 = dfs(v_s, x + 1, y, path + 1, -2);
//	}
//	
//	if (y - 1 > 0 && trend != 1 && v_s[x][y - 1] != '*'){
//		p4 = dfs(v_s, x, y - 1, path + 1, -1);
//	}
//
//}
//
//
//int main()
//{
//	vector<string> v_s;
//	int size = 0;
//	cin >> size;
//
//	int m = 0;
//	cin >> m;
//
//	v_s.resize(size);
//	for (int i = 0; i < size; i++)
//	{
//		cin >> v_s[i];
//	}
//
//	vector<vector<int>> path_board(size);
//
//	for (int i = 0; i < size; i++)
//	{
//		path_board[i].resize(m, 0);
//	}
//
//
//	dfs(v_s,0, 0, 0, 0);
//	// i-1 j-1 i+1 j+1  ->  v_s[i-1][j]  v_s[i][j-1]   v_s[i+1][j]  v_s[i][j+1]
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>

using namespace std;


//int dfs(const vector<string>& v_s, int x, int y, int path, vector<vector<int>>& path_board,const int& endx,const int& endy) {
//    if (x == endx && y == endy) {
//        return path;  
//    }
//
//    int max_path = -1;  
//    path_board[x][y] = 1;  
//
//
//    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
//
//    for (int i = 0; i < 4; i++) {
//        int new_x = x + directions[i][0];
//        int new_y = y + directions[i][1];
//
//        if (new_x >= 0 && new_x < v_s.size() && new_y >= 0 && new_y < v_s[0].size() &&
//            path_board[new_x][new_y] == 0 && v_s[new_x][new_y] != '*') {
//            int result = dfs(v_s, new_x, new_y, path + 1, path_board, endx, endy);
//            if (result > max_path) {
//                max_path = result;  
//            }
//        }
//    }
//
//    path_board[x][y] = 0;  
//    return max_path;  
//}
//
//int main() {
//    int size = 0, m = 0;
//    cin >> size >> m;
//
//    int x1, y1, x2, y2;
//    cin >> x1 >> y1 >> x2 >> y2;
//
//    vector<string> v_s(size);
//    for (int i = 0; i < size; i++) {
//        cin >> v_s[i];
//    }
//
//    vector<vector<int>> path_board(size, vector<int>(m, 0));
//    int result = dfs(v_s, x1 - 1, y1 - 1, 0, path_board, x2 - 1, y2 - 1);
//
//    cout << result << endl;
//
//    return 0;
//}


//int dfs(const vector<string>& v_s, int x, int y, int path, vector<vector<int>>& path_board,const int& endx,const int& endy) {
//    if (x == endx && y == endy) {
//        return path;  
//    }
//
//    int max_path = -1;  
//    path_board[x][y] = 1;  
//
//
//    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
//
//    for (int i = 0; i < 4; i++) {
//        int new_x = x + directions[i][0];
//        int new_y = y + directions[i][1];
//
//        if (new_x >= 0 && new_x < v_s.size() && new_y >= 0 && new_y < v_s[0].size() &&
//            path_board[new_x][new_y] == 0 && v_s[new_x][new_y] != '*') {
//            int result = dfs(v_s, new_x, new_y, path + 1, path_board, endx, endy);
//            if (result > max_path) {
//                max_path = result;  
//            }
//        }
//    }
//
//    path_board[x][y] = 0;  
//    return max_path;  
//}

#include<queue>

int bfs(const vector<string>& v_s,const int& endx, const int& endy, const int& beginx, const int& beginy)
{
    int size = v_s.size();
    int m = v_s[0].size();
    vector<vector<int>> path_board(size, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({ beginx ,beginy });
    // 方向数组，上、右、下、左
    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == endx && y == endy)
        {
            return path_board[endx][endy];
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];

            if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < m &&
                path_board[new_x][new_y] == 0 && v_s[new_x][new_y] != '*') {
                path_board[new_x][new_y] = path_board[x][y] + 1;  // 更新路径长度
                q.push({ new_x, new_y });
            }
        }
    }

    return -1;
}

int main() {
    int size = 0, m = 0;
    cin >> size >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<string> v_s(size);
    for (int i = 0; i < size; i++) {
        cin >> v_s[i];
    }

    vector<vector<int>> path_board(size, vector<int>(m, 0));
    int result = bfs(v_s, x2 - 1, y2 - 1, x1 - 1, y1 - 1);

    cout << result << endl;

    return 0;
}

