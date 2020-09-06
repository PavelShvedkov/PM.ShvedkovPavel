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
	char* getCharString()const;

	String& operator = (const String&);
	bool operator == (const String&)const;
	bool operator != (const String&)const;
	String& operator += (const String&);
	String& operator -= (const String&);
	String operator + (const String&)const;
	String operator - (const String&)const;
	const char& operator [](int)const;
	char& operator [](int);

	friend ostream& operator << (ostream&, const String&);
	friend istream& operator>>(istream&, String&);
private:
	char* string;
};
#endif // STRING_H

