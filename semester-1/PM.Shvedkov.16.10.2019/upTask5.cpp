#include <iostream>

using namespace std;

int enterNumber();
short enterDigit();
int modifiedNumber(int, short);
void menu();
void menuText();
void workWithConsole();
void displayResult(int, int, short);
void runTests();
void testCase(short, int, short, int);



int main()
{
	menu();
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}
void menu()
{
	while (true)
	{
		char operation;

		menuText();

		cin >> operation;

		switch (operation)
		{
		case '1':
			workWithConsole();
			break;
		case '2':
			runTests();
			break;
		case '3':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}

		system("pause");
		system("cls");
	}
}
int modifiedNumber(int number, short removable)
{
	int reflection = 0;
	bool sign = 1;

	number < 0 ? sign = 1 : sign = 0;
	number = abs(number);

	while (number)
	{
		if (number % 10 != removable)
		{
			reflection = reflection * 10 + number % 10;
		}
		number /= 10;
	}

	while (reflection)
	{
		number = number * 10 + reflection % 10;
		reflection /= 10;
	}

	if (sign)
	{
		number *= -1;
	}

	return number;
}
short enterDigit()
{
	short digit;

	while (true)
	{
		cout << "Enter digit (0..9): ";
		cin >> digit;

		if (digit >= 0 && digit <= 9)
		{
			break;
		}

		cout << "Not digit. Ty again." << endl;
		system("pause");
		system("cls");
	}

	return digit;
}
int enterNumber()
{
	int number;

	cout << " Enter number: ";
	cin >> number;

	return number;
}
void workWithConsole()
{
	int initialNumber = enterNumber();
	int digit = enterDigit();

	int number = modifiedNumber(initialNumber, digit);

	displayResult(initialNumber, number, digit);

}
void displayResult(int initialNumber, int number, short digit)
{
	cout << "Number '" << initialNumber << " ' with deleted digit '" << digit << "': " << number << endl;
}
void runTests()
{
	int testNumber = 1;

	testCase(testNumber++, 12345678, 5, 1234678);
	testCase(testNumber++, 11111111, 1, 0);
	testCase(testNumber++, 1133445544, 4, 113355);
	testCase(testNumber++, -123045726, 2, -1304576);



}
void testCase(short testNumber, int initialNumber, short digit, int expNumber)
{
	int number = modifiedNumber(initialNumber, digit);

	if (number == expNumber)
	{
		cout << "Case #" << testNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << " Case #" << testNumber << " IS NOT CORRECT. :(" << endl;
		cout << " Actual = " << modifiedNumber(initialNumber, digit) << ", but expected =" << expNumber;
	}
}


