#include<iostream>
using namespace std;

//int main()
//{
//	int b = 0;
//	cin >> b;
//
//	while (b--)
//	{
//		pair<int, int> warriors;
//		pair<int, int> fur_ball;
//
//		cin >> warriors.first >> warriors.second;
//		cin >> fur_ball.first >> fur_ball.second;
//
//		int initialize = fur_ball.first;
//		int num = 0;
//
//		int flag = 1;
//		if (warriors.second >= fur_ball.first)
//		{
//			flag = 0;
//		}
//
//		while (warriors.first > 0&& flag)
//		{
//			fur_ball.first -= warriors.second;
//			if (fur_ball.first <= 0)
//			{
//				num++;
//				fur_ball.first = initialize;
//				continue;
//			}
//
//			warriors.first -= fur_ball.second;
//
//		}
//
//		if (flag)
//		{
//			cout << num << endl;
//		}
//		else
//		{
//			cout << -1 << endl;
//		}
//	}
//	
//
//	return 0;
//} 
//
//#include<unordered_map>
//#include<string>
//#include<vector>
//
//bool exist(vector<unordered_map<char, int>>& M, unordered_map<char, int>& _str)
//{
//	bool flag = false;
//	for (auto e : M)
//	{
//		if (e == _str)
//		{
//			flag = true;
//			break;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	vector<unordered_map<char, int>> M;
//	
//	int size = 0;
//	std::cin >> size;
//
//	M.resize(size);
//	string str;
//	int num = 0;
//	while (size--)
//	{
//		std::cin >> str;
//		if (M.empty())
//		{
//			for (auto e : str)
//			{
//				M[0][e]++;
//			}
//		}
//
//		unordered_map<char, int> _str;
//		for (auto e : str)
//		{
//			_str[e]++;
//		}
//
//		if (!exist(M, _str))
//		{
//			num++;
//			M.push_back(_str);
//		}
//	}
//
//	cout << num << endl;
//	return 0;
//}

//[1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0], 
//[0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
//[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
//[0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0], 
//[1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0], 
//[0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0], 
//[0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0], 
//[1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0], 
//[1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0], 
//[0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0], 
//[0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0], 
//[0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1], 
//[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1]

//#include<unordered_map>
//#include<string>
#include<vector>
#include<unordered_set>

//[[1, 1, 0]
// [1, 1, 0] 
// [0, 0, 1]]
int citys(vector<vector<int>>& m) {
    // write code here
    vector<unordered_set<int>> size;
    int amend = 0;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (m[i][j] == 1)
            {
                int flag = 1;
                for (auto& e : size)
                {
                    if ((flag == 0)&&(e.count(i) || e.count(j)))
                    {
                        amend++;
                    }

                    if (e.count(i) || e.count(j))
                    {
                        e.insert(i);
                        e.insert(j);
                        flag = 0;
                    }
                }

                if (flag)
                {
                    unordered_set<int> s;
                    s.insert(i);
                    s.insert(j);

                    size.push_back(s);
                }
                
            }
        }
    }

    int _size = size.size() - amend;


    return _size;

}

int main()
{
    vector<vector<int>> m = { {1,1,0},{1,1,0},{0,0,1} };
    cout << citys(m) << endl;
    return 0;
}

int citys(vector<vector<int>>& m) {
    vector<unordered_set<int>> size;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] == 1) {
                vector<int> indexes;
                for (int k = 0; k < size.size(); ++k) {
                    if (size[k].count(i) || size[k].count(j)) {
                        indexes.push_back(k);
                    }
                }

                if (indexes.empty()) {
                    unordered_set<int> s;
                    s.insert(i);
                    s.insert(j);
                    size.push_back(s);
                }
                else {
                    int first_index = indexes[0];
                    size[first_index].insert(i);
                    size[first_index].insert(j);

                    for (int k = 1; k < indexes.size(); ++k) {
                        int idx = indexes[k];
                        size[first_index].insert(size[idx].begin(), size[idx].end());
                    }

                    for (int k = indexes.size() - 1; k > 0; --k) {
                        size.erase(size.begin() + indexes[k]);
                    }
                }
            }
        }
    }

    return size.size();
}