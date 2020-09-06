#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

String::String() :string(nullptr)
{
}
String::String(const char* source)
{
	int length = strlen(source);
	string = new char[length + 1];

	strcpy(string, source);
}
String::String(const String& other)
{
	int length = other.getLength();
	this->string = new char[length + 1];

	strcpy(string, other.string);
}
String::~String()
{
	delete[]string;
}

int String::getLength()const
{
	return strlen(string);;
}

char* String::getCharString() const
{
	char* buffer = new char[this->getLength() + 1];

	strcpy(buffer, this->string);

	return buffer;
}

String& String::operator=(const String& other)
{
	if (string)
	{
		delete[]string;
	}

	int newLength = other.getLength();

	this->string = new char[newLength + 1];

	strcpy(string, other.string);

	return *this;
}
bool String::operator==(const String& other) const
{
	if (this->string == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (other.string == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (this->getLength() != other.getLength())
	{
		return false;
	}

	for (int i=0; i < other.getLength(); ++i)
	{
		if ((this->string)[i] != other[i])
		{
			return false;
		}
	}

	return true;
}
bool String::operator!=(const String& other) const
{
	return !(*this == other);
}

	


String String::operator+(const String& term) const
{
	int length1 = this->getLength();
	int length2 = term.getLength();

	char* buffer = new char[length1+length2+1];

	for (int i = 0; i < length1; i++)
	{
		buffer[i] = (*this)[i];

	}	return String();
}

const char& String::operator[](int index) const
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return string[index];
}
char& String::operator[](int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return string[index];
}

ostream& operator<<(ostream& out, const String& source)
{
	cout << source.string;

	return out;
}
istream& operator>>(istream& in, String& destination)
{
	if (destination.string)
	{
		delete[]destination.string;
	}

	String buffer;
	char* ter = new char[100];
	in >> ter;

	destination.string = new char[strlen(ter) + 1];
	strcpy(destination.string, ter);
	delete[]buffer.string;

	return in;
}
