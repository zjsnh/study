#pragma once
#include<iostream>
#include<cassert>
#include<ctime>
using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;




class Date
{
	//友元声明
	friend ostream& operator<<(ostream& out, const Date& d);//减少拷贝
	friend istream& operator>>(istream& out, Date& d);//不要const 

	//friend std::ostream& operator<<(std::ostream& out, const time& d);//减少拷贝
	//friend std::istream& operator>>(std::istream& out, time& d);
public:
	Date(int year, int month, int day);

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	int getMonthdays(const int year, const int month);

	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;

	Date operator--(int);
	Date operator++(int);

	Date& operator--();
	Date& operator++();

	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};


//内联函数
inline ostream& operator<<(ostream& out, const Date& d)//减少拷贝
{
	out << d._year << "\\" << d._month << "\\" << d._day;
	out << endl;

	return out;
}

inline istream& operator>>(istream& in, Date& d)//不要const 
{
	in >> d._year >> d._month >> d._day;

	return in;
}


