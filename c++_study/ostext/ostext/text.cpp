//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string S = { "aabbaa" };
//
//
//    for (size_t i = 1; i < S.size();) {
//        if ( i != 0 && S[i] == S[i - 1]) {
//            S.erase(i - 1, 2);
//            --i;
//        }
//        else {
//            i++;
//        }
//    }
//
//    if (S.size() != 0)
//        cout << S << endl;
//    else
//        cout << "0" << endl;
//    return 0;
//}


//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	try
//	{
//        int a = 2, b = 22;
//        string num;
//
//        int nums = 0;
//
//        for (int i = a; i <= b; i++)
//        {
//            num += to_string(i);
//        }
//
//        for (auto e : num)
//        {
//            if (e == '2')
//            {
//                nums++;
//            }
//        }
//
//        cout << nums << endl;
//	}
//	catch (const std::exception& e)
//	{
//        cout << e.what() << endl;
//	}
//
//    return 0;
//}


#include<iostream>
using namespace std;
#include<vector>


//int maxProfit(vector<int>& prices) {
//
//    int Last_profit = 0;
//    int minprice = 1e5;
//    int New_profit = 0;
//    for (auto price : prices)
//    {
//        if (price - minprice > New_profit)
//        {
//            New_profit = max(price - minprice, New_profit);
//        }
//        else
//        {
//            Last_profit += New_profit;
//            New_profit = 0;
//            minprice = price;
//        }
//    }
//
//    return Last_profit + New_profit;
//
//}
//
//
//int main()
//{
//    vector<int> prices = { 7,1,5,3,6,4 };
//    cout<< maxProfit(prices);
//
//    return 0;
//}


//bool Jump(vector<int>& nums, int i)
//{
//    if (i >= nums.size()-1)
//    {
//        return true;
//    }
//
//    int nextPos = -1;
//    for (int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1); j++)
//    {
//        if (nums[j] > nums[i])
//        {
//            nextPos = j;
//            break;
//        }
//    }
//
//    if (nextPos == -1) // 如果没有找到比当前数大的数，则无法前进
//    {
//        return false;
//    }
//
//    return Jump(nums, nextPos); // 递归跳到下一个位置
//
//}
//
//bool canJump(vector<int>& nums) {
//    
//    int i = 0;
//    return Jump(nums, i);
//}
//
//
//int main()
//{
//    vector<int> nums = { 2,3,1,1,4 };
//    cout<< canJump(nums);
//    return 0;
//}

//int main() {
//    vector<int> V = { 1,100, 1, 1, 1, 90, 1, 1, 80, 1 };
//    int a = 10;
//
//    if (V.empty()) {
//        cout << 0;
//        return 0;
//    }
//
//    int budget = V[0];
//    int c = 0;
//
//    if (V.size() > 1) {
//        if (V[0] < V[1]) {
//            budget = V[0];
//            c = 0;
//        }
//        else {
//            budget = V[1];
//            c = 1;
//        }
//    }
//
//    for (int i = c; i < V.size();) {
//        if (i + 1 >= V.size()) {
//            cout << budget;
//            return 0;
//        }
//
//        if (i + 2 >= V.size()) {
//            cout << budget;
//            return 0;
//        }
//
//        if (V[i + 1] < V[i + 2]) {
//            budget += V[i + 1];
//            i += 1;
//        }
//        else {
//            budget += V[i + 2];
//            i += 2;
//        }
//    }
//
//    cout << budget;  // 确保输出最终预算值
//    return 0;
//}

//#include<queue>
//
//int main() {
//
//   /* int c;
//    cin >> c;*/
//    int a = 3, b;
// /*   cin >> a;*/
//
//    priority_queue<int> Q;
//    vector<int> V = { 2, 4, 8, 10, 11 };
//
//
//    //while (cin >> b) {
//    //    V.push_back(b);
//    //}
//
//    int num = 0;
//
//    for (auto e : V)
//    {
//        if ((e & 1) == 0)
//        {
//            Q.push(e);
//        }
//        else
//        {
//            num += e;
//        }
//    }
//
//    for (int i = 0; i < a && !Q.empty(); i++)
//    {
//        while ((Q.top() & 1) != 0 && !Q.empty())
//        {
//            num += Q.top();
//            Q.pop();
//        }
//
//        if (Q.empty())
//        {
//            break;
//        }
//      
//        int temp = Q.top() / 2;
//        Q.pop();
//        Q.push(temp);
//      
//    }
//
//    while (!Q.empty())
//    {
//        num += Q.top();
//        Q.pop();
//    }
//
//    cout << num << endl;
//
//
//    return 0;
//}



