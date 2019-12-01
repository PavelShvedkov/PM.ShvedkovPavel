#pragma once
#include <iostream>
  
using namespace std;

bool isAlphabet(char);
bool isLower(char);
bool equivalenceStrings(char*, char*);
bool areEqual(char* , char* );
int compressionStrings(char*, char*);
int searchFirstSubstringIndex(char*, char*,bool=true);//1task
int getLenght(const char*);
int compare(const char*, const char*, bool = true);
char* createString(const char*);
char* trancfers(char*, char*, char*, int, int);
char toUpper(char);
void copyString(char*, const char*);
void runTestString();
void caseTestString(char*, char*, char*, char*);
void deleteMemory(char*);
void caseEquevalence(char*, char*, int, int, int);
void caseSSILowSSR(char*, char*, int, int, int);
void caseSSRLowSSI(char*, char*, char*, char*, int, int);


char* trancfers(char* string, char* subStringRemovable, char* subStringInsertiable, int sizesRelations, int sizeSSR)
{
	char* workingString = new char[255];

	for (int i = 0, index; string[i] != '\0'; i++)
	{
		index = searchFirstSubstringIndex(string, subStringRemovable);

		if (index == -1)
		{
			break;
		}

		switch (sizesRelations)
		{
		case 1:
			caseEquevalence(string, subStringInsertiable, sizeSSR, index, i);
			continue;
		case 2:
			caseSSILowSSR(string, subStringInsertiable, sizeSSR, index, i);
			continue;
		case 3:
			caseSSRLowSSI(string, subStringInsertiable, subStringRemovable, workingString, index, i);
			return workingString;
		}
	}

	deleteMemory(workingString);
	return string;
}


void deleteMemory(char* string)
{
	delete[]string;
}

void caseTestString(char* string, char* subStringR,char* subStringI,char* expString)
{
	int sizesRelations = compressionStrings(subStringI, subStringR);

	if (areEqual(trancfers(string, subStringR, subStringI, sizesRelations, getLenght(subStringR)),expString))
	{
		cout << " )))" << endl;
	}
	else
	{
		cout << " (((" << endl;
	}
}

void caseSSRLowSSI(char* string, char* subStringInsertiable, char* subStringRemovable, char* workingString, int index, int i)
{
	copyString(workingString, string);

	while (searchFirstSubstringIndex(workingString, subStringRemovable) != -1)
	{
		int start = searchFirstSubstringIndex(workingString, subStringRemovable);

		for (int i = 0; start < (getLenght(workingString) + getLenght(subStringInsertiable) - getLenght(subStringRemovable)); i++, start++)
		{
			if (i < getLenght(subStringInsertiable))
			{
				workingString[start] = subStringInsertiable[i];
			}

			if (getLenght(string) == getLenght(workingString))
			{
				workingString[start + getLenght(subStringInsertiable)] = string[start + getLenght(subStringRemovable)];
			}
			else
			{
				workingString[start + getLenght(subStringInsertiable)] = string[start - getLenght(subStringInsertiable) + (2 * getLenght(subStringRemovable))];
			}
		}
	}
}

void caseSSILowSSR(char* string, char* subStringInsertiable, int sizeSSR, int index, int i)
{
	for (int k = 0; string[index] != '\0'; k++, index++, i++)
	{
		string[index + sizeSSR + getLenght(subStringInsertiable) - sizeSSR] = string[index + sizeSSR];

		if (k < getLenght(subStringInsertiable))
		{
			string[index] = subStringInsertiable[k];
		}
	}
}

void caseEquevalence(char* string, char* subStringInsertiable, int sizeSSR, int index, int i)
{
	for (int k = 0; k < sizeSSR; k++, index++, i++)
	{
		string[index] = subStringInsertiable[k];
	}
}

bool areEqual(char* lhs, char* rhs)
{
	if (lhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (rhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (getLenght(lhs) != getLenght(rhs))
	{
		return false;
	}

	for (char* p = lhs, *q = rhs; p < '\0'; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}

	return true;
}

void runTestString()
{
	char string[] = " I am just Iron IRON man!";
	char subStringR[] = "IRON";
	char subStringI[] = "wooden";
	char expString[] = " I am just Iron wooden man!";
	caseTestString(string, subStringR, subStringI, expString);

	 char string2[] = " I am just Iron Man!";
	 char subStringR2[] = "IRON";
	 char subStringI2[] = "woodern";
	 char expString2[] = " I am just Iron Man!";
	caseTestString(string2, subStringR2, subStringI2, expString2);

	 char string3[] = " I AM JUST IRON MAN!";
	 char subStringR3[] = "JUST";
	 char subStringI3[] = "DUST";
	 char expString3[] = " I AM DUST IRON MAN!";
	caseTestString(string3, subStringR3, subStringI3, expString3);
	
	char string4[] = " I am just Iron Man!";
	char subStringR4[] = "Iron";
	char subStringI4[] = "h";
	char expString4[] = " I am just h Man!";
	caseTestString(string4, subStringR4, subStringI4, expString4);
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

			if (!isLower(subString[0]) && isLower(string[i]))
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
