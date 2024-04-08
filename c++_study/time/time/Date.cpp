#pragma once
#include"time.h"


Date::Date(int year = 1970, int month = 1, int day = 1)
{
	assert(0 < month && month <= 12 && day <= getMonthdays(year, month));

	_year = year;
	_month = month;
	_day = day;
}

int Date::getMonthdays(const int year, const int month)
{
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	
	return months[month];
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year 
		&&_month == d._month 
		&&_day == d._day;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator<(const Date& d) const
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator<=(const Date& d) const
{
	return (*this == d) && (*this < d);
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}


bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}



Date& Date::operator+=(int day)
{

	if (day < 0)
	{
		*this -= -day;
		return *this;
	}

	_day += day;

	while (_day > getMonthdays(_year, _month))
	{
		++_month;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}

		_day -= getMonthdays(_year, _month);
	}

	return *this;
}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month == 13)
//		{
//			++tmp._year;
//			tmp._month = 1;
//		}
//	}
//
//	return tmp;
//}


Date Date::operator+(int day) const
{
	Date temp = *this;
	return temp += day;
}

Date& Date::operator-=(int day)
{

	if (day < 0)
	{
		*this += -day;
		return *this;
	}

	_day -= day;

	while (_day >= 0)
	{
		--_month;

		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += getMonthdays(_year, _month);
	}

	return *this;
}


Date Date::operator-(int day) const
{
	Date temp = *this;
	return temp -= day;
}

Date& Date::operator--(int)
{
	Date temp = *this;

	(*this) -= 1;
	return temp;
}

Date& Date::operator++(int)
{
	Date temp = *this;

	(*this) += 1;
	return temp;
}

Date& Date::operator--()
{
	(*this) -= 1;
	return *this;
}

Date& Date::operator++()
{
	(*this) += 1;
	return *this;
}


int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;

	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;

	}

	int count = 0;

	while (min > max)
	{
		++max._day;
		++count;
	}

	/*while (min > max)
	{
		++max._day;
		++count;
	}*/
	//ºı…Ÿ±»Ωœ

	return flag * count;
}