//int main()
//{
//	int a = 1;
//	int mindistance = 1e5;
//
//	vector<int> V;
//	V.push_back(0);
//	V.push_back(1);
//
//	while (V.back() < a)
//	{
//		mindistance = a - V.back();
//
//		V.push_back(V[V.size() - 1] + V[V.size() - 2]);
//	}
//
//	mindistance = min(V.back() - a, mindistance);
//
//	cout << mindistance << endl;
//
//	return 0;
//}

//

//vector<string> buff;
//
//bool judge(vector<string>& board, string word, int x, int y, int local)
//{
//    if (local == word.size()) {
//        return true;
//    }
//
//    // 确保 x 和 y 在边界内并匹配,不能斜着走
//    if (x >= 0 && x < board.size() && y>=0 && y < board[x].size() && board[x][y] == word[local])
//    {
//        board[x][y] = '0';//防止重复
//
//        if (judge(board, word, x - 1, y, local + 1))
//            return true;
//        else if (judge(board, word, x + 1, y, local + 1))
//            return true;
//        else if (judge(board, word, x, y - 1, local + 1))
//            return true;
//        else if (judge(board, word, x, y + 1, local + 1))
//            return true;
//
//		board[x][y] = buff[x][y];// 路径失败，将值重新带回去
//    }
//
//    return false;
//}
//
//bool exist(vector<string>& board, string word) {
//	// write code here
//
//
//	/*int x = board.size();
//	int y = board[0].size();*/
//	buff = board;
//	for (int x = 0; x < board.size(); x++)
//	{
//		for (int y = 0; y < board[x].size(); y++)
//		{
//			
//			if (judge(board, word, x, y, 0) == true)
//					return true;
//
//		}
//	}
//
//	return false;
//
//}
//
////["XYZE","SFZS","XDEE"],"XYZZED"
//
//
//int main()
//{
//	vector<string> board = { "CAA","AAA","BCD" };
//	string word("AAB");
//
//	cout << exist(board, word) << endl;
//	return 0;
//}


//void triangle(vector<int>& board, int i)
//{
//	if (i == 1)
//	{
//		cout << 1 << endl;
//		return;
//	}
//
//	if (i == 2)
//	{
//		cout << 1 << " " << 1 << endl;
//		return;
//	}
//
//	vector<int> copy;
//	copy.resize(board.size() + 1);
//	copy[0] = 1;
//	copy[copy.size() - 1] = 1;
//
//	cout << 1 << " ";
//	for (int i = 1; i < copy.size()-1; i++)
//	{
//		copy[i] = board[i - 1] + board[i];
//		cout << copy[i] << " ";
//	}
//
//	cout << 1 << " " << endl;
//
//	swap(board, copy);
//	return;
//}
//
//
//int main()
//{
//	int i = 0;
//	cin >> i;
//	vector<int> board = { 1,1 };
//	for (int a = 1; a <= i; a++)
//	{
//		triangle(board, a);
//	}
//	return 0;
//}


//
//int main()
//{
//	int cur = 0;
//	cin >> cur;
//	while (cur--)
//	{
//		int y, o, u;
//		cin >> y >> o >> u;
//
//		int Min = min(y, min(o, u));
//		o -= Min;
//		
//		cout << Min * 2 + o - 1;
//
//	}
//
//
//	return 0;
//}

#include<string>


//string solve(string s, string t) {
//    // write code here
//    string shorts = s;
//    string longs = t;
//    if (t.size() < s.size())
//    {
//        shorts = t;
//        longs = s;
//    }
//    string re;
//
//    int carry_over = 0;
//    int shorts_subscript = shorts.size() - 1;
//    int longs_subscript = longs.size() - 1;
//    while (shorts_subscript >= 0)
//    {
//        int digit = (longs[longs_subscript] - '0') + (shorts[shorts_subscript] - '0') + carry_over;
//        carry_over = digit / 10;
//        re += to_string(digit % 10);
//
//        shorts_subscript--;
//        longs_subscript--;
//    }
//    
//    while (longs_subscript >= 0)
//    {
//        int digit = (longs[longs_subscript] - '0') + carry_over;
//        carry_over = digit / 10;
//        re += to_string(digit % 10);
//
//        longs_subscript--;
//    }
//
//    if (carry_over > 0) {
//        re += to_string(carry_over);
//    }
//
//    reverse(re.begin(), re.end());
//
//    return re;
//}
//
//int main()
//{
//    string cout_re = solve("1005", "999");
//    cout << cout_re << endl;
//    return 0;
//}

