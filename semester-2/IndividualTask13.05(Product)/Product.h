#ifndef PRODUCT_H
#define PRODUCT_H
#include <fstream>
#include <iostream>

using namespace std;

const int N = 50;

class Date
{
public:
	Date() :day(01), month(01), year(2000) {};
	Date(int day, int month, int year)
	{
		if (isValidDate(day, month, year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			this->day = 1;
			this->month = 1;
			this->year = 2000;
		}
	}

	//Date& operator =(const Date&);
	static	bool isValidDate(int day, int month, int year)
	{
		if ((day < 1 || day>31) || (month < 1 || month>12))
		{
			cout << "Not valid date" << endl;
		}
		return true;
	}
	friend ostream& operator<<(ostream& out, const Date& date)
	{
		cout << date.day << "." << date.month << "." << date.year;

		return out;
	}
	friend istream& operator >>(istream& in, Date& date)
	{
		int d = 0, m = 0, y = 0;
		cout << " Enter day: ";
		cin >> d;
		cout << " Enter month: ";
		cin >> m;
		cout << " Enter year: ";
		cin >> y;

		Date other(d, m, y);
		date = other;
		return in;
	}
	bool operator ==(const Date& other)const
	{
		if (this->getDay()== other.getDay())
		{
			if (this->getMonth()== other.getMonth())
			{
				if (this->getYear()==other.getYear())
				{
					return true;
				}
			}
	}
		return false;
	}

	void setDay(int day)
	{
		if (isValidDate(day, this->month, this->year))
		{
			this->day = day;
		}
	}
	void setMonth(int month)
	{
		if (isValidDate(this->day, month, this->year))
		{
			this->month = month;
		}
	}
	void setYear(int year)
	{
		if (isValidDate(this->day, this->month, year))
		{
			this->year = year;
		}
	}
	int getDay()const
	{
		return day;
	}
	int getMonth()const
	{
		return month;
	}
	int getYear()const
	{
		return year;
	}

private:
	int day;
	int month;
	int year;
};

class Product
{
public:
	Product() {};
	Product(const char*, const char*, Date, int, int);
	~Product() {};
	void setProductName(const char*);
	void setGrade(const char*);
	void setDateOfIssue(Date);
	void setShelfLife(int);
	void setCost(int);
	void setProduct(const char*, const char*, Date, int, int);
	char* getProductName()const;
	char* getGrade()const;
	Date getDateOfIssue()const;
	Date getShelfLife()const;
	int getCost()const;

	friend ofstream& operator <<(ofstream& , const Product&);
	bool operator ==(const Product&) const;

	void enterProduct();
	void displayProduct();

private:
	char productName[N], grade[N];
	Date dateOfIssue, shelfLife;
	int cost;
};
#endif//PRODUCT_H
