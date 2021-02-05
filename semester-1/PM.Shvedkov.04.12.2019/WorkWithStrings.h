#pragma once
#include <iostream>

using namespace std;

bool isAlphabet(char);
bool isLower(char);
bool equivalenceStrings(char*, char*);
bool areEqual(char*, char*);
int compressionStrings(char*, char*);
int searchFirstSubstringIndex(char*, char*, bool = true);
int getLength(const char*);
int compare(const char*, const char*, bool = true);
int enterenceSymbolInString(char*, char);
char** createList(char[], int&);
char* createString(const char*);
char* trancferToP(int, short);
char* associationStrings(char*, char*);
char toUpper(char);
void copyString(char*, const char*);
void runTestString();
void caseTestString(char*, char*, bool, int);
void deleteMemory(char*);
void displayList(char**, int);
void alphabetBubleSortList(char**, int);
void alphabetInsertSortList(char**, int);
void lengthSortList(char**, int);
void symbolEnterenceSortList(char**, int, char);
void searchFirstBeginEndSubstring(char*, char*, int&, int&, bool = true);
void copyStringTo(char*, const char*, int);
void copyStringAfter(char*, const char*, int);

char* associationStrings(char* lps, char* rps)
{
	char* buffer = new char[(getLength(lps) + getLength(rps)) + 10];
	int k = 0;

	for (int i = 0; lps[i] > 0; k++, i++)
	{
		buffer[k] = lps[i];
	}

	for (int i = 0; rps[i] > 0; k++, i++)
	{
		buffer[k] = rps[i];
	}

	return createString(buffer);
}

void copyStringTo(char* target, const char* source, int end)
{
	if (end < 0)
	{
		throw std::invalid_argument(" Top face must be greater than 0!");
	}

	if (target == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int targetLength = getLength(target);

	int sourceLength = getLength(source);

	if (targetLength < sourceLength)
	{
		throw std::invalid_argument("Length destination string!");
	}

	int i = 0, n = getLength(target);

	for (int i = 0; i < n; i++)
	{
		target[i] = '\0';
	}

	while (i < end)
	{
		target[i] = source[i];
		i++;
	}
}

void copyStringAfter(char* target, const char* source, int begin)
{
	if (begin > getLength(source))
	{
		throw std::invalid_argument(" Out of line!");
	}

	if (target == nullptr)
	{
		throw std::invalid_argument(" String can't be null!");
	}

	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int targetLength = getLength(target);

	int sourceLength = getLength(source);

	if (targetLength < sourceLength)
	{
		throw std::invalid_argument("Length destination string!");
	}

	int i = 0, n = getLength(target);

	for (int i = 0; i < n; i++)
	{
		target[i] = '\0';
	}

	while (source[i])
	{
		target[i] = source[i + begin];
		i++;
	}
}

void searchFirstBeginEndSubstring(char* string, char* subString, int& begin, int& end, bool caseSensitive)
{
	if (searchFirstSubstringIndex(string, subString, caseSensitive) != -1)
	{
		begin = searchFirstSubstringIndex(string, subString);
		end = getLength(subString) + begin;
	}
}

void symbolEnterenceSortList(char** list, int k, char symbol)
{
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (enterenceSymbolInString(list[j], symbol) < enterenceSymbolInString(list[j + 1], symbol))
			{
				swap(list[j], list[j + 1]);
				continue;
			}

			break;
		}
	}
}

void lengthSortList(char** list, int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (getLength(list[j]) < getLength(list[j + 1]))
			{
				swap(list[j], list[j + 1]);
				continue;
			}

			break;
		}
	}
}

void alphabetBubleSortList(char** list, int k)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;

		for (int j = k - 1; j > i; j--)
		{
			if (compare(list[j], list[j - 1], 0) == -1)
			{
				swap(list[j], list[j - 1]);
				isSorted = false;
			}
		}

		i++;
	}
}

void alphabetInsertSortList(char** list, int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (compare(list[j], list[j + 1]) == 1)
			{
				swap(list[j], list[j + 1]);
				continue;
			}

			break;
		}
	}
}

