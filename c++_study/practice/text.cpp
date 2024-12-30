#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>


std::vector<int> split(const std::string& str,std::string s)
{
	int _start = 0;
	int pos = 0;
	std::vector<int> ver;
	while (std::string::npos)
	{
		pos = str.find(s, _start);
		ver.push_back(atoi(str.substr(_start, pos - _start).c_str()));
		_start = pos + 1;
	}

	ver.push_back(atoi(str.substr(_start).c_str()));

	return ver;
}

bool leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days(int month, bool flag)
{
	int months[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (flag && month == 2)
		return 29;

	return months[month];
}

int days(const std::vector<int>& time, const std::vector<int>& _time)
{
	int _days = 0;
	int year1 = time[0];
	int year2 = _time[0];
	while (year1 > year2)
	{
		if (leap(year2))
		{
			_days += 366;
		}
		_days += 365;
	}


}


int main()
{
	string str;
	cin >> str;
	std::vector<int> time = split(str, " ");
	std::vector<int> _time = { 2000,1,1,6 };
	int day_size = 0;
	

	return 0;
}