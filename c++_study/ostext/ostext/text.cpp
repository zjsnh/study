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

//int main() {
//    //int L;
//   // cin >> L;
//
//    int critical = 20;
//   // cin >> critical;
//
//    vector<int> V = { 1, 1, 6, 10, 9, 3, 3, 5, 3, 7 };
//
//    /*int b;
//    while (cin >> b)
//    {
//        V.push_back(b);
//    }*/
//
//    int mindistance = V.size();
//    int right = 0;
//    int left = 0;
//
//    pair<int, int> LR_Location;
//
//    int num = 0;
//
//    /*for (int i = 0; i < V.size(); )
//    {
//        if (num >= critical)
//        {
//            if (right - left + 1 < mindistance)
//            {
//                LR_Location = pair<int, int>(left, right);
//                mindistance = right - left + 1;
//            }
//
//            while (left <= right && num > critical)
//            {
//                num -= V[left];
//                if (num > critical)
//                {
//                    left++;
//
//                    LR_Location = pair<int, int>(left, right);
//                    --mindistance;
//                }
//            }
//        }
//        else
//        {
//            num += V[i];
//            right = i;
//            i++;
//        }
//    }*/
//
//    while (right < V.size()) {
//        num += V[right];
//
//        while (num >= critical) {
//            if (right - left + 1 < mindistance) {
//                LR_Location = pair<int, int>(left, right);
//                mindistance = right - left + 1;
//            }
//            num -= V[left];
//            left++;
//        }
//        right++;
//    }
//
//    cout << LR_Location.first + 1 << " " << LR_Location.second + 1 << endl;
//    return 0;
//
//
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
//bool judge(vector<string>& board, string& word, int x, int y, int local)
//{
//    if (local == word.size()) {
//        return true;
//    }
//
//    // 确保 x 和 y 在边界内并匹配
//    if (x - 1 >= 0 && y - 1 >= 0 && y - 1 < board[x - 1].size() && board[x - 1][y - 1] == word[local]) {
//        if (judge(board, word, x - 1, y - 1, local + 1)) return true;
//    }
//    if (x < board.size() && y - 1 >= 0 && y - 1 < board[x].size() && board[x][y - 1] == word[local]) {
//        if (judge(board, word, x, y - 1, local + 1)) return true;
//    }
//    if (x + 1 < board.size() && y - 1 >= 0 && y - 1 < board[x + 1].size() && board[x + 1][y - 1] == word[local]) {
//        if (judge(board, word, x + 1, y - 1, local + 1)) return true;
//    }
//    if (x + 1 < board.size() && y < board[x + 1].size() && board[x + 1][y] == word[local]) {
//        if (judge(board, word, x + 1, y, local + 1)) return true;
//    }
//    if (x + 1 < board.size() && y + 1 < board[x + 1].size() && board[x + 1][y + 1] == word[local]) {
//        if (judge(board, word, x + 1, y + 1, local + 1)) return true;
//    }
//    if (x >= 0 && y + 1 < board[x].size() && board[x][y + 1] == word[local]) {
//        if (judge(board, word, x, y + 1, local + 1)) return true;
//    }
//    if (x - 1 >= 0 && y < board[x - 1].size() && board[x - 1][y] == word[local]) {
//        if (judge(board, word, x - 1, y, local + 1)) return true;
//    }
//    if (x - 1 >= 0 && y + 1 < board[x - 1].size() && board[x - 1][y + 1] == word[local]) {
//        if (judge(board, word, x - 1, y + 1, local + 1)) return true;
//    }
//
//    return false;
//}
//
//
//
//
//
//bool exist(vector<string>& board, string& word) {
//	// write code here
//
//
//	/*int x = board.size();
//	int y = board[0].size();*/
//
//	for (int x = 0; x < board.size(); x++)
//	{
//		for (int y = 0; y < board[x].size(); y++)
//		{
//			if (board[x][y] == word[0])
//			{
//				if (judge(board, word, x, y, 1) == true)
//					return true;
//			}
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
//	vector<string> board = { "XYZE","SFZ","XDEE" };
//	string word("XYZZED");
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
//    int digit = 0;
//    int carry_over = 0;
//
//    while (temp1!=nullptr&&temp2==nullptr)
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

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* reverse_list(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while (temp != nullptr) {
        ListNode* _next = temp->next;

        temp->next = prev;
        prev = temp;
        temp = _next;
    }

    return prev;
}

ListNode* addInList(ListNode* head1, ListNode* head2) {
    // write code here

    head1 = reverse_list(head1);
    head2 = reverse_list(head2);

    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    int digit = 0;
    int carry_over = 0;

    while (temp1 != nullptr && temp2 != nullptr) {
        digit = temp1->val + temp2->val + carry_over;
        carry_over = digit / 10;
        temp1->val = digit % 10;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    ListNode* uncompleted = temp1;
    if (temp2 != nullptr) {
        uncompleted = temp1;
    }

    while (uncompleted != nullptr) {
        digit = uncompleted->val + carry_over;
        carry_over = digit / 10;
        uncompleted->val = digit % 10;

        if (uncompleted->next == nullptr) {
            break;
        }

        uncompleted = uncompleted->next;
    }

    if (carry_over != 0) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

        newNode->val = 1;
        newNode->next = nullptr;

        uncompleted->next = newNode;
    }

    return reverse_list(head1);
}

int main()
{
    ListNode* list1 = new ListNode;
    list1->val;


    return 0;
}