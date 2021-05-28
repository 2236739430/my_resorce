#include <iostream>
#include <ostream>
#include<iomanip>


using namespace std;


class Date{
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	int getmonthday(int year, int month)
	{
		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = monthday[month];
		if (((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) && month == 2)
		{
			day = 29;
		}
		return day;
	}
	Date(int year = 2021, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = 1;
		_day = 0;
	}
	Date& operator+(int day)
	{
		_day += day;
		while (_day > getmonthday(_year, _month))
		{
			_day -= getmonthday(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	int operator-(const Date& d)
	{
		int yearday = 365;//每年天数
		if ((_year % 400) == 0 || ((_year % 4) == 0 && (_year % 100) != 0))
		{
			yearday = 366;
		}
		int monthday = 0;//差了几个月的天数
		for (int i = d._month; i < _month; i++)
		{
			monthday += getmonthday(d._year, i);
		}
		if (_month < d._month)//计算少月天数
		{
			for (int i = _month; i < d._year; i++)
			{
				monthday += getmonthday(d._year, i);
			}
			monthday *= -1;
		}
		if ((_year - d._year) < 0)//差了几年
		{
			monthday *= -1;
		}
		int dayday = _day - d._day;
		return (_year - d._year)*yearday + monthday + dayday;
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator<<(ostream& out, const Date& d)//setfill('0') << setw(2) 等价于%2d
{
	out << d._year << "-" << setfill('0') << setw(2)
		<< d._month << "-" << setfill('0') << setw(2) << d._day << endl;
	return out;
}


int main()
{
	Date d1;
	while (cin >> d1)
	{
		Date d2(d1);
		cout << (d1 - d2);
	}

	return 0;
}