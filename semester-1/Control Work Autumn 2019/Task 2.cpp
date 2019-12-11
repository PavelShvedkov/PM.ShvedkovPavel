#include <iostream>
#include "WorkWithArrays.h"
#include "WorkWithStrings.h"

using namespace std;

int* encoding(char const*, char const*);
char* decoding(int const*,int, char const*);
char* createRule(const char*);
//char* createRule(const char*, int);
void createRuleTest();
void encodingTests();
void decodingTests();
bool equals(const char*, const char*);
bool equals(const int*,int, const int*,int);

int main()
{
	createRuleTest();
	encodingTests();
	decodingTests();
	system("pause");
}

//char* createRule(const char* source, int shift)
//{
//	char* buffer = createString(source);
//	int sourceSize = getLenght(source);
//
//	for (int i = 0, j = sourceSize; i < sourceSize / 2; j--, i++)
//	{
//		swap(buffer[i], buffer[j - 1]);
//	}
//	int i = 0;
//	while (shift < getLenght(source))
//	{
//		buffer[i] = buffer[shift];
//		i++;
//		shift++;
//	}
//
//	// reverse source
//	// shift left 
//	return nullptr;
//}

char* createRule(const char* source)
{
	char* buffer =createString(source) ;
	int sourceSize = getLenght(source);

	for (int i = 0,j= sourceSize; i < sourceSize /2 ;j--, i++)
	{
		swap(buffer[i], buffer[j-1]);
	}

	//buffer[getLenght(source)] = 0;
	return buffer;
}

int* encoding(const char* source, const char* rule)
{
	char* buffer = createString(source);
	

	for (int i = 0; i < getLenght(source); i++)
	{
		for (int j = 0; j < getLenght(rule); j++)
		{
			if (isLower(buffer[i]))
			{
				buffer[i]=toUpper(buffer[i]);
			}

			if (buffer[i] == rule[j])
			{
				buffer[i] = rule[j];
				break;
			}
		}
		
	}

	int* encodingArray = new int{ 0 };

	for (int i = 0; i < getLenght(source); i++)
	{
		if (buffer[i]>='A'&& buffer[i] <= 'Z')
		{
			encodingArray[i] = 91 - buffer[i];
		}
		else
		{
			encodingArray[i] = (int)buffer[i];
		}
	}

	//deleteMemory(buffer);
	return encodingArray;
}

char* decoding(const int* source,int size, const char* rule)
{
	char* buffer = new char[size] { 0 };
	int i = 0;

	for (; i < size; i++)
	{	
		if (((91-source[i]) >= 'A') && ((91-source[i]) <= 'Z'))
		{
			buffer[i] = 91 - source[i];
		}
		else
		{
			buffer[i] = source[i];
		}
	}

	buffer[i] = 0;

	return buffer;
}

bool equals(const char* lhs, const char* rhs)
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

	for (const char* p = lhs, *q = rhs; p < '\0'; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}

	return true;
}

bool equals(const int* lhs,int n, const int* rhs,int m)
{
	if (n != m)
	{
		return false;
	}

	for (const int* p = lhs, *q = rhs; p < lhs + n; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}

	return true;
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* actual = createRule(source);

	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;

	/*actual = createRule(source, 5);

	expected = "UTSRQPONMLKJIHGFEDCBAZYXWV";

	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;*/
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode,10, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 },10) ? "Passed." : "Failed.") << endl;

	//deleteMemory(encode);

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode,29, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 },29) ? "Passed." : "Failed.") << endl;

	// new shift rule

	/*rule = createRule(source, 5);

	encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, 10, new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, 29, new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, 29) ? "Passed." : "Failed.") << endl;*/

}

void decodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	char* decode = decoding(new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 },10, rule);

	cout << "Test for decoding " << (equals(decode, "Learn C++!") ? "Passed." : "Failed.") << endl;

	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 },29, rule);

	cout << "Test for decoding " << (equals(decode, "Cogito, ergo sum! (Descartes)") ? "Passed." : "Failed.") << endl;

	// new shift rule

	/*rule = createRule(source, 5);

	decode = decoding(new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10, rule);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	decode = decoding(new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, 29, rule);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;*/

}