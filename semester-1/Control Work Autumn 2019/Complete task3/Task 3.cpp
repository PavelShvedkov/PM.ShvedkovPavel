#include <iostream>


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
	int number = 0, summ = 0;
	int length = getLength(source);

	for (int i = 0; i <= length; i++)
	{
		if (isDigit(source[i]))
		{
			number = number * 10 + (source[i] - '0');
			continue;
		}
		else
		{
			summ += number;
			number = 0;
		}
	}

	return summ;
}

int parseStringToSumWithSigned(const char* source)
{
	int number = 0, summ = 0;
	int length = getLength(source);

	for(int i = 0, k=1; i <= length;i++)
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

	result = parseStringToSumWithSigned("1235+-800* 4** -22--- 9") == 426;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	//etc
}