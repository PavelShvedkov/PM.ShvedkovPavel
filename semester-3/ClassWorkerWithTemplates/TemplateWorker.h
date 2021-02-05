#ifndef TemplateWorker_H
#define TemplateWorker_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

using namespace std;
template<class D, class M>
class TemplateWorker;

//template<class D,class M>
//ostream& operator << <D, M>(ostream&, const TemplateWorker<D, M>&);
//template<class D, class M>
//istream& operator >> <D, M>(istream&, TemplateWorker<D,M>&);

template<class D,class M>
class TemplateWorker
{
public:
	TemplateWorker(const string, const string, const string, D, M);
	TemplateWorker(TemplateWorker&);
	TemplateWorker() :surname("Unknown"), initials("U W"), position("Unknown"), startYear(1), salary(1) {}//инициализатор в к-е
	TemplateWorker(const TemplateWorker&);

	void setSurname(const string&);
	void setInitials(const string&);
	void setPosition(const string&);
	void setStartYear(D);
	void setSalary(M);

	string getSurname()const;
	string getInitials()const;
	string getPosition()const;
	D getStartYear()const;
	M getSalary()const;

	friend ostream& operator << <D,M>(ostream&, const TemplateWorker<D,M>&);
	friend istream& operator >> <D,M>(istream&,  TemplateWorker&);
	TemplateWorker& operator =(const TemplateWorker&);

private:
	string surname;
	string initials;
	string position;
	D startYear;//инстанцировать поля своими классами через темплэйт
	M salary;
};

template<class D,class M>
TemplateWorker<D,M>::TemplateWorker(const string surname, const string initials, const string position, D startYear, M salary)
{
	setSurname(surname);
	setInitials(initials);
	setPosition(position);
	setStartYear(startYear);
	setSalary(salary);
}

template<class D , class M >
TemplateWorker<D, M>::TemplateWorker(TemplateWorker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());
}

template<class D , class M >
TemplateWorker<D, M>::TemplateWorker(const TemplateWorker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());
}

template<class D , class M >
void TemplateWorker<D, M>::setSurname(const string& name)
{
	if (name[0] == '/0')
	{
		throw std::invalid_argument(" Surname can't be zero!!!");
	}

	this->surname = name;
}
template<class D, class M>
void TemplateWorker<D, M>::setInitials(const string& initials)
{
	if (initials[0] == '/0')
	{
		throw std::invalid_argument(" Initials can't be zero!!!");
	}

	if (!(initials.find(" ")))
	{
		throw std::invalid_argument(" Initials must be separated by a space!!!");
	}
	this->initials = initials;
}
template<class D, class M >
void TemplateWorker<D, M>::setPosition(const string& position)
{
	if (position[0] == '/0')
	{
		throw std::invalid_argument(" Position can't be zero!!!");
	}

	this->position = position;
}
template<class D, class M>
void TemplateWorker<D, M>::setStartYear(D startYear)
{
	this->startYear = startYear;
}
template<class D , class M >
void TemplateWorker<D, M>::setSalary(M salary)
{
	this->salary = salary;
}

template<class D , class M >
string TemplateWorker<D, M>::getSurname() const
{
	return surname;
}
template<class D , class M >
string TemplateWorker<D,M>::getInitials() const
{
	return initials;
}
template<class D , class M>
string TemplateWorker<D, M>::getPosition() const
{
	return position;
}
template<class D,class M>
D TemplateWorker<D, M>::getStartYear() const
{
	return startYear;
}
template<class D , class M>
M TemplateWorker<D, M>::getSalary() const
{
	return salary;
}

template<class D, class M >
TemplateWorker<D,M>& TemplateWorker<D, M>::operator=(const TemplateWorker& other)
{
	setSurname(other.getSurname());
	setInitials(other.getInitials());
	setPosition(other.getPosition());
	setStartYear(other.getStartYear());
	setSalary(other.getSalary());

	return *this;
}

template<class D , class M >
ostream& operator<<(ostream& out, const TemplateWorker<D,M>& object)
{
	out << "Surname: " << object.getSurname() << endl;
	out << "Initials: " << object.getInitials() << endl;
	out << "Position: " << object.getPosition() << endl;
	out << "Start year:" << object.getStartYear() << endl;
	out << "Salary:" << object.getSalary() << endl;

	return out;
}
template<class D , class M >
istream& operator>>(istream& in, TemplateWorker<D, M>& object)
{
	string buffer;
	D dateBuffer;
	M moneyBuffer;

	in >> buffer;
	object.setSurname(buffer);
	in >> buffer;
	object.setInitials(buffer);
	in >> buffer;
	object.setPosition(buffer);
	in >> dateBuffer;
	object.setStartYear(dateBuffer);
	in >> moneyBuffer;
	object.setSalary(moneyBuffer);

	return in;
}

#endif TEMPLATEWORKER_H// !

