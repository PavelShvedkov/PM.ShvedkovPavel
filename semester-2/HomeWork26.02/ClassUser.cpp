#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "User.h"

using namespace std;
int User::totalOnline = 0;

User::User()
{
	age = 2020 - 2000;
	strcpy(name, "name");
	programmingSkill = 0;
	gender;
	birthday = Date(1, 1, 2000);
	totalOnline++;
}

void User::setName(const char* name)
{
	if (strlen(name) > N)
	{
		throw std::invalid_argument(" Size your name too big");
	}

	strcpy(this->name, name);
}
void User::setProgrammingSkill(bool skill)
{
	programmingSkill = skill;
}
void User::setGender(Gender gender)
{
	this->gender = gender;
}
void User::setBirthday(Date date)//можно посчитать через день рождения
{
	birthday = date;
}

char* User::getName()const
{
	char* name = new char[N];

	strcpy(name, this->name);

	return name;
}
bool User:: getProgrammingSkill() const
{
	return this->programmingSkill;
}
Gender User::getGender()const
{
	return this->gender;
}
int User::getAge()const
{
	return this->age;
}

void User::registry(const char* name, bool programmingSkill, Date birthDay, Gender gender)
{
	age = 2020 - birthDay.getYear();
	setName(name);
	setProgrammingSkill(programmingSkill);
	setBirthday(birthDay);
	setGender(gender);
}
void User::profileInfo()
{
	for (int i = 30; i > 0; i--)
	{
		cout << "__";
	}

	cout << endl<<endl;
	cout << '\t' << '\t'<< "User name: " << this->getName() << endl;
	cout << '\t' << '\t'<< "Programming skill: " << (this->getProgrammingSkill() ? "Yes" : "No") << endl;
	cout<<'\t' << '\t'<< "Gender: " << (female==this->getGender()?"Female":"Male") << endl;
	cout<< '\t' << '\t'<< "Age: " << this->getAge() << endl;

	for (int i = 30; i > 0; i--)
	{
		cout << "__";
	}
}
void User::usersOnline()
{
	cout << " Total users online: " << this->totalOnline<<endl;
}


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