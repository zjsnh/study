#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>


//2
//5 3
//WWWLW
//5 3
//WLLLL

//int main()
//{
//	int a;
//	cin >> a;
//
//	int size;
//	int grade;
//
//	string chess("WLLLL");
//
//	while (cin >> size >> grade >> chess)
//	{
//		int cur = 0;
//		int success = 0;
//		for (int i = 0; i < chess.size(); i++)
//		{
//			if (chess[i] == 'W')
//			{
//				++success;
//				cur += (success >= 3) ? grade : 1;
//				continue;
//			}
//			success = 0;
//			cur += -1;
//
//		}
//		cout << cur << endl;
//	}
//
//	
//
//	return 0;
//}


//int maxLength(vector<int>& arr) {
//     write code here
//
//    unordered_map<int, int>  Map;
//
//    int distance = 1;
//    Map[arr[0]];
//    int right = 0;
//    int left = 0;
//    while (right < arr.size()) {
//
//        if (Map.count(arr[right]) && Map[arr[right]] >= left) {
//            left = Map[arr[right]] + 1;
//        }
//
//        distance = max(distance, right - left + 1);
//        Map[arr[right]] = right;
//        right++;
//    }
//    return distance;
//}
//
//int main()
//{
//    vector<int> arr = { 2,2,3,4,3 };
//    int length = maxLength(arr);
//
//    cout << length << endl;
//    
//    return 0;
//}

// string char vector int

#include<algorithm>

pair<char, char> find_max_and_second_max(const unordered_map<char, int>& map) {
    char max_char = '\0', second_max_char = '\0';
    int max_value = std::numeric_limits<int>::min();
    int second_max_value = std::numeric_limits<int>::min();

    for (const auto& kv : map) {
        if (kv.second > max_value) {
            second_max_value = max_value;
            second_max_char = max_char;
            max_value = kv.second;
            max_char = kv.first;
        }
        else if (kv.second > second_max_value && kv.second < max_value) {
            second_max_value = kv.second;
            second_max_char = kv.first;
        }
    }

    return { max_char, second_max_char };
}

bool yes_or_on(const unordered_map<char, int>& map)
{
    int length = 0;
    int Max = 0;
    for (auto& e : map)
    {
        Max = max(e.second, Max);
        length += e.second;
    }
    length -= Max;

    return length + 1 >= Max;
}



int main()
{
	string str("aabbccc");
	sort(str.begin(), str.end());
	unordered_map<char, int> M;

	for (auto& e : str)
	{
		M[e]++;
	}

    if (!yes_or_on(M))
    {
        cout << "no" << endl;
        return 0;
    }

    string _str;

    while (!M.empty()) {
        std::pair<char, char> S = find_max_and_second_max(M);

        if (S.first != '\0') {
            _str += S.first;
            M[S.first] -= 1;
            if (M[S.first] == 0) {
                M.erase(S.first);
            }
        }

        if (S.second != '\0') {
            _str += S.second;
            M[S.second] -= 1;
            if (M[S.second] == 0) {
                M.erase(S.second);
            }
        }
    }

    cout << _str << endl;


	return 0;
}