#include "year.h"

int Date::GetMonthDay(int year, int month)
{
	int dayarr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = dayarr[month];
	if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0))
	{
		day = 29;
	}
	return day;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	
	return *this;
}

Date::~Date()
{
	_year = 0;
	_month = 1;
	_day = 1;
}

//改变自己
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month += 1;
		if (_month > 12)
		{
			_year += 1;
			_month = 1;
		}
	}

	return *this;
}

//不改变自己
Date Date::operator+(int day)
{
	Date d1(*this);
	d1._day += day;
	while (d1._day > GetMonthDay(d1._year, d1._month))
	{
		d1._day -= GetMonthDay(d1._year, d1._month);
		d1._month += 1;
		if (d1._month > 12)
		{
			d1._year += 1;
			d1._month = 1;
		}
	}

	return d1;
}

Date Date::operator-(int day)
{
	Date d1(*this);
	d1._day -= day;
	while (d1._day < 0)
	{
		d1._month--;
		if (d1._month == 0)
		{
			d1._year--;
			d1._month = 13;//为了下次可以取到12月
		}
		d1._day += GetMonthDay(d1._year,d1._month);
	}
	return d1;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 13;//为了下次可以取到12月
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator++()
{
	_day++;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month += 1;
		if (_month > 12)
		{
			_year += 1;
			_month = 1;
		}
	}

	return *this;
}

bool Date::operator>(const Date& d)
{
	//检测年
	if (_year < d._year)
	{
		return false;
	}
	else if (_year > d._year)
	{
		return true;
	}
	//检测月
	if (_month < d._month)
	{
		return false;
	}
	else if (_month > d._month)
	{
		return true;
	}
	//检测日
	if (_day < d._day)
	{
		return false;
	}
	else if (_day > d._day)
	{
		return true;
	}

	//相等
	return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

inline bool Date::operator >= (const Date& d)
{
	if (_year < d._year)
	{
		return false;
	}
	else if (_year > d._year)
	{
		return true;
	}
	if (_month < d._month)
	{
		return false;
	}
	else if (_month > d._month)
	{
		return true;
	}
	if (_day < d._day)
	{
		return false;
	}

	return true;
}

bool Date::operator < (const Date& d)
{
	if (_year > d._year)
	{
		return false;
	}
	else if (_year < d._year)
	{
		return true;
	}
	if (_month > d._month)
	{
		return false;
	}
	else if (_month < d._month)
	{
		return true;
	}
	if (_day >= d._day)
	{
		return false;
	}

	return true;
}

bool Date::operator <= (const Date& d)
{
	if (_year < d._year)
	{
		return false;
	}
	else if (_year > d._year)
	{
		return true;
	}
	if (_month < d._month)
	{
		return false;
	}
	else if (_month > d._month)
	{
		return true;
	}
	if (_day > d._day)
	{
		return false;
	}

	return true;
}

bool Date::operator != (const Date& d)
{
	if (_year != d._year)
	{
		return true;
	}
	if (_month != d._month)
	{
		return true;
	}

	return _day != d._day;
}

int Date::operator-(const Date& d)
{
	int yearday = 365;
	if ((_year % 400) == 0 || ((_year % 4) == 0 && (_year % 100) != 0))
	{
		yearday = 366;
	}
	int monthday = 0;
	for (int i = d._month; i < _month; i++)
	{
		monthday += GetMonthDay(d._month, i);
	}
	if (_month < d._month)
	{
		for (int i = _month; i < d._month; i++)
		{
			monthday += GetMonthDay(d._month, i);
		}
		monthday *= -1;
	}
	if ((_year - d._year) < 0)
	{
		monthday *= -1;
	}
	int dayday = _day - d._day;
	return (_year - d._year)*yearday + monthday + dayday;
}