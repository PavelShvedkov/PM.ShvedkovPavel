#include <iostream>

using namespace std;

int unitsInBinary(int);
void testCase(int, int);
void runtest();
int enterNumber();
void displayResult(int);
void menu();
void workWithConsole();
void menuText();

int main()
{
	menu();
}

void runtest()
{
	testCase(1, 1);
	testCase(3, 2);
	testCase(4, 1);
	testCase(10, 2);
	testCase(35678, 9);
	testCase(0, 0);
	testCase(-10, 2);
	testCase(363, 6);

}

int enterNumber()
{
	int number;

	cout << " Enter number: ";
	cin >> number;

	return number;
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
			runtest();
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

void workWithConsole()
{
	int number = enterNumber();

	int counter = unitsInBinary(number);

	displayResult(counter);
}

void displayResult(int counter)
{
	cout << " Units in binary: " << counter << endl;
}

int unitsInBinary(int decimalNumber)
{
	int counter = 0;

	for (; decimalNumber > 0; decimalNumber /= 2)
	{
		if (decimalNumber % 2==0)
		{
			counter++;
		}
	}
	return counter;
}

void testCase(int decimalNumber, int expResponse)
{
	int counter = 0;

	

	if (counter = expResponse)
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :)" << endl;
	}
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}


