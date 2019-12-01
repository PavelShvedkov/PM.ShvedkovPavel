#pragma once
#include <iostream>
  
using namespace std;

bool isAlphabet(char);
bool isLower(char);
bool equivalenceStrings(char*, char*);
int compressionStrings(char*, char*);
int searchFirstSubstringIndex(char*, char*,bool=true);
int getLenght(const char*);
int compare(const char*, const char*, bool = true);
char* createString(const char*);
char toUpper(char);
void copyString(char*, const char*);
void runTestString();
void caseTestString(char*, char*,bool,int);
void deleteMemory(char*);

void deleteMemory(char* string)
{
	delete[]string;
}

void caseTestString(char* string, char* subString, bool sensitive, int expAnswer)
{
	if (searchFirstSubstringIndex(string,subString,sensitive) == expAnswer)
	{
		cout << " )))" << endl;
	}
	else
	{
		cout << " (((" << endl;
	}
}

void runTestString()
{
	bool flag = true;
	char string[] = " I am just Iron IRON man!";
	char subString[] = "IRON";
	caseTestString(string, subString,flag,16);

	 flag = false;
	char string2[] = " I am just Iron Man!";
	char subString2[] = "IRON";
	caseTestString(string2, subString2, flag,11);

	 flag = true;
	char string3[] = " I AM JUST IRON MAN!";
	char subString3[] = "Am";
	caseTestString(string3, subString3, flag,-1);
	
	 flag = true;
	char string4[] = " I am just Iron Man!";
	char subString4[] = "IRON";
	caseTestString(string4, subString4, flag,-1);
}

char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}

	return symbol;
}

bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}

bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}

char* createString(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int lenght = getLenght(source) + 1;

	char* target = new char[lenght];

	int i = 0;

	while (source[i])
	{
		target[i] = source[i];
		i++;
	}

	target[i] = '\0';

	return target;
}

void copyString(char* target, const char* source)
{
	if (target == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int targetLenght = getLenght(target);

	int sourceLenght = getLenght(source);

	if (targetLenght < sourceLenght)
	{
		throw std::invalid_argument("Lenght destination string!");
	}

	int i = 0;

	while (source[i])
	{
		target[i] = source[i];
		i++;
	}

	target[i] = '\0';
}

int compare(const char* lhs, const char* rhs, bool ordinal)
{
	if (lhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	if (rhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int lhsLenght = getLenght(lhs);

	int rhsLenght = getLenght(rhs);

	for (int i = 0; i <= lhsLenght || i <= rhsLenght; i++)
	{
		char lHelper = ordinal ? lhs[i] : toUpper(lhs[i]);
		char rHelper = ordinal ? rhs[i] : toUpper(rhs[i]);


		if (lhs[i] == rhs[i])
		{
			continue;
		}

		if (lhs[i] > rhs[i])
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	if (lhsLenght == rhsLenght)
	{
		return 0;
	}
}

int searchFirstSubstringIndex(char* string, char* subString, bool caseSensitive)
{
	int index = -1, midind = 0;
	int lenght = getLenght(string);
	int lenghtSubString = getLenght(subString);

	for (int i = 0; i < lenght; i++)
	{
		switch (caseSensitive)
		{
		case 0:
			if (isLower(subString[0]) && !isLower(string[i]))
			{
				subString[0] -= 32;
			}

			if (isLower(!subString[0]) && isLower(string[i]))
			{
				subString[0] += 32;
			}

		case 1:
			if (string[i] == subString[0])
			{
				midind = i;

				for (int k = 0; k < lenghtSubString; k++, i++)
				{
					switch (caseSensitive)
					{
					case 0:
						if (isLower(subString[k]) && !(isLower(string[i])))
						{
							subString[k] -= 32;
						}

						if (!(isLower(subString[k])) && isLower(string[i]))
						{
							subString[k] += 32;
						}
					case 1:
						if (subString[k] == string[i])
						{
							if (k == lenghtSubString - 1)
							{
								return index;
							}

							index = midind;
							continue;
						}

						index = -1;
						break;
					}
				}
			}
		}

	}
	return index;
}

int getLenght(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int lenght = 0;

	while (source[lenght])
	{
		lenght++;
	}

	return lenght;
}

bool equivalenceStrings(char* string1, char* string2)
{
	int i = 0;
	int j = 0;

	if (getLenght(string1) == getLenght(string2))
	{
		return true;
	}

	return false;
}

int compressionStrings(char* string1, char* string2)
{
	int answer = 1;

	if (getLenght(string1) < getLenght(string2))
	{
		answer = 2;
	}

	if (getLenght(string1) > getLenght(string2))
	{
		answer = 3;
	}

	return answer;
}
