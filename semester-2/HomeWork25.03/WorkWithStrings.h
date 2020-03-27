#pragma once
#include <iostream>

using namespace std;

namespace myStrings
{

	bool isAlphabet(char);
	bool isLower(char);
	bool equivalenceStrings(char*, char*);
	bool areEqual(char*, char*);
	bool isDigit(const char);
	int compressionStrings(char*, char*);
	int searchFirstSubstringIndex(char*, char*, bool = true);
	int getLength(const char*);
	int compare(const char*, const char*, bool = true);
	int enterenceSymbolInString(char*, char);
	int parseStringToSumWithSigned(const char*);
	int findFirstIndexSubstringLength(string, int);
	int symbolsInNumber(int);
	char** createList(char[], int&);
	char* createString(const char*);
	char* createStringSymbols(char, int);
	char* trancferToP(int, short);
	char* copyStringTo(const char*, int);
	string deleteFirstSubstringGivenLength(string , int );
	char* copyStringAfter(const char*, int);
	char* numberToString(int);
	char toUpper(char);
	void copyString(char*, const char*);
	void runTestString();
	void caseTestString(char*, char*, bool, int);
	void deleteMemory(char*);
	void displayList(char**, int);
	void alphabetBubleSortList(char**, int);
	void alphabetInsertSortList(char**, int);
	void lenghtSortList(char**, int);
	void symbolEnterenceSortList(char**, int, char);
	void searchFirstBeginEndSubstring(char*, char*, int&, int&, bool = true);
	void associationStrings(char*, char*);

	int symbolsInNumber(int number)
	{
		int digits = 1;

		if (number < 0)
		{
			++digits;
		}

		while (number /= 10)
		{
			++digits;
		}

		return digits;
	}

	char* createStringSymbols(char symbol, int length)
	{
		char* source = new char[length + 1];
		int i = 0;

		for (; i < length; ++i)
		{
			source[i] = symbol;
		}

		source[i] = '\0';

		return source;
	}

	char* numberToString(int number)
	{
		char* string = new char[symbolsInNumber(number) + 1];
		int lengthString = symbolsInNumber(number) + 1;

		for (int i = lengthString - 2; i >= 0; i--)
		{
			string[i] = (char)(number % 10 + 48);
			number /= 10;
		}

		string[lengthString - 1] = '\0';

		return string;
	}//когда число начинается с нуля выводятся неверные данные

	string deleteFirstSubstringGivenLength(string source, int length)
	{
		int index= findFirstIndexSubstringLength(source, length);
		
		if (index==-1)
		{
			return source;
		}

		return source.erase(index, length+1);
	}

	int findFirstIndexSubstringLength(string source, int length)
	{
		int index = -1;

		/*for (int i = 0, k = 0; source[i]; i++)*/for (int i = 0, k = 0; i<source.size(); i++)
		{
			if (isAlphabet(source[i]))
			{
				index = i;
				while (isAlphabet(source[i]))
				{
					k++;
					i++;
				}
				if (k == length)
				{
					return index;
				}
				k = 0;
			}

		}

		return -1;
	}

	int parseStringToSumWithSigned(const char* source)
	{
		int number = 0, summ = 0;
		int length = getLength(source);

		for (int i = 0, k = 1; i <= length; i++)
		{
			if (isDigit(source[i]))
			{
				number = number * 10 + k * (source[i] - '0');
				continue;
			}
			else
			{
				if (source[i] == '-' && isDigit(source[i + 1]))
				{
					k = -1;
					continue;
				}
				k = 1;
				summ += number;
				number = 0;
			}
		}

		return summ;
	}

	bool isDigit(const char symbol)
	{
		return symbol >= '0' && symbol <= '9';
	}

	void associationStrings(char* lps, char* rps)
	{

		if (rps == nullptr)
		{
			return;
		}

		int k = 0, lenl = getLength(lps);

		for (int i = 0; rps[i] != '\0'; lenl++, i++)
		{
			lps[lenl] = rps[i];
		}
		lps[lenl] = '\0';

	}

	char* copyStringTo(const char* source, int end)
	{
		int sourceLenght = getLength(source);

		if (end < 0 || end > sourceLenght)
		{
			throw std::invalid_argument(" Top face must be greater than 0 and less row size!");
		}

		if (source == nullptr)
		{
			throw std::invalid_argument(" String can't be null");
		}

		char* target = new char[sourceLenght] {0};

		int i = 0;


		if (end == sourceLenght)
		{
			copyString(target, source);
		}

		while (i < end)
		{
			target[i] = source[i];
			i++;
		}

		return target;
	}

	char* copyStringAfter(const char* source, int begin)
	{
		int sourceLength = getLength(source);

		if (begin > sourceLength || begin < 0)
		{
			throw std::invalid_argument(" Out of line!");
		}

		if (begin == sourceLength)
		{
			return '\0';
		}

		if (source == nullptr)
		{
			throw std::invalid_argument(" String can't be null");
		}

		char* target = new char[sourceLength] {0 };

		for (int i = 0; source[i]; i++)
		{
			target[i] = source[i + begin];
		}

		return target;
	}


	void searchFirstBeginEndSubstring(char* string, char* subString, int& begin, int& end, bool caseSensitive)
	{
		if (searchFirstSubstringIndex(string, subString, caseSensitive) != -1)
		{
			begin = searchFirstSubstringIndex(string, subString);
			end = getLength(subString) + begin;
		}
		else
		{
			begin = -1;
			end = -1;
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

	void lenghtSortList(char** list, int k)
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

		for (char* p = lhs, *q = rhs; p < 0; p++, q++)
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

		int lenght = getLength(source) + 1;

		char* target = new char[lenght];

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

		int sourceLenght = getLength(source);

		if (targetLength < sourceLenght)
		{
			throw std::invalid_argument("Lenght destination string!");
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

		int lhsLenght = getLength(lhs);

		int rhsLenght = getLength(rhs);

		for (int i = 0; i <= lhsLenght || i <= rhsLenght; i++)
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

		if (lhsLenght == rhsLenght)
		{
			return 0;
		}
	}

	int searchFirstSubstringIndex(char* string, char* subString, bool caseSensitive)
	{
		int index = -1, midind = 0;
		int lenght = getLength(string);
		int lenghtSubString = getLength(subString);

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

	int getLength(const char* source)
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
}