//struct ListNode
//{
//    int val;
//    ListNode* next;
//};
//
//ListNode* reverse_list(ListNode* head)
//{
//    ListNode* temp = head;
//    ListNode* prev = nullptr;
//    while (temp != nullptr)
//    {
//        ListNode* _next = temp->next;
//        
//        temp->next = prev;
//        prev = temp;
//        temp = _next;
//    }
//
//    return prev;
//}
//
//ListNode* addInList(ListNode* head1, ListNode* head2) {
//    // write code here
//
//    head1 = reverse_list(head1);
//    head2 = reverse_list(head2);
//
//    ListNode* temp1 = head1;
//    ListNode* temp2 = head2;
//    
//    int digit = 0;
//    int carry_over = 0;
//
//    while (temp1!=nullptr&&temp2!=nullptr)
//    {
//        digit = temp1->val + temp2->val + carry_over;
//        carry_over = digit / 10;
//        temp1->val = digit % 10;
//
//        temp1 = temp1->next;
//        temp2 = temp2->next;
//    }
//
//    ListNode* uncompleted = temp1;
//    //if (temp2 != nullptr) {
//    //    uncompleted = temp1;
//    //}
//
//    while (uncompleted != nullptr) {
//        digit = uncompleted->val + carry_over;
//        carry_over = digit / 10;
//        uncompleted->val = digit % 10;
//
//        if (uncompleted->next == nullptr) {
//            break;
//        }
//
//        uncompleted = uncompleted->next;
//    }
//
//    if (carry_over != 0) {
//        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//        newNode->val = 1;
//        newNode->next = nullptr;
//
//        uncompleted->next = newNode;
//    }
//
//    return reverse_list(head1);
//}
//
//void push_back(ListNode** head, int* array, int size) {
//    ListNode* temp = *head;
//
//
//    if (temp == nullptr) {
//        *head = new ListNode;
//        (*head)->val = array[0];
//        (*head)->next = nullptr;
//        temp = *head;
//    }
//
//    while (temp->next != nullptr) {
//        temp = temp->next;
//    }
//
//    for (int i = 1; i < size; i++) {
//        temp->next = new ListNode;
//        temp = temp->next;
//        temp->val = array[i];
//        temp->next = nullptr;
//    }
//}
//
//int main()
//{
//    ListNode* head1 = nullptr;
//    int array1[] = {4,6,0,2,6,6,3,6,3,0,7,8,0,4,1,7,0,5,6,5,2,4,9,9,1,5,1,5};
//
//    int size1 = sizeof(array1) / 4;
//
//    ListNode* head2 = nullptr;
//    int array2[]= { 6,2,7,8,6,4,7,0,9,3,0,3,6,2,5,6,0,9,6,2,7,4,2,7,1,0,9,0,5,6,5,4,9,1,8,9,3,4,0,2,1,8,8,2,2,0 };
//
//    int size2 = sizeof(array2) / 4;
//    push_back(&head1, array1, size1);
//    push_back(&head2, array2, size2);
//
//    head2 = addInList(head2, head1);
//
//    while (head2 != nullptr)
//    {
//        cout << head2->val << " ";
//        head2 = head2->next;
//    }
//
//    cout << endl;
//
//    return 0;
//}

