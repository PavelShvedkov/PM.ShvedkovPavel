#include "Date.h"


Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int day, int month, int year)
{
	setData(day, month, year);
}

void Date::setData(int day, int month, int year)//дату не членить
{
	if (year < 0)
	{
		throw std::invalid_argument(" ");
	}

	bool leapYear = 1;

	this->year = year;

	if (!(year % 4))
	{
		leapYear = 1;
	}
	else if (!(year % 100))
	{
		if (!(year % 400))
		{
			leapYear = 1;
		}
		else
		{
			leapYear = 0;
		}
	}
	else
	{
		leapYear = 1;
	}

	if (month < 0 || month>12)
	{
		throw std::invalid_argument(" ");
	}

	this->month = month;

	int sizeMonth = 0;

	if (month == 4 || month == 6 || month == 9 || month == 11)//1,3,5,7,8,10,12-31  4,6,9,11-30
	{
		sizeMonth = smallMonth;
	}
	else if (month == 2)
	{
		sizeMonth = februar;
	}

	switch (sizeMonth)
	{
	case smallMonth:
		if (day < 0 || day>30)
		{
			throw std::invalid_argument(" ");
		}
		this->day = day;
		break;
	case februar:
		if (leapYear)
		{
			if (day < 0 || day>29)
			{
				throw std::invalid_argument(" ");
			}

			this->day = day;
		}
		else
		{
			if (day < 0 || day>28)
			{
				throw std::invalid_argument(" ");
			}
			this->day = day;
		}
		break;
	default:
		if (day < 0 || day>31)
		{
			throw std::invalid_argument(" ");
		}
		this->day = day;
		break;
	}
}
int Date::getYear()const
{
	return year;
}
int Date::getMonth()const
{
	return month;
}
int Date::getDay()const
{
	return day;
}

ostream& operator <<(ostream& out, const Date& object)
{
	out << object.getDay() << '.' << object.getMonth() << '.' << object.getYear();

	return out;
}
istream& operator >>(istream& in,  Date& object)
{
	int bufferDay=0, bufferMonth = 0, bufferYear = 0;

	in >> bufferDay;
	in >> bufferMonth;
	in >> bufferYear;
	object.setData(bufferDay, bufferMonth, bufferYear);

	return in;
}