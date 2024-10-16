//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	string str;
//	cin >> str;
//	int num = 1;
//
//	int sn = 0;
//	for (int i = 0; i < 11; i++)
//	{
//		if (str[i] == '-')
//			continue;
//
//		sn += (str[i] - '0') * num;
//		num++;
//	}
//
//	sn %= 11;
//	char _sn = sn == 10 ? 'X' : (sn + '0');
//	if (str[12] != _sn)
//	{
//		str[12] = _sn;
//		cout << str << endl;
//	}
//
//
//	cout << "Right" << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//#include<set>  
//
//using namespace std;
//
//// y , x
//void BFS_maze(const vector<string>& _maze, pair<int, int> _location) {
//    vector<string> _maze_mirror = _maze;
//    set<pair<int, int>> outlet;  
//
//    vector<pair<int, int>> trend = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
//    queue<pair<int, int>> _bfs;
//    _bfs.push(_location);
//    _maze_mirror[_location.first][_location.second] = '*';  
//    int step = 0;
//    int _step = 0;
//    while (!_bfs.empty()) {
//        int cycles = _bfs.size(); 
//        _step++; 
//        for (int _cycle = 0; _cycle < cycles; _cycle++) {
//            pair<int, int> pos = _bfs.front();
//            _bfs.pop();
//
//            for (int i = 0; i < 4; i++) {
//                pair<int, int> _pos(pos.first + trend[i].first, pos.second + trend[i].second);
//
//                if (_pos.first >= 0 && _pos.first < _maze.size()  
//                    && _pos.second >= 0 && _pos.second < _maze[0].size()
//                    && _maze_mirror[_pos.first][_pos.second] != '*'
//                    && _maze[_pos.first][_pos.second] != '*') {
//
//                    if (_maze[_pos.first][_pos.second] == 'e') {  
//
//                        if (step == 0)
//                        {
//                            step = _step;
//                        }
//
//                        outlet.insert(_pos);  
//                        continue; 
//                    }
//
//                    _bfs.push(_pos); 
//                    _maze_mirror[_pos.first][_pos.second] = '*';  
//                }
//            }
//        }
//    }
//
//
//    if (!outlet.empty()) {
//        cout << outlet.size() << " " << step - 1 << endl; 
//    }
//    else {
//        cout << -1 << endl;  
//    }
//}
//
//
//pair<int, int> loc(const vector<string>& _maze) {
//    for (int i = 0; i < _maze.size(); i++) {
//        for (int j = 0; j < _maze[i].size(); j++) {
//            if (_maze[i][j] == 'k') {
//                return pair<int, int>(i, j); 
//            }
//        }
//    }
//    return pair<int, int>();  
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<string> maze(n);
//    for (int i = 0; i < n; i++) {
//        cin >> maze[i];
//    }
//
//    BFS_maze(maze, loc(maze));  
//
//    return 0;
//}

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>  

using namespace std;

vector<pair<int, int>> trend = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int DFS(const vector<vector<int>>& matrix, vector<vector<int>>& dp, pair<int, int> pos) {
    int i = pos.first, j = pos.second;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int max_len = 1;  

    for (auto& t : trend) {
        int x = i + t.first;
        int y = j + t.second;

        if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
            max_len = max(max_len, 1 + DFS(matrix, dp, { x, y }));
        }
    }

    dp[i][j] = max_len;  
    return dp[i][j];
}

int solve(vector<vector<int> >& matrix)
{
    int result = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
            result = max(result, DFS(matrix, dp, { i, j }));
		}
	}

    return result;
}