//string solve1(string s, string t) {
//    // write code here
//    string shorts = s;
//    string longs = t;
//    if (t.size() < s.size()) {
//        shorts = t;
//        longs = s;
//    }
//    string re;
//
//    int carry_over = 0;
//    int shorts_subscript = shorts.size() - 1;
//    int longs_subscript = longs.size() - 1;
//    while (shorts_subscript >= 0) {
//        int digit = (longs[longs_subscript] - '0') + (shorts[shorts_subscript] - '0') +
//            carry_over;
//        carry_over = digit / 10;
//        re += to_string(digit % 10);
//
//        shorts_subscript--;
//        longs_subscript--;
//    }
//
//    while (longs_subscript >= 0) {
//        int digit = (longs[longs_subscript] - '0') + carry_over;
//        carry_over = digit / 10;
//        re += to_string(digit % 10);
//
//        longs_subscript--;
//    }
//
//    if (carry_over > 0) {
//        re += to_string(carry_over);
//    }
//
//    reverse(re.begin(), re.end());
//
//    return re;
//}
//
//
//string solve(string s, string t) {
//    // write code here
//    string shorts = s;
//    string longs = t;
//    if (t.size() < s.size()) {
//        shorts = t;
//        longs = s;
//    }
//
//    int carry_over = 0;
//    int shorts_subscript = shorts.size() - 1;
//    int num = 0;
//    string result;
//    
//
//    while (shorts_subscript >= 0) {
//        int longs_subscript = longs.size() - 1;
//        string re;
//        while (longs_subscript >= 0 || carry_over) {
//            int sum = shorts[shorts_subscript] - '0';
//
//            /*if (longs_subscript >= 0) {
//                sum *= longs[longs_subscript--] - '0';
//            }*/
//
//            if (longs_subscript >= 0) {
//                sum *= longs[longs_subscript--] - '0';
//            }
//            else
//            {
//                //sum 这时候只需要加上上一次计算的进位即可
//                num *= 0;
//            }
//            
//
//            re += to_string((sum + carry_over) % 10);
//
//            carry_over = (sum + carry_over) / 10;
//        }
//
//        reverse(re.begin(), re.end());
//
//        for (int i = 0; i < num; i++)
//        {
//            re += '0';
//        } 
//
//
//        result = solve1(result, re);
//
//        shorts_subscript--;
//        num++;
//
//    }
//
//   // return result;
//
//    int start_pos = result.find_first_not_of("0");
//    if (start_pos != string::npos) {
//        return result.substr(start_pos);
//    }
//    return "0";
//
//}

//int main()
//{
//    cout << solve("10086", "10086");
//
//    return 0;
//}

//struct ListNode
//{
//    int val;
//    ListNode* next;
//};
//
//ListNode* reverse_list(ListNode* head) {
//    ListNode* temp = head;
//    ListNode* prev = nullptr;
//    while (temp != nullptr) {
//        ListNode* _next = temp->next;
//
//        temp->next = prev;
//        prev = temp;
//        temp = _next;
//    }
//
//    return prev;
//}
//
//ListNode* addInList(ListNode* head1, ListNode* head2) {
//    // write code here
//
//    head1 = reverse_list(head1);
//    head2 = reverse_list(head2);
//
//    ListNode* temp1 = head1;
//    ListNode* temp2 = head2;
//    int digit = 0;
//    int carry_over = 0;
//
//    while (temp1 != nullptr && temp2 != nullptr) {
//        digit = temp1->val + temp2->val + carry_over;
//        carry_over = digit / 10;
//        temp1->val = digit % 10;
//
//        temp1 = temp1->next;
//        temp2 = temp2->next;
//    }
//
//    ListNode* uncompleted = temp1;
//    if (temp2 != nullptr) {
//        uncompleted = temp1;
//    }
//
//    while (uncompleted != nullptr) {
//        digit = uncompleted->val + carry_over;
//        carry_over = digit / 10;
//        uncompleted->val = digit % 10;
//
//        if (uncompleted->next == nullptr) {
//            break;
//        }
//
//        uncompleted = uncompleted->next;
//    }
//
//    if (carry_over != 0) {
//        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//
//        newNode->val = 1;
//        newNode->next = nullptr;
//
//        uncompleted->next = newNode;
//    }
//
//    return reverse_list(head1);
//}
//
//int main()
//{
//    ListNode* list1 = new ListNode;
//    list1->val;
//
//
//    return 0;
//}


//#include<vector>
//#include <iostream>
//using namespace std;
//
//int main() {
//    /*int n = 0;
//    cin >> n;*/
//    vector<int> cost = { 55 ,89, 84, 47, 76, 71, 75, 63, 18, 9 };
//    /*int b = 0;
//    while (cin >> b)
//    {
//        cost.push_back(b);
//    }*/
//
//    vector<int> dp;
//    dp.resize(cost.size() + 1);
//    dp[0] = 0;
//    dp[1] = 0;
//
//    for (int i = 2; i <= cost.size(); i++)
//    {
//        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//    }
//
//    cout << dp[cost.size()] << endl;
//    return 0;
//
//}


