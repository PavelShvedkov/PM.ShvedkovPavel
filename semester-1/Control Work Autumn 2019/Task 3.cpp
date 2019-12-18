#include <iostream>
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"

using namespace std;

int getLength(const char*);
bool isDigit(const char);
void reverseNumber(int&);
//etc
int parseStringToSumWithUnsigned(const char*);
int parseStringToSumWithSigned(const char*);
void parseStringToSumWithUnsignedTest();
void parseStringToSumWithSignedTest();


int main()
{
	parseStringToSumWithUnsignedTest();
	parseStringToSumWithSignedTest();
	system("pause");
	return 0;
}

int parseStringToSumWithUnsigned(const char* source)
{
	const int N = 256;
	int buffer[N] = { 0 };
	int i = 0, j = 0, k = 0;
	int number = 0, summ = 0;
	bool flag = false;
	int length = getLength(source);

	for (int i = 0; 0 < length; length--)
	{
		if (isDigit(source[length]))
		{
			summ+= (source[length]-'0');
		}
	}

	//while (source[i])
	//{
	//	if (isDigit(source[i]))
	//	{
	//		flag = true;
	//		buffer[j] = source[i] - 48;
	//		j++;
	//		i++;
	//		continue;
	//	}
	//	else
	//	{
	//		if (flag)
	//		{
	//			for (int k = 0, length = j - 1; k < j / 2; length--, k++)
	//			{
	//				swap(buffer[k], buffer[length]);
	//			}
	//			int i = 0;
	//			while (i < j)
	//			{
	//				number += buffer[i] * pow(10, i);
	//				i++;
	//			}
	//		}

	//	}
	//	flag = false;
	//	summ += number;
	//	i++;
	//}

	return summ;
}

int parseStringToSumWithSigned(const char* source)
{


	return 0;
}

bool isDigit(const char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

void reverseNumber(int& number)
{
	return;
}

int getLength(const char* source)
{
	int length = 0;

	while (source[length])
	{
		length++;
	}

	return length;
}

void parseStringToSumWithUnsignedTest()
{
	bool result = parseStringToSumWithUnsigned("1235+-8+*** 90") == 1333;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("1235+-8+* 4** -22--- 9") == 1278;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	//etc
}

void parseStringToSumWithSignedTest()
{
	bool result = parseStringToSumWithSigned("1235+-8+*** 90") == 1317;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("1235+-8+* 4** -22--- 9") == 1218;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	//etc
}