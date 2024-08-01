#include<iostream>
using namespace std;
#include<string>
#include<vector>

//string formatString(string str, vector<char>& arg) {
//    // write code here
//
//    string _str;
//    int i = 0;
//    for (int j = 0; j < str.size(); j++)
//    {
//        if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z'))
//        {
//            _str += str[j];
//        }
//        else
//        {
//            _str += arg[i];
//            i++;
//            j++;
//        }
//    }
//
//
//    while (i < arg.size())
//    {
//        _str += arg[i];
//        i++;
//    }
//
//    return _str;
//}
//
////"A%sC%sE",[B,D,F]
//
//int main()
//{
//    vector<char> arg = { 'B','D','F' };
//
//    cout << formatString("A%sC%sE", arg) << endl;
//
//    return 0;
//}

#include<algorithm>

//bool isPrime(int n)
//{
//    if (n <= 3) 
//        return n > 1;
//
//
//    for (int i = 2; i < n; i++) {
//        if (n % i == 0) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
////11 12 13 14 15 16 17 18 19 20
//
//int main() {
//    int left = 11;
//    int right = 20;
//    int num = 0;
//
//    for (int i = left; i <= right; i++) {
//        string str = to_string(i);
//        bool found = false;
//
//        for (int j = 0; j < str.size() - 1; j++) {
//            for (int k = j + 1; k < str.size(); k++) {
//                string _str1;
//                _str1 += str[j];
//                _str1 += str[k];
//
//                string _str2;
//                _str2 += str[k];
//                _str2 += str[j];
//
//                // 处理前导零的逻辑
//                int start_pos1 = _str1.find_first_not_of("0");
//                if (start_pos1 == string::npos || start_pos1 == 1) {
//                    _str1 = '1';
//                }
//
//                int start_pos2 = _str2.find_first_not_of("0");
//                if (start_pos2 == string::npos|| start_pos2 == 1) {
//                    _str2 = '1';
//                }
//
//                if (isPrime(stoi(_str1)) || isPrime(stoi(_str2))) {
//                    found = true;
//                    num++;
//                    break;
//                }
//            }
//
//            if (found) {
//                break;
//            }
//        }
//    }
//
//    cout << num << endl;
//
//    return 0;
//}	

    

//AACTGTGCACGACCTGA
//5


int main()
{
    string str = "ACGT";
    int distance = 2;
    int maxGCCount = 0;
    string maxSubstr;

    for (int i = 0; i <= str.size() - distance; i++) {
        int currentGCCount = 0;
        string substr = str.substr(i, distance);

        for (int j = 0; j < distance ; j++) {
            if (substr[j] == 'G' || substr[j] == 'C') {
                currentGCCount++;
            }
        }

        if (currentGCCount > maxGCCount) {
            maxGCCount = currentGCCount;
            maxSubstr = substr;
        }
    }

    cout << maxSubstr << endl;

    return 0;
}