//int main() {
//    int L;
//    cin >> L;
//
//    int critical;
//    cin >> critical;
//
//    vector<int> V ;
//
//    int b;
//    while (cin >> b)
//    {
//        V.push_back(b);
//    }
//
//    int mindistance = V.size();
//    int right = 0;
//    int left = 0;
//
//    pair<int, int> LR_Location;
//
//    int num = 0;
//
//    while (right < V.size())
//    {
//        num += V[right];
//        while (left < right && num >= critical)
//        {
//            if (mindistance > right - left + 1)
//            {
//                LR_Location = pair<int, int>(left, right);
//                mindistance = right - left + 1;
//            }
//            num -= V[left]; // 1 1 6 10 9 3 3 5 3 7
      
//            left++;
//        }
//
//        right++;
//    }   
//
//    
//    cout << LR_Location.first + 1 << " " << LR_Location.second + 1 << endl;
//    return 0;
//
//
//}

//int main()
//{
//	string str("abcd12345ed125ss123");
//
//
//
//	int right = 0;
//	pair<int, int> maxdistance(0, 0);
//
//
//	while (right < str.size())
//	{
//		int left = right;
//		while (str[right] <= '9' && str[right] >='0' && right< str.size())
//		{
//			if (right - left > maxdistance.second - maxdistance.first)
//			{
//				maxdistance.second = right;
//				maxdistance.first = left;
//			}
//			right++;
//		}
//		
//		right++;
//	}
//
//	cout << str.substr(maxdistance.first, maxdistance.second - maxdistance.first + 1);
//
//	return 0;
//
//}




//void solve(vector<vector<char> >& grid, int x , int y)
//{
//
//    // 确保 x 和 y 在边界内并匹配,不能斜着走
//    if (x >= 0 && x < grid.size() && y>=0 && y < grid[x].size() && grid[x][y] == '1')
//    {
//        grid[x][y] = '0';//将相连的  ' 1 ' 全部置为 ' 0 '
//        
//        solve(grid, x - 1, y);
//        solve(grid, x + 1, y);
//        solve(grid, x, y - 1);
//        solve(grid, x, y + 1);
//    }
//
//    return ;
//}
//
//int solve(vector<vector<char> >& grid) {
//    // write code here
// 
//
//    //vector<vector<char>> copy = grid;
//    int count = 0;
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[i].size(); j++)
//        {
//            if (grid[i][j] == '1')
//            {
//                solve(grid, i, j);
//                count++;
//            }
//        }
//    }
//
//    return count;
//}
//
////[[1, 1, 0, 0, 0], [0, 1, 0, 1, 1], [0, 0, 0, 1, 1], [0, 0, 0, 0, 0], [0, 0, 1, 1, 1]]
//int main()
//{
//    vector<vector<char> > grid = { { '1', '1', '0' , '0', '0'},{'0', '1','0', '1', '1'},{'0', '0', '0', '1', '1' },{'0' , '0', '0','0', '0'},{'0', '0', '1', '1', '1'} };
//    std::cout << solve(grid) << endl;
//    return 0;
//}

//bool istriangle(const vector<long long>& triangle, int i, int j, int z) {
//    return (triangle[i] + triangle[j] > triangle[z] &&
//        triangle[i] + triangle[z] > triangle[j] &&
//        triangle[j] + triangle[z] > triangle[i]);
//}
//
//bool areBothTriangles(const vector<long long>& triangle, int i, int j, int z) {
//    if (!istriangle(triangle, i, j, z)) {
//        return false;
//    }
//
//    vector<int> remainingIndices;
//    for (int k = 0; k < triangle.size(); ++k) {
//        if (k != i && k != j && k != z) {
//            remainingIndices.push_back(k);
//        }
//    }
//
//    return istriangle(triangle, remainingIndices[0], remainingIndices[1], remainingIndices[2]);
//}
//
//int main() {
//    int cycle_index;
//    cin >> cycle_index;
//
//    while (cycle_index > 0) {
//        vector<long long> triangle;
//        long long b;
//        while (cin >> b) {
//            triangle.push_back(b);
//            if (cin.peek() == '\n' || cin.peek() == EOF) {
//                break;
//            }
//        }
//
//        bool found = false;
//
//        for (int i = 0; i < triangle.size() - 2 && !found; ++i) {
//            for (int j = i + 1; j < triangle.size() - 1 && !found; ++j) {
//                for (int z = j + 1; z < triangle.size(); ++z) {
//                    if (areBothTriangles(triangle, i, j, z)) {
//                        cout << "Yes" << endl;
//                        found = true;
//                        break;
//                    }
//                }
//            }
//        }
//
//        if (!found) {
//            cout << "No" << endl;
//        }
//
//        --cycle_index;
//    }
//
//    return 0;
//}

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



