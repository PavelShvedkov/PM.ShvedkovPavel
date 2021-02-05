#include <iostream>

using namespace std;
enum MonthNumber { smallMonth = 1, februar };

class Date
{
public:

	Date();
	Date(int, int, int);

	void setData(int, int, int);

	int getYear()const;
	int getMonth()const;
	int getDay()const;

	friend ostream& operator <<(ostream&, const Date&);
	friend istream& operator >>(istream&,  Date&);

private:
	int day;
	int month;
	int year;
};
