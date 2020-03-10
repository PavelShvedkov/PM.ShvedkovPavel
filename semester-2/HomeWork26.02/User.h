#include <iostream>
#include <time.h>

using namespace std;

const int N = 20;
enum Gender { gender, male, female };
enum MonthNumber { smallMonth = 1, februar };

struct Date
{
public:

	Date();
	Date(int , int , int );

	void setData(int, int , int );

	int getYear()const;
	int getMonth()const;
	int getDay()const;


private:
	int day;
	int month;
	int year;
};

class User
{
public:

	User();

	void setName(const char*);
	void setProgrammingSkill(bool);
	void setGender(Gender);
	void setBirthday(Date);

	char* getName()const;
	bool getProgrammingSkill()const;
	Gender getGender()const;
	int getAge()const;

	void registry(const char*, bool, Date ,Gender);
	void profileInfo();
	void usersOnline();

private:
	static int totalOnline;
	int age;
	char name[N];
	bool programmingSkill;
	Gender gender;
	Date birthday;
};