//#include <iostream>
//using namespace std;
//#include<unordered_map>
//
//int main() {
//    int a, b;
//    cin >> a;
//    cin >> b;
//
//    int least_com_mul = a * b;
//
//    vector<int> a_mul;
//    for (int i = 1; i <= least_com_mul / a; i++)
//    {
//        a_mul.push_back(i * a);
//    }
//
//    vector<int> b_mul;
//    for (int i = 1; i <= least_com_mul / b; i++)
//    {
//        b_mul.push_back(i * b);
//    }
//
//
//    unordered_map<int, int> com_mul;
//
//    for (const auto& e : a_mul) {
//        com_mul[e]++;
//    }
//
//    for (const auto& e : b_mul) {
//        if (com_mul.find(e) != com_mul.end()) {
//            cout << e << endl;
//            break;
//        }
//    }
//
//
//
//    return 0;
//}

//struct Less
//{
//    bool operator()(int a, int b)
//    {
//        return a > b;
//    }
//};
//#include<algorithm>
//
//int MLS(vector<int>& arr) {
//    // write code here
//
//    sort(arr.begin(), arr.end(),Less());
//
//    int right = 1;
//    int count = 1;
//    int max_str = 1;
//
//    while (right < arr.size())
//    {
//        if (arr[right] == arr[right - 1])
//            continue;
//
//        if (arr[right] == arr[right - 1] + 1)
//            count++;
//        else
//            count = 1;
//
//        max_str = max(count, max_str);
//
//        right++;
//    }
//
//    return max_str;
//}
//
////[100,4,200,1,3,2]
//
//int main()
//{
//    vector<int> arr = { 100,4,200,1,3,2 };
//    cout << MLS(arr);
//    return 0;
//}

#include<unordered_map>

//enum love_score
//{
//    e = 1,
//    v,
//    o,
//    l,
//};

//unordered_map<char, int> love_map = { {'l',4},{'o',3},{'v',2},{'e',1} };
//
//
//int solve(vector<vector<char>>& board,int x,int y)
//{
//    if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
//    {
//        return 0;
//    }
//
//    int score = 0;
//
//    if (love_map.count(board[x][y]) == 1)
//        score = love_map[board[x][y]];
//
//
//    int below = solve(board,  x + 1, y);
//    int right = solve(board,  x, y + 1);
//    
//    return score + max(right, below);
//}
//
////3 2
////ab
////cd
////ef
//
////{"a" , "b"},
////{"c" , "d" },
////{"e" , "f" }
//
//int main()
//{
//    /*vector<vector<char>> board = {
//
//        {"a","b"},
//        {"c","d"},
//        {"e","f"}
//
//    };*/
//
//    vector<vector<char>> board;
//
//    int length;
//    int wide;
//    cin >> length;
//    cin >> wide;
//
//    board.resize(wide);
//
//    string str;
//
//    /*vector<char> V;
//    V.push_back('e');*/
//
//    //board[0].push_back('e');
//
//
//    for (int i = 0; i < wide; i++)
//    {
//        cin >> str;
//        for (auto e : str)
//        {
//            board[i].push_back(e);
//        }
//    }
//
//    int score = 0;
//
//    score = solve(board, 0, 0);
//    cout << score << endl;
//    return 0;
//}

//{
//    2 , 1 , 0 , 0
//    0 , 1 , 0 , 2
//    0 , 1 , 1 , 1
//    0 , 2 , 1 , 0
//}

