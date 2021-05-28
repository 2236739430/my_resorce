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
//返回类型Date&，用于连续赋值时的情况
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
	if (day < 0)
	{
		(*this) -= (-day);
		return *this;
	}
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
	if (day < 0)
	{
		return (d1 - (-day));
	}
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
	if (day < 0)
	{
		return (d1 + (-day));
	}
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
	if (day < 0)
	{
		(*this) += (-day);
		return *this;
	}
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
//前置++，++完，Date&赋值时把*this直接赋值给后面
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
//后置++,int仅用于重载，赋值给前面再++
Date Date::operator++(int)
{
	Date d1(*this);
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

	return d1;
}
//前置--
Date& Date::operator--()
{
	(*this) -= 1;
	return *this;
}
//后置--

Date Date::operator--(int)
{
	Date d1(*this);
	(*this) -= 1;
	return d1;
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

bool Date::operator >= (const Date& d)
{
	/*if (_year < d._year)
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
	}*/

	return (*this) > d || (*this) == d;
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
	/*if (_year < d._year)
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
	}*/

	return (*this) < d || (*this) == d;
}

bool Date::operator != (const Date& d)
{
	/*if (_year != d._year)
	{
		return true;
	}
	if (_month != d._month)
	{
		return true;
	}*/

	return !((*this) == d);
}

int Date::operator-(const Date& d)
{
	int yearday = 365;//每年天数
	if ((_year % 400) == 0 || ((_year % 4) == 0 && (_year % 100) != 0))
	{
		yearday = 366;
	}
	int monthday = 0;//差了几个月的天数
	for (int i = d._month; i < _month; i++)
	{
		monthday += GetMonthDay(d._month, i);
	}
	if (_month < d._month)//计算少月天数
	{
		for (int i = _month; i < d._month; i++)
		{
			monthday += GetMonthDay(d._month, i);
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

void Date::print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl << endl;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}