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


int maxLength(vector<int>& arr) {
    // write code here

    unordered_map<int, int>  Map;

    int distance = 1;
    //Map[arr[0]];
    int right = 0;
    int left = 0;
    while (right < arr.size()) {

        if (Map.count(arr[right]) && Map[arr[right]] >= left) {
            left = Map[arr[right]] + 1;
        }

        distance = max(distance, right - left + 1);
        Map[arr[right]] = right;
        right++;
    }
    return distance;
}

int main()
{
    vector<int> arr = { 2,2,3,4,3 };
    int length = maxLength(arr);

    cout << length << endl;
    
    return 0;
}