//#include<queue>
//
//
//int rotApple(vector<vector<int> >& grid) {
//
//    int dx[] = { 0,0,1,-1 };
//    int dy[] = { 1,-1,0,0 };
//    queue<pair<int, int>> level;
//    
//
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[i].size(); j++)
//        {
//            if (grid[i][j] == 2)
//            {
//                level.push(make_pair(i, j));
//            }
//        }
//    }
//
//    
//    int ret = 0;
//    while (!level.empty())
//    {
//        int sz = level.size();//记录每一层的个数
//        ret++;
//        while (sz--)
//        {
//            auto [a, b] = level.front();//c++ 17 新语法
//
//            for (int i = 0; i < 4; i++)
//            {
//                int x = a + dx[i];
//                int y = b + dy[i];
//
//                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
//                {
//                    grid[x][y] = 2;
//                    level.push(make_pair(x, y));
//                }
//            }
//            level.pop();
//        }
//    }
//
//    ret -= 1;//ret多统计一次
//
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[i].size(); j++)
//        {
//            if (grid[i][j] == 1)
//            {
//                ret = -1;
//            }
//        }
//    }
//
//    return ret;
//}
//
//int main()
//{
//    vector<vector<int> > grid = { {2,1,1},{1,0,1},{1,1,1} };
//    rotApple(grid);
//    return 0;
//}


//int main()
//{
//    long long b;
//    cin >> b;
//
//    string V;
//    V += to_string(b);
//
//    reverse(V.begin(),V.end());
//
//    string S;
//    int count = 3;
//
//    int i = 0;
//
//    while (i < V.size())
//    {
//        S += V[i];
//        count--;
//        if (count == 0 && i + 1 < V.size())
//        {
//            S += ',';
//            count = 3;
//        }
//
//        i++;
//    }
//
//    reverse(S.begin(), S.end());
//
//    cout << S << endl;
//    return 0;
//}


//int main()
//{
//    int n = 0;
//    cin >> n;
//
//
//    int dp[40];
//    dp[0] = 1;
//    dp[1] = 2;
//
//
//    for (int i = 2; i < n; i++)
//    {
//        dp[i] = (dp[i - 1] ) + (dp[i - 2] );
//    }
//
//    cout << dp[n - 1] << endl;
//    return 0;
//}
//#include<algorithm>
//
//bool IsContinuous(vector<int>& numbers) {
//    // write code here
//    sort(numbers.begin(), numbers.end());
//
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        if (numbers[i] != 0 && i + 1 < numbers.size() && numbers[i] == numbers[i + 1])
//            return false;
//    }
//
//    int min = -1;
//    for (auto& e : numbers)
//    {
//        if (e != 0)
//        {
//            min = e;
//
//            if (numbers.back() - min - 1 <= 3 )
//            {
//                return true;
//            }
//
//            return false;
//        }
//    }
//    
//
//
//}
//
////[6,0,2,0,4]
//int main()
//{
//    vector<int> numbers = { 6,0,2,0,4 };
//    cout << IsContinuous(numbers) << endl;
//    return 0;
//}

//7
//8 9 2 5 4 7 1

//int main()
//{
//    vector<int> prices = { 8,7,9,2,5,4,7,1 };
//    int maxprices = 0;
//    int minprice = 1e5;
//
//    for (auto price : prices)
//    {
//        if (minprice > price)
//        {
//            minprice = price;
//        }
//
//        maxprices = max(maxprices, price - minprice );
//
//    }
//    cout << maxprices << endl;
//
//    return 0;
//}

//bool horse_board(vector<pair<int, int>>& horse, int x, int y);
//
//int path(int x,int y, vector<pair<int, int>>& horse, pair<int, int>& soldier)
//{
//    if (x < 0 || x > soldier.first || y < 0 || y > soldier.second) {
//        return 0;
//    }
//
//    if (x == soldier.first && y == soldier.second)
//        return 1;
//
//    if (horse_board(horse, x, y))
//        return 0;
//
//    return path(x + 1, y, horse, soldier) + path(x, y + 1, horse, soldier);
//    
//}
//
//bool horse_board(vector<pair<int, int>>& horse, int x, int y) {
//    for (const auto& h : horse) {
//        if (h.first == x && h.second == y) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    pair<int, int> soldier;
//    //cin >> soldier.first >> soldier.second;
//    soldier.first = 5;
//    soldier.second = 4;
//    int a = 3;
//    vector<pair<int, int>> horse;
//    horse.push_back(make_pair(2, 3));
//    //先存入本身位置
//    int dx_horse[] = { 1,2,2,1,-1,-2,-2,-1 };
//    int dy_horse[] = { -2,-1,1,2,2,1,-1,-2 };
//
//    for (int i = 0; i < 8; i++) {
//        int x = horse[0].first + dx_horse[i];
//        int y = horse[0].second + dy_horse[i];
//
//        if (x >= 0 && x <= soldier.first && y >= 0 && y <= soldier.second) {
//            horse.push_back(make_pair(x, y));
//        }
//    }
//
//    cout << path(0, 0, horse, soldier) << endl;
//
//    return 0;
//}

