# 笔试强训 day —7

## 字符串中连续的最长数字串

![image-20240722153402623](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722153402623.png)

![image-20240722153408810](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722153408810.png)

```C++
string str("abcd12345ed125ss123");



int right = 0;
pair<int, int> maxdistance(0, 0);


while (right < str.size())
{
	int left = right;
	while (str[right] <= '9' && str[right] >='0' && right< str.size())
	{
		if (right - left > maxdistance.second - maxdistance.first)
		{
			maxdistance.second = right;
			maxdistance.first = left;
		}
		right++;
	}
	
	right++;
}

cout << str.substr(maxdistance.first, maxdistance.second - maxdistance.first + 1);
```

**substr 参数为初始位置和从这个位置开始几个字符的距离**

## 岛屿数量

![image-20240722155649302](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722155649302.png)

![image-20240722155657345](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722155657345.png)

```c++
void solve(vector<vector<char> >& grid, int x , int y)
{

    // 确保 x 和 y 在边界内并匹配,不能斜着走
    if (x >= 0 && x < grid.size() && y>=0 && y < grid[x].size() && grid[x][y] == '1')
    {
        grid[x][y] = '0';//将相连的  ' 1 ' 全部置为 ' 0 '
        
        solve(grid, x - 1, y);
        solve(grid, x + 1, y);
        solve(grid, x, y - 1);
        solve(grid, x, y + 1);
    }

    return ;
}

int solve(vector<vector<char> >& grid) {
    // write code here
 

    //vector<vector<char>> copy = grid;
    //如果不改变原数组，可以使用拷贝对象
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                solve(grid, i, j);
                count++;
            }
        }
    }
c++
    return count;
}

//[[1, 1, 0, 0, 0], [0, 1, 0, 1, 1], [0, 0, 0, 1, 1], [0, 0, 0, 0, 0], [0, 0, 1, 1, 1]]
int main()
{
    vector<vector<char> > grid = { { '1', '1', '0' , '0', '0'},{'0', '1','0', '1', '1'},{'0', '0', '0', '1', '1' },{'0' , '0', '0','0', '0'},{'0', '0', '1', '1', '1'} };
    std::cout << solve(grid) << endl;
    return 0;
}
```

## 拼三角

![image-20240722165358106](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722165358106.png)

![image-20240722165112603](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722165112603.png)

```C++
bool istriangle(const vector<long long>& triangle, int i, int j, int z) {
    return (triangle[i] + triangle[j] > triangle[z] &&
            triangle[i] + triangle[z] > triangle[j] &&
            triangle[j] + triangle[z] > triangle[i]);
}

bool areBothTriangles(const vector<long long>& triangle, int i, int j, int z) {
    if (!istriangle(triangle, i, j, z)) {
        return false;
    }

    vector<int> remainingIndices;
    for (int k = 0; k < triangle.size(); ++k) {
        if (k != i && k != j && k != z) {
            remainingIndices.push_back(k);
        }
    }

    return istriangle(triangle, remainingIndices[0], remainingIndices[1], remainingIndices[2]);
}

int main() {
    int cycle_index;
    cin >> cycle_index;

    while (cycle_index > 0) {
        vector<long long> triangle;
        long long b;
        while (cin >> b) {
            triangle.push_back(b);
            if (cin.peek() == '\n' || cin.peek() == EOF) {
                break;
            }
        }

        bool found = false;

        for (int i = 0; i < triangle.size() - 2 && !found; ++i) {
            for (int j = i + 1; j < triangle.size() - 1 && !found; ++j) {
                for (int z = j + 1; z < triangle.size(); ++z) {
                    if (areBothTriangles(triangle, i, j, z)) {
                        cout << "Yes" << endl;
                        found = true;
                        break;
                    }
                }
            }
        }
        
//bool found = false;
//for (int i = 0; i < triangle.size() - 2; i++) {
//    int j = i + 1;
//    int z = j + 1;
//    //对于 j 并没有循环
//    while (z < triangle.size()) {
//        if (areBothTriangles(triangle, i, j, z)) {
//            cout << "Yes" << endl;
//            found = true;
//            goto _break;
//        }
//
//        z++;
//    }
//
//    i++;//重复加
//
//_break:
//    break;
//}

        if (!found) {
            cout << "No" << endl;
        }

        --cycle_index;
    }

    return 0;
}
```

![image-20240722165922873](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722165922873.png)

### [**使用库函数 <algorithm>**]()

![image-20240722171105013](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240722171105013.png)