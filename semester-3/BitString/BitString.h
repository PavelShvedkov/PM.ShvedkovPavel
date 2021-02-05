#ifndef BITSTRING_H
#define BITSTRING_H

#include "String.h"
#include <iostream>;

using namespace std;

class BitString :
	public String
{
public:
	BitString();
	BitString(const char*);
	BitString(const BitString&);
	BitString(const String&);

	BitString& operator+(const BitString&)const;
	bool operator==(const BitString&);
	BitString& operator = (const BitString&);

protected:
	static char* addCode(const char*);
	bool sign;
};
//формирование дополнительного кода: 0010->1101+1=1110->0001+1=0010

#endif BITSTRING_H