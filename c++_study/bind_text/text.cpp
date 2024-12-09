
//#include <iostream>
//#include <functional>
//#include <string>
//
//void print(std::string str)
//{
//	std::cout << str << std::endl;
//}
//
//
//int main()
//{
//	auto func = std::bind(printf, "hello");
//	func();
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//std::vector<std::string> split_string(const std::string& s, const std::string& _s) {
//	std::vector<std::string> str;
//	size_t start = 0;
//	size_t end = s.find(_s);
//
//	while (end != std::string::npos) {
//		str.push_back(s.substr(start, end - start));
//		start = end + _s.length();
//		end = s.find(_s, start);
//	}
//
//	str.push_back(s.substr(start));
//	return str;
//}
//
//
//std::string merge(std::vector<std::string>& split, const std::string& _s)
//{
//
//	auto it = split.begin();
//	std::string str;
//	str += *it;
//	it++;
//	while (it != split.end())
//	{
//		str += _s;
//		str += *it;
//		it++;
//	}
//
//	return str;
//}
//
//bool is(int num) {
//	if (num <= 1) return false; 
//
//
//	for (int i = 2; i <= num*num; ++i) {
//
//		if (num % i == 0) return false;
//	}
//	return true;
//}
//
//std::vector<int> find(int n) {
//
//	std::vector<int> v;
//	for (int i = 2; i <= n; ++i) {
//		if (is(i)) {
//			v.push_back(i);
//		}
//	}
//
//	return v;
//}
//
//#include <unordered_map>
//
//int find_same_num(std::vector<int> nums)
//{
//	std::vector<int> num(1000, 0);
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		num[nums[i]]++;
//
//		if (num[nums[i]] == 2)
//		{
//			return nums[i];
//		}
//	}
//
//}
//
//
//
//int main()
//{
//	std::string s;
//	std::cin >> s;
//
//	vector<string> _str;
//	
//	string _s;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if ((i + 1) < s.size() && s[i] == '&' && s[i + 1] == '&')
//		{
//			i += 2;
//			_str.push_back(_s);
//		}
//
//		_s += s[i];
//	}
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <string>

std::string path;
std::vector<std::string> ret;

void traceback(std::string& nums, std::vector<int>& res ,int size) {
    if (path.size() == size)
        ret.push_back(path);

    for (int i = 0; i < nums.size(); i++) {
        if (res[i] == 0) {
            path+=nums[i];
            res[i] = 1;
            traceback(nums, res, size);
            path.pop_back();

            res[i] = 0;
        }
    }
}


void trace()
{
    std::string s = "abcdefghijklmnopqrstuvwxyz";
    std::vector<int> res(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        traceback(s, res, i);
    }

}

int last(int n, int m) {
    std::vector<int> dp(n + 1, 0);

    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + m) % i;
    }

    return dp[n] + 1; 
}


int main()
{

}