int enterenceSymbolInString(char* string, char symbol)
{
	int j = 0;

	for (int i = 0; i < getLength(string); i++)
	{
		if (string[i] == symbol)
		{
			j++;
		}
	}

	return j;
}

void displayList(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << endl;
	}
}

char** createList(char source[], int& k)
{
	const int N = 256;
	char* bufferWords[N];
	int i = 0, j = 0;
	bool isWordCreating = false;
	k = 0;
	char buffer[N] = "";

	while (source[i])
	{
		if (isAlphabet(source[i]))
		{
			buffer[j] = source[i];
			j++;
			isWordCreating = true;
		}
		else
			if (isWordCreating)
			{
				bufferWords[k] = createString(buffer);
				copyString(buffer, "");
				j = 0;
				k++;
				isWordCreating = false;
			}

		i++;
	}
	if (isWordCreating)
	{
		bufferWords[k] = createString(buffer);
		k++;
	}

	char** words = new char* [k];

	for (int i = 0; i < k; i++)
	{
		words[i] = bufferWords[i];
	}

	return words;
}

char* trancferToP(int number, short p)
{
	char* str = new char[255]{};
	int i = 0;

	for (int ost = 0; number > 0; i++)
	{
		if (number % p >= 10)
		{
			ost = (number % p) + 55;
		}

		if (number % p <= 10)
		{
			ost = (number % p) + 48;
		}

		str[i] = ost;


		number /= p;
	}

	for (int k = 0; k < i; i--, k++)
	{
		swap(str[k], str[i - 1]);
	}

	return str;
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

	if (getLength(lhs) != getLength(rhs))
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

void deleteMemory(char* string)
{
	delete[]string;
}

void caseTestString(char* string, char* subString, bool sensitive, int expAnswer)
{
	if (isLower(string[0]) == expAnswer)
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
	caseTestString(string, subString, flag, 16);

	flag = false;
	char string2[] = " I am just Iron Man!";
	char subString2[] = "IRON";
	caseTestString(string2, subString2, flag, 11);

	flag = true;
	char string3[] = " I AM JUST IRON MAN!";
	char subString3[] = "I";
	caseTestString(string3, subString3, flag, 1);

	flag = true;
	char string4[] = " I am just Iron Man!";
	char subString4[] = "IRON";
	caseTestString(string4, subString4, flag, -1);
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

	int Length = getLength(source) + 1;

	char* target = new char[length];

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

	int targetLength = getLength(target);

	int sourceLength = getLength(source);

	if (targetLength < sourceLength)
	{
		throw std::invalid_argument("Length destination string!");
	}

	int i = 0, n = getLength(target);

	for (int i = 0; i < n; i++)
	{
		target[i] = '\0';
	}

	while (source[i])
	{
		target[i] = source[i];
		i++;
	}
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

	int lhsLength = getLength(lhs);

	int rhsLength = getLength(rhs);

	for (int i = 0; i <= lhsLength || i <= rhsLength; i++)
	{
		char lHelper = ordinal ? lhs[i] : toUpper(lhs[i]);
		char rHelper = ordinal ? rhs[i] : toUpper(rhs[i]);


		if (lHelper == rHelper)
		{
			continue;
		}

		if (lHelper > rHelper)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	if (lhsLength == rhsLength)
	{
		return 0;
	}
}

int searchFirstSubstringIndex(char* string, char* subString, bool caseSensitive)
{
	int index = -1, midind = 0;
	int Length = getLength(string);
	int lengthSubString = getLength(subString);

	for (int i = 0; i < length; i++)
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

				for (int k = 0; k < lengthSubString; k++, i++)
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
							if (k == lengthSubString - 1)
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

int getLength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int length = 0;

	while (source[length])
	{
		length++;
	}

	return length;
}

bool equivalenceStrings(char* string1, char* string2)
{
	int i = 0;
	int j = 0;

	if (getLength(string1) == getLength(string2))
	{
		return true;
	}

	return false;
}

int compressionStrings(char* string1, char* string2)
{
	int answer = 1;

	if (getLength(string1) < getLength(string2))
	{
		answer = 2;
	}

	if (getLength(string1) > getLength(string2))
	{
		answer = 3;
	}

	return answer;
}
