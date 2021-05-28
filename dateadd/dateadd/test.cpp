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
	Date(int year = 2021, int month = 5, int day = 1, int add = 0)
	{
		_year = year;
		_month = month;
		_day = day;
		_add = 0;
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
private:
	int _year;
	int _month;
	int _day;
	int _add;
};
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day >> d._add;
	d + d._add;
	return in;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year <<  "-" << setfill('0') << setw(2) 
		<<d._month <<  "-" << setfill('0') << setw(2) <<d._day <<  endl;
	return out;
}

int main()
{
	int m = 0;
	cin >> m;
	while (m--)
	{
		Date d1;
		cin >> d1;
		cout << d1;
	}


	return 0;
}