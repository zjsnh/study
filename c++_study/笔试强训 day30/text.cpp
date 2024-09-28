//#include<iostream>
//using namespace std;
//using ll = long long;
//
//bool even(const ll& num) {
//    return (num % 2) == 0;
//}
//
//bool prime_num(const ll& num) {
//    if (num <= 1) return false; 
//    for (ll i = 2; i * i <= num; ++i) {
//        if (num % i == 0) return false; 
//    }
//    return true;
//}
//
//int main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        ll a, b;
//        cin >> a >> b;
//
//        if ((even(a) || even(b)) || (a != 1 && b != 1)) {
//            cout << "NO" << endl;
//            continue;
//        }
//        
//        if (prime_num(a * b)) {
//            cout << "YES" << endl;
//            continue;
//        }
//        else
//        {
//            cout << "NO" << endl;
//            continue;
//        }
//    }
//}




//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//// ->  ÅÅÐò ±éÀú
//using ll = long long;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	vector<ll> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	sort(v.begin(), v.end());
//
//	int fast = 0, slow = 0;
//
//	int num = 0;
//	int _num = 0;
//	while (fast < v.size()&& slow <= fast)
//	{
//		if (v[fast] - v[slow] <= k)
//		{
//			if ((fast - slow + 1) > num)
//			{
//				num = fast - slow + 1;
//			}
//
//			fast++;
//		}
//		else
//		{
//			slow++;
//		}
//	}
//
//	cout << num << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>


//else
//{
//	num = max(num, (int)v.size());
//	v.clear();
//	++_num;
//	i = _num;
//}

//¶ÌµÄÊÇs1
int length_s(const string& s1, const string& s2) {
    int num = 0;
    vector<char> v;
    int _num = 0;

    int circulate = 0;
    int pos = 0;

    for (int i = 0; i < s1.size(); i++) {
        v.push_back(s1[i]);

        for (int j = pos; j < s2.size(); j++) {
            if (s2[j] == v.back()) {
                pos = j + 1;
                _num++; 
                break; 
            }

            if (i == s1.size() - 1 && j == s2.size() - 1)
            {

                num = max(_num, num);
                if (++circulate == s1.size())
                {
                    return num;
                }

                i = circulate - 1;
                _num = 0;
                pos = 0;
                v.clear();
                break;
            }

        }

    }

    return num; 
}

int main()
{
	int a, b;
	cin >> a >> b;

    string _short;
    string _long;


    if (a > b)
    {
        cin >> _long >> _short;
    }
    else
    {
        cin >> _short >> _long;
    }



	cout << length_s(_short, _long) << endl;

	return 0;
}
