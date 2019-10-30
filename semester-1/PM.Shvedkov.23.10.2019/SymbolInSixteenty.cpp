//- Реализовать функцию, определяющую количество вхождений
//  заданного символа в шестнадцатиричном предствалении
//  заданного целого знакового числа. Проверить работу функции в консоли.

#include <iostream>

using namespace std;

int hexadecimalCharacter(int, char);
short conversionCharToShort(char);
void testCase(int, char, short);
void runtest();
int enterNumber();
char enterSymbol();
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
	testCase(17, 'A', 0);
	testCase(159, 'F', 1);
	testCase(415, '9', 1);
	testCase(165348, '2', 1);
	testCase(1111111, '4', 2);
	testCase(0, '0', 1);
	testCase(-1111, '5', 1);
	testCase(64567644, '3', 2);

}

int enterNumber()
{
	int number;

	cout << " Enter number: ";
	cin >> number;

	return number;
}

char enterSymbol()
{
	char symbol;

	while (true)
	{
		cout << " Enter symbol (0...9) or (A...F): ";
		cin >> symbol;
	}

	return symbol;
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

	char symbol = enterSymbol();

	int counter = hexadecimalCharacter(number, symbol);

	displayResult(counter);
}

void displayResult(int counter)
{
	cout << " Symbols in hexadecimal : " << counter << endl;
}

int hexadecimalCharacter(int decimalNumber, char symbol)
{
	short digit = 0;

	short counter = 0;

	switch (symbol)
	{
	case '1':
		digit = 1;
		break;
	case '2':
		digit = 2;
		break;
	case '3':
		digit = 3;
		break;
	case '4':
		digit = 4;
		break;
	case '5':
		digit = 5;
		break;
	case '6':
		digit = 6;
		break;
	case '7':
		digit = 7;
		break;
	case '8':
		digit = 8;
		break;
	case '9':
		digit = 9;
		break;
	case 'A':
		digit = 10;
		break;
	case 'B':
		digit = 11;
		break;
	case 'C':
		digit = 12;
		break;
	case 'D':
		digit = 13;
		break;
	case 'E':
		digit = 14;
		break;
	case 'F':
		digit = 15;
		break;
	case '0':
		digit = 0;
		break;
	default:
		cout << " Unkown charakter! " << endl;
	}

	for (; decimalNumber > 0; decimalNumber /= 16)
	{
		if (decimalNumber % 16 == digit)
		{
			counter++;
		}
	}
	return counter;
}

short conversionCharToShort(char symbol)
{
	short digit = 0;
	switch (symbol)
	{
	case '1':
		digit = 1;
		break;
	case '2':
		digit = 2;
		break;
	case '3':
		digit = 3;
		break;
	case '4':
		digit = 4;
		break;
	case '5':
		digit = 5;
		break;
	case '6':
		digit = 6;
		break;
	case '7':
		digit = 7;
		break;
	case '8':
		digit = 8;
		break;
	case '9':
		digit = 9;
		break;
	case 'A':
		digit = 10;
		break;
	case 'B':
		digit = 11;
		break;
	case 'C':
		digit = 12;
		break;
	case 'D':
		digit = 13;
		break;
	case 'E':
		digit = 14;
		break;
	case 'F':
		digit = 15;
		break;
	case '0':
		digit = 0;
		break;
	}

	return digit;
}

void testCase(int decimalNumber, char symbol, short expResponse)
{
	short digit = conversionCharToShort(symbol);

	short counter = 0;

	for (; decimalNumber > 0; decimalNumber /= 16)
	{
		if (decimalNumber % 16 == digit)
		{
			counter++;
		}
	}

	if (counter = expResponse)
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}



