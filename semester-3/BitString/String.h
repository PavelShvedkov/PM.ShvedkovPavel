#ifndef STRING_H
#define STRING_H
#include <fstream>

using namespace std;

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	
	int getLength()const;
	char* strToChar()const;

	void deleteString();
	String& operator = (const String&);
	String operator + (const String&)const;
	String operator + ( char)const;
	String operator - (const String&)const;
	bool operator == (const String&)const;
	const char& operator [](int)const;
	char& operator [](int);

	friend String operator +(char, const String&);
	friend ostream& operator << (ostream&, const String&);
	friend istream& operator>>(istream&, String&);
protected:
	char* string;
};
#endif // STRING_H

