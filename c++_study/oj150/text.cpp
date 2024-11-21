#include <vector>
#include <iostream>

using namespace std;

//bool Reachable(vector<int>& gas, vector<int>& cost,int pos)
//{
//	int count = gas.size();
//	int _gas = gas[pos];
//	while (count--)
//	{
//		_gas -= cost[pos];
//		pos++;
//		pos %= gas.size();
//
//		if (_gas < 0)
//		{
//			return false;
//		}
//
//		_gas += gas[pos];
//
//	}
//
//	return true;
//}


//
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//
//	int nums = 0, tnums = 0, pos = 0;
//
//	for (int i = 0; i < gas.size(); i++)
//	{
//		nums += gas[i] - cost[i];
//		tnums += gas[i] - cost[i];
//
//		if (nums < 0)
//		{
//			nums = 0;
//			pos = i + 1;
//		}
//	}
//
//	if (tnums < 0)
//	{
//		return -1;
//	}
//
//	return pos;
//
//
//}
//
//int main()
//{
//	vector<int> gas = { 1, 2, 3, 4, 5 };
//	vector<int> cost = { 3,4,5,1,2 };
//
//	canCompleteCircuit(gas, cost);
//	return 0;
//}
//
//int lengthOfLastWord(string s) {
//    int pos = s.size() - 1;
//
//
//    while (pos >= 0 && s[pos] == ' ') {
//        pos--;
//    }
//
//    int length = 0;
//    while (pos >= 0 && s[pos] != ' ') {
//        length++;
//        pos--;
//    }
//
//    return length;
//}
//
//int main()
//{
//    cout << lengthOfLastWord("a");
//    return 0;
//}

//int _same(string& str1, string& str2)
//{
//	int same = 0;
//	int size = str1.size();
//	if (str1.size() > str2.size())
//	{
//		size = str2.size();
//	}
//
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (str1[i] == str2[i])
//		{
//			same++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	return same;
//}
//
//
//
//string longestCommonPrefix(vector<string>&strs) {
//	int same = strs[0].size();
//
//	for (int i = 1; i < strs.size(); i++)
//	{
//		same = _same(strs[0], strs[i]);
//		if (same == 0)
//		{
//			return " ";
//		}
//	}
//
//	return strs[0].substr(0, same);
//}

#include<sstream>
//string reverseWords(string s) {
//	std::stringstream ss(s);
//	std::string str;
//
//	std::string temp;
//
//	ss >> temp;
//	reverse(temp.begin(),temp.end());
//	str = temp;
//	while (ss >> temp)
//	{
//		str += " ";
//		reverse(temp.begin(), temp.end());
//		str += temp;
//	} 
//	reverse(str.begin(), str.end());
//
//	return str;
//}


string convert(string s, int numRows) {

	////text

}


int main()
{
	
	
	return 0;
}
