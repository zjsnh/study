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

#include<unordered_set>

vector<int> findAnagrams(string s, string p) {

	for (int i = 0; i < s.size() - p.size(); i++)
	{
		for (int j = i; j < p.size(); j++)
		{
			if()
		}
	}

}

int main()
{


	return 0;
}