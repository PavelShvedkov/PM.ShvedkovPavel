#include <iostream>

using namespace std;

int enterNumber();
short enterRemovable();
short enterDeputy();
int modifiedNumber(int, short, short);
void menu();
void menuText();
void workWithConsole();
void displayResult(int, int, short, short);
void runTests();
void testCase(short, int, short,short, int);



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
int modifiedNumber(int number, short removable, short deputy)
{
	bool sign = 1;

	number < 0 ? sign = 1 : sign = 0;
	number = abs(number);

		int mirrorImage = 0;

		while (number)
		{
			if (number % 10 == removable)
			{
				mirrorImage = mirrorImage * 10 + deputy;
			}
			else
			{
				mirrorImage = mirrorImage * 10 + number % 10;
			}

			number /= 10;
		}

		while (mirrorImage)
		{
			number = number * 10 + mirrorImage % 10;
			mirrorImage /= 10;
		}

	if (sign)
	{
		number *= -1;
	}

	return number;
}
short enterRemovable()
{
	short digit;

	while (true)
	{
		cout << " Enter removable (0..9): ";
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
short enterDeputy()
{
	short digit;

	while (true)
	{
		cout << " Enter deputy (0..9): ";
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
	int digit = enterRemovable();
	int deputy= enterDeputy();

	int number = modifiedNumber(initialNumber, digit, deputy);

	displayResult(initialNumber, number, digit, deputy);

}
void displayResult(int initialNumber, int number, short digit, short deputy)
{
	cout << "Number '" << initialNumber << " ' after replacing the number '" << digit << "' by '"<<deputy<<"' : " << number << endl;
}
void runTests()
{
	int testNumber = 1;

	testCase(testNumber++, 12345678, 5, 4, 12344678);
	testCase(testNumber++, 11111111, 1, 3, 33333333);
	testCase(testNumber++, 11334455, 4, 5, 11335555);
	testCase(testNumber++, -123045726, 2,1, -113045716);



}
void testCase(short testNumber, int initialNumber, short digit, short deputy, int expNumber)
{
	int number = modifiedNumber(initialNumber, digit, deputy);

	if (number == expNumber)
	{
		cout << "Case #" << testNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << " Case #" << testNumber << " IS NOT CORRECT. :(" << endl;
		cout << " Actual = " << modifiedNumber(initialNumber, digit, deputy) << ", but expected =" << expNumber;
	}
}

