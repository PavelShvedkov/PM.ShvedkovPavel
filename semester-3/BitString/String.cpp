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
	//delete[]string;
}

int String::getLength()const
{
	int length=0;

	if (string)
	{
		length = strlen(string);
	}

	return length;
}

char* String::strToChar() const
{
	int length = this->getLength();
	char* buffer = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		buffer[i] = (*this)[i];
	}

	buffer[length] = '\0';

	return buffer;
}

void String::deleteString()
{
	if (!string)
	{
		delete[]string;
	}
	string = 0;
	cout << " Deletion completed" << endl;
}

String& String::operator=(const String& other)
{
	if (string==other.string)
	{
		delete[]string;
	}

	int newLength = other.getLength();

	this->string = new char[newLength + 1];

	strcpy(string, other.string);

	return *this;
}

String String::operator+(const String& term) const
{
	int length1 = this->getLength();
	int length2 = term.getLength();
	int i = 0;

	char* buffer = new char[length1 + length2 + 1];

	for (; i < length1; i++)
	{
		buffer[i] = (*this)[i];
	}	
	
	for (int j = 0; j < length2; j++,i++)
	{
		buffer[i] = term[j];
	}

	buffer[i] = '\0';

	return buffer;
}

String String::operator+( char term) const
{
	int length1 = this->getLength();
	int i = 0;

	char* buffer = new char[length1 +  2];

	for (; i < length1; i++)
	{
		buffer[i] = (*this)[i];
	}

	buffer[i] = term;
	buffer[i+1] = '\0';

	return buffer;
}

bool String::operator==(const String& other) const
{

	return (bool)!strcmp(this->string,other.string);
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

String operator+(char symbol, const String& wort)
{
	int length1 = wort.getLength();
	int i = 0;

	char* buffer = new char[length1 + 2];

	buffer[i] = symbol;

	for (; i < length1; i++)
	{
		buffer[i+1] = wort[i];
	}

	buffer[i + 1] = '\0';

	return buffer;
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
