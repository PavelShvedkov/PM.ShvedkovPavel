#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <fstream>
#include "String.h"

class Worker
{
public:
	Worker(const String,const String,const String, int, int);
	Worker(Worker&);
	Worker() :surname("Unknown"), initials("U W"), position("Unknown"), startYear(1), salary(1) {}
	Worker(const Worker&);

	void setSurname(const String&);
	void setInitials(const String&);
	void setPosition(const String&);
	void setStartYear(int);
	void setSalary(int);

	String getSurname()const;
	String getInitials()const;
	String getPosition()const;
	int getStartYear()const;
	int getSalary()const;

	friend ostream& operator <<(ostream&, const Worker&);
	friend istream& operator >>(istream&, const Worker&);
	Worker& operator =(const Worker&);

private:
	String surname;
	String initials;
	String position;
	int startYear;
	int salary;
};

#endif // !WORKER_H
