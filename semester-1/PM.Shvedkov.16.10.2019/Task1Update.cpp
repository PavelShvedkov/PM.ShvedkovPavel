#include <iostream>

using namespace std;

bool logicFunction(int);
void workWithConsole();
void menu();
int enterData();
short enterOptionalData();
void menuText();
void displayResult(int, bool);
void countTest(short, int, bool);
void runTests();


int main()
{
	menu();
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

void runTests()
{
	int testNumber = 1;

	countTest(testNumber++, -5762, 0);
	countTest(testNumber++, 6442549, 0);
	countTest(testNumber++, 1111, 1);
	countTest(testNumber++, 0, 0);
	countTest(testNumber++, 24142, 1);
}

bool logicFunction(int number)
{
	bool check = true;

	number = abs(number);

	for (int k = 2; k < number; k++)
	{
		if (number % k != 0)
		{
			continue;
		}
		else
		{
			check = false;
			break;
		}
	}
	return check;
}

void countTest(short testNumber, int number, bool expCheck)
{
		int mirrorImage = 0;

		while (int clone = number)
		{
			mirrorImage = mirrorImage * 10 + clone % 10;
			clone /= 10;
		}

		bool out = false;

		if (mirrorImage == number)
		{
			out = true;
		}

	if (out==expCheck)
	{
		cout << "Case #" << testNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << testNumber << " IS NOT CORRECT. :(" << endl;
	}
}

int workWithCansole()
{
	int number = enterData();

	bool answer = logicFunction(number);

	displayResult(number, answer);

	return 0;
}

int enterData()
{
	int number;

	cout << " Enter number: ";
	cin >> number;

	return number;
}

short enterOptionalData()
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

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}

void displayResult(int number, bool answer)
{
	if (answer)
	{
		cout << "Number '" << number << "' is polindrom" << endl;

	}
	else
	{
		cout << "Number '" << number << "' is not polindrom" << endl;

	}

}




