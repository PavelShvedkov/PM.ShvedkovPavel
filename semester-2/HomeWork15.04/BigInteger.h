#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class BigInteger
{
public:
	BigInteger(const char*);
	BigInteger(BigInteger const&);
	~BigInteger();

	int getLength()const;
	char getDigit(int)const;
	void display()const;
	BigInteger displaySum(const BigInteger&);
	BigInteger displayDiff(const BigInteger&);
	void randomFill(int);

	char& operator [](const int);
	const char& operator [](const int)const;
	BigInteger& operator =(const BigInteger&);
	BigInteger& operator +=(const BigInteger&);
	BigInteger operator +(const BigInteger&)const;
	BigInteger& operator -=(const BigInteger&);
	BigInteger operator -(const BigInteger&)const;

private:
	char* digits;
	int digitLength;
	static bool isDataValid(const char*);
	void setDigitLength(int);
	void setDigits(const char*);
	static char* resize(const char*);
	static char* add(char*, char*);
	static char* subtract(char*, char*);
	static void swap(char*&, char*&);
	static int  toDigit(char);
	static char toChar(int);
};

ostream& operator <<(ostream&, const BigInteger&);

#endif BIGINTEGER_H