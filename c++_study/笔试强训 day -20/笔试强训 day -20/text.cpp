#include<iostream>
using namespace std;

typedef long long ll;

//int main()
//{
//
//
//	pair<ll, ll> opposite;
//	pair<ll, ll> light;
//
//	/*cin >> opposite.first >> opposite.second;
//	cin >> light.first >> light.second;*/
//	opposite.first = 2;
//	opposite.second = 3;
//	light.first = 1;
//	light.second = 3;
//
//
//	ll harm = 0;
//	while (opposite.second > 0 && light.second > 0)
//	{
//		harm = harm + opposite.first + light.first;
//
//		opposite.second -= light.first;
//		light.second -= opposite.first;
//	}
//
//	if (opposite.second <= 0 && light.second > 0)
//	{
//		harm += light.first * 10;
//	}
//	else if (opposite.second > 0 && light.second <= 0)
//	{
//		harm += opposite.first * 10;
//	}
//
//	cout << harm << endl;
//
//	return 0;
//}


//#include<vector>
//#include<algorithm>
//
//int main()
//{
//	//vector<ll> arr = { 3,-4,5 };
//	vector<ll> arr;
//	ll b;
//	while (cin >> b)
//	{
//		arr.push_back(b);
//	}
//
//	ll Max = 0;
//	ll right = 0;
//
//	ll part = 0;
//	ll all = 0;
//	ll Min = 0;
//	ll between = 0;
//
//	int attachable = 0;
//
//	while (arr[right] > 0 && right < arr.size())
//	{
//		Max += arr[right];
//		right++;
//	}
//
//	if (right < arr.size())
//	{
//		Min = arr[right];
//		attachable = 1;
//		right++;
//	}
//
//	while (right < arr.size())
//	{
//
//		if (arr[right] < 0)
//		{
//
//			if (attachable)
//			{
//				all = Max + Min + part;
//			}
//			else
//			{
//				all = Min + part + between;
//			}
//
//			if (Max > all && Max > part)
//			{
//				attachable = 0;
//				between = part;
//			}
//			else
//			{
//				attachable = 1;
//				between = 0;
//				Max = max(all, part);
//			}
//
//
//			right++;
//			part = 0;
//			Min = arr[right];
//			continue;
//		}
//
//		part += arr[right];
//		right++;
//	}
//
//	if (attachable)
//	{
//		all = Max + Min + part;
//	}
//	else
//	{
//		all = Min + part + between;
//	}
//
//	Max = max(Max, max(all, part));
//
//	cout << Max << endl;
//
//	return 0;
//}



#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

bool palindromic(string str) {
    string copy = str;

    reverse(str.begin(), str.end());

    if (copy == str)
        return true;

    return false;
}

int main()
{
    string str;
    cin >> str;
    int num = 0;
    if (str.size() > 0)
    {
        if (palindromic(str))
        {
            num = str.size() - 1;
            str.pop_back();
            if (palindromic(str))
            {
                num = 0;
            }
        }
        else {
            num = str.size();
        }
    }

    cout << num << endl;

    return 0;
}