//#include<algorithm>
//
//bool palindromic(string str)
//{
//    string copy = str;
//
//    reverse(str.begin(), str.end());
//
//    if (copy == str)
//        return true;
//
//    return false;
//}
//
//int main()
//{
//    string Str("abbba");
//
//    int max_distance = 1;
//
//    for(int i=1;i<Str.size();i++)
//    {
//        int left = 1;
//        int right = i;
//        string str = Str.substr(0, i + 1);
//        if (palindromic(str))
//            max_distance = i + 1;
//
//        for (; left < right; left++)
//        {
//            if (right - left + 1 > max_distance)
//            {
//                str = Str.substr(left, right - left + 1);
//                if (palindromic(str))
//                    max_distance = right - left + 1;
//            }
//        }
//
//    }
//
//    cout << max_distance << endl;
//    return 0;
//}

//int n, m, x, y;
//long long dp[50][50];
//int lab[50][50];
//int dir[8][2] = { -1,-2,1,-2,-2,-1,2,-1,-2,1,-1,2,1,2,2,1 };
//int main()
//{
//    cin >> n >> m >> x >> y;
//    dp[0][0] = 1;
//    lab[x][y] = 1;
//    for (int i = 0; i < 8; i++) {
//        int xx = x + dir[i][0];
//        int yy = y + dir[i][1];
//        lab[xx][yy] = 1;
//    }
//
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= m; j++)
//        {
//            if (i == 0 && j == 0)
//                continue;
//
//            if (lab[i][j])
//            {
//                dp[i][j] = 0;
//                continue;
//            }
//
//            if (i == 0)
//            {
//                dp[i][j] = dp[i][j - 1];
//                continue;
//            }
//
//            if (j == 0)
//            {
//                dp[i][j] = dp[i - 1][j];
//                continue;
//            }
//
//
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        }
//    }
//
//    cout << dp[n][m] << endl;
//
//    return 0;
//}

//int main()
//{
//    pair<int, int> apple;
//    pair<int, int> peach;
//
//    //first -> price second -> quantity
//
//    cin >> apple.first >> peach.first;
//    cin >> apple.second >> peach.second;
//
//
//    pair<int, int> expensive = apple;
//    pair<int, int> cheap = peach;
// 
//
//    int real_first_E = expensive.first % 2 == 0 ? expensive.first : expensive.first - 1;
//    int real_first_C = cheap.first % 2 == 0 ? cheap.first : cheap.first - 1;
//
//    if (real_first_E * expensive.second < real_first_C * cheap.second)
//    {
//        expensive = peach;
//        cheap = apple;
//    }
//
//
//    long long total = 0;
//
//    while (expensive.first - 2 >= 0 && cheap.first - 1 >= 0)
//    {
//        expensive.first -= 2;
//        cheap.first -= 2;
//
//        total += expensive.second;
//    }
//
//    if (cheap.first == 0 || expensive.first == 0||(expensive.first == 1 && cheap.first==1))
//        cout << total << endl;
//
//    if (expensive.first == 1 && cheap.first - 2 >= 0)
//    {
//        total += cheap.second;
//        cout << total << endl;
//    }
//   
//    return 0;
//
//}
#include<algorithm>
int main() {
    string str;
    getline(cin, str);

    string _str;
    for (string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
        if (*it == ' ') {
            reverse(_str.begin(), _str.end());
            cout << _str << " ";
            _str.clear();
        }
        else {
            _str += *it;
        }
    }

    reverse(_str.begin(), _str.end());
    cout << _str << endl;

    return 0;
}