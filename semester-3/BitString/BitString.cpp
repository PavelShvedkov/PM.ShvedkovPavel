#define _CRT_SECURE_NO_WARNINGS
#include "BitString.h"

BitString::BitString() :String()
{

}

BitString::BitString(const char* source)
{
	int maxSize = 9;
	char* buffer;
	int length = strlen(source);

	if (length > 8)
	{
		throw std::out_of_range("Overflow buffer");
	}

	string = new char[maxSize];
	sign = 0;

	for (int i = 0; i < length; ++i)
	{
		if (source[i] != '1' && source[i] != '0'&& source[i] != '-')
		{
			string = nullptr;
			return;
		}

		if (source[i]=='-')
		{
			string[0] = '1';
			sign = 1;
			continue;
		}

		string[maxSize-1-length+i] = source[i];
	}

	for (int i = sign; i < maxSize  - length-!(sign); i++)
	{
		string[i] = '0';
	}

	string[maxSize-1] = '\0';

	if (sign)
	{
		string = addCode(string);
	}
}

BitString::BitString(const BitString& other)
{
	if (this->string==other.string)
	{
		return;
	}

	if (string)
	{
		delete[]string;
	}

	string = new char[other.getLength() + 1];

	this->sign = other.sign;
	strcpy(string, other.string);
}

BitString::BitString(const String& source):BitString(source.strToChar())
{
	/*char* buffer = source.strToChar();
	 
	BitString(buffer);*/
}

BitString& BitString::operator+(const BitString& other) const
{
	int len1 = this->getLength();
	int len2 = other.getLength();

	if (!len1 || !len2)
	{
		BitString* buffer=new BitString;
		if (!len1)
		{
			 *buffer=other;
		}
		else
		{
			if (!len2)
			{
				 *buffer=*this;
			}
		}

		return *buffer;
	}

	String ls1 = other;
	String ls2 =  *this;
	String result;

	int carry = 0;

	for (int i = ls2.getLength() - 1; i >= 0; --i)
	{
		int bit1 = ls1[i] - '0'; // '0' => 0, '1' => 1
		int bit2 = ls2[i] - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result =  sum+result;
		carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
	}

	if (carry)
	{
		result = '1'+result;
	}

	if (result==String("10000000"))
	{
		result = "0";
	}

	BitString* buffer=new BitString(result);

	return *buffer;
}

bool BitString::operator==(const BitString& other)
{
	if (other[0]!=(*this)[0])
	{
		return false;
	}

	bool answer = 1;
	
	int len1 = this->getLength();
	int len2 = other.getLength();

	String ls1 = len1 < len2 ? *this : other;
	String ls2 = len1 < len2 ? other : *this;

	for (int i = ls1.getLength(); i < ls2.getLength(); ++i)
	{
		ls1 = '0'+ls1;
	}
	
	for (int i = 0; i < ls2.getLength(); i++)
	{
		if (ls2[i] != ls1[i])
		{
			answer = 0;
		}
	}

	return answer;
}

BitString& BitString::operator=(const BitString& other)
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

char* BitString::addCode(const char* source)
{
	int length = strlen(source);
	char* buffer = new char[length];
	strcpy(buffer, source);

	for (int i = 0; i < length; i++)
	{
		if (source[i]=='0')
		{
			buffer[i] = '1';
		}
		else
		{
			buffer[i] = '0';
		}
	}

	for (int i = length-1; i>0; --i)
	{
		if (buffer[i] == '0')
		{
			buffer[i] = '1';
			break;
		}
		else
		{
			buffer[i] = '0';
		}
	}

	return buffer;
}
