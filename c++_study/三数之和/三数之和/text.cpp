#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

//vector<vector<int>> threeSum(vector<int>& nums) {
//    vector<vector<int>> Nums;
//
//    sort(nums.begin(), nums.end());
//    int left = 0;
//    int right = nums.size() - 1;
//
//    int k = left + 1;
//    while (left+2 <= right)
//    {
//        if (nums[left] > 0)
//            break;
//
//        if (nums[k] + nums[right] + nums[left] == 0)
//        {
//
//            vector<int> Num = { nums[k],nums[right],nums[left] };
//            Nums.push_back(Num);
//            left++;
//            right--;
//
//        }
//        else if(nums[k] + nums[right] + nums[left] < 0)
//        {
//            k++;
//            if (k == right)
//            {
//                left++;
//                k = left + 1;
//            }
//        }
//        else 
//        {
//            right--;
//            k = left + 1;
//        }
//    }
//
//    return Nums;
//
//}

//int main()
//{
//    //vector<int> nums = { 0,0,0 };
//    vector<int> nums = { -1,0,1,2,-1,-4 };
//
//    vector<vector<int>> Nums = threeSum(nums);
//
//    
//
//
//    return 0;
//}


//int lengthOfLongestSubstring(string s) {
//
//    int length = 1;
//    int L = 1;
//    string str;
//    str += s[0];
//
//    for (int i = 1; i < s.size(); i++)
//    {
//        
//        size_t pos = str.find_first_of(s[i]);
//        str += s[i];
//        if (pos == -1)
//        {
//            L++;
//        }
//        else
//        {
//            str = str.substr(pos + 1);
//            length = max(L, length);
//            L = str.size();
//        }
//    }
//
//
//    length = max(L, length);
//
//    return length;
//
//}

//int main()
//{
//    string s("abcabcbb");
//    cout << lengthOfLongestSubstring(s) << endl;
//    return 0;
//}
//#include<unordered_map>
//vector<int> findAnagrams(string s, string p) {
//
//    vector<int> answer;
//    int w_start = 0, w_end = p.size() - 1;
//    unordered_map<char, int> M1;
//    unordered_map<char, int> M2;
//
//    for (int i = w_start; i <= w_end; ++i) {
//        M1[s[i]]++;
//    }
//    for (int i = 0; i < p.size(); ++i) {
//        M2[p[i]]++;
//    }
//
//    while (w_end < s.size()) {
//        if (M1 == M2) {
//            answer.emplace_back(w_start);
//        }
//
//        M1[s[w_start++]]--;
//        if (M1[s[w_start - 1]] == 0) 
//            M1.erase(s[w_start - 1]);
//
//        M1[s[++w_end]]++;
//    }
//
//    return answer;
//
//}
//
//int main()
//{
//    string s("cbaebabacd");
//    string p("abc");
//
//    findAnagrams(s, p);
//
//    return 0;
//}


//
//int subarraySum(vector<int>& nums, int k) {
//
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//
//	}
//	
//}
//
//int main()
//{
//	vector<int> nums = { 1,2,3 };
//	subarraySum(nums, 3);
//	return 0;
//}

#include <iostream>

int main() {
    const int i = 0;
    int& r = const_cast<int&>(i);
    r = 1;
    std::cout << &r << endl;
    std::cout << &i << endl;

    std::cout << r << endl;
    std::cout << i;

    return 0;
}