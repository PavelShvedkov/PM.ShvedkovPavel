#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"

using namespace std;

Worker::Worker(const String surname,const String initials,const String position, int startYear, int salary)
{
	setSurname(surname);
	setInitials(initials);
	setPosition(position);
	setStartYear(startYear);
	setSalary(salary);
}
Worker::Worker(Worker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());
}
 Worker::Worker(const Worker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());
}


void Worker::setSurname(const String& name)
{
	if (name[0]=='/0')
	{
		throw std::invalid_argument(" Surname can't be zero!!!");
	}

	this->surname = name;
}
void Worker::setInitials(const String& initials)
{
	if (initials[0] == '/0')
	{
		throw std::invalid_argument(" Initials can't be zero!!!");
	}

	if (!(strtok(initials.getCharString()," ")))
	{
		throw std::invalid_argument(" Initials must be separated by a space!!!");
	}
	this->initials = initials;
}
void Worker::setPosition(const String& position)
{
	if (position[0] == '/0')
	{
		throw std::invalid_argument(" Position can't be zero!!!");
	}

	this->position = position;
}
void Worker::setStartYear(int startYear)
{
	if (startYear <0)
	{
		throw std::invalid_argument(" Start year can't be zero!!!");
	}

	this->startYear = startYear;
}
void Worker::setSalary(int salary)
{
	if (salary < 0)
	{
		throw std::invalid_argument(" Salary must be positive!!!");
	}

	this->salary = salary;
}

String Worker::getSurname() const
{
	return surname;
}
String Worker::getInitials() const
{
	return initials;
}
String Worker::getPosition() const
{
	return position;
}
int Worker::getStartYear() const
{
	return startYear;
}
int Worker::getSalary() const
{
	return salary;
}

Worker& Worker::operator=(const Worker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());

	return *this;
}

ostream& operator<<(ostream& out, const Worker& object)
{
	out <<"Surname: "<< object.getSurname()<<endl;
	out << "Initials: " << object.getInitials() << endl;
	out << "Position: " << object.getPosition() << endl;
	out << "Start year:" << object.getStartYear() << endl;
	out << "Salary:" << object.getSalary() << endl;

	return out;
}
istream& operator>>(istream& in, Worker& object)
{
	String buffer;
	int intBuffer = 0;
	
	in >> buffer;
	object.setSurname(buffer);
	in >> buffer;
	object.setInitials(buffer);
	in >> buffer;
	object.setPosition(buffer);
	in >> intBuffer;
	object.setStartYear(intBuffer);
	in >> intBuffer;
	object.setSalary(intBuffer);

	return in;
}
