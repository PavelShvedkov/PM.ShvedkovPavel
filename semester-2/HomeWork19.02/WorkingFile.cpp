#include <iostream>
#include "RationalFraction.h"

using namespace std;

typedef int (*testOption)(RationalFraction, RationalFraction, RationalFraction, int);

void menu();
void menuText();
void operationList();
void workWithConsole();
void tests();
void startTest(testOption);
int testGCF(RationalFraction, RationalFraction, RationalFraction, int);


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
			operationList();
			break;
		case '3':
			system("cls");
			tests();
			break;
		case '4':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}

		system("pause");
		system("cls");
	}
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to display a list of operations." << endl;
	cout << "Press 3 to select test." << endl;
	cout << "Press 4 to exit." << endl;
}

void operationList()
{
	cout << " ^ - power" << endl;
	cout << " # - squareRoot" << endl;
	cout << " ~ - reversion fraction" << endl;
	cout << " G - greatest common factor" << endl;
	cout << " L - least common multiple" << endl;
}

void workWithConsole()
{
	RationalFraction a, b, r;
	int c = 1;
	char operation;
	int operands = 3;

	enum operations { pow = '^', root = '#', reverse = '~', GCF = 'G', LCF = 'L' };//#-root;~-reverse,G-GCF,L-LCF

	cout << " Enter 1-st operand" << endl;
	a.enter();
	system("cls");

	cout << " Enter operation" << endl;
	cin >> operation;
	system("cls");

	if (operation == 'G' || operation == 'L')
	{
		cout << " Enter 2-nd operand" << endl;
		b.enter();
		operands = 2;
		system("cls");
	}
	else if (operation == 94)
	{
		cout << " Enter exponent: ";
		cin >> c;
		operands = 1;
		system("cls");
	}

	switch (operation)
	{
	case pow:
		r = power(a, c);
		break;
	case root:
		r = squareRoot(a);
		break;
	case reverse:
		r = a.reverseFraction();
		break;
	case GCF:
		r = greatestCommonFactor(a, b);
		break;
	case LCF:
		r = leastCommonMultiple(a, b);
		break;
	default:
		cout << " Not valid operation" << endl;
		return;
	}

	switch (operands)
	{
	case 1:
		a.display(0);
		cout << " power " << c << " = ";
		r.display();
		break;
	case 2:
		cout << operation << "(";
		a.display();
		cout << ",";
		b.display();
		cout << ")" << endl;
		break;
	case 3:
		cout << " Square root of ";
		a.display(0);
		cout << "= ";
		a.display();
		break;
	}
}

void tests()
{

	int button;

	cout << " Enter 1 to run the test to find the largest common factor" << endl;
	cout << " Enter 2 to return to the menu" << endl;
	while (true)
	{
		cin >> button;

		switch (button)
		{
		case 1:
			startTest(testGCF);
			break;
		case 2:
			system("cls");
			menu();
			break;
		default:
			cout << " Not valid operation, tre again." << endl;
			break;
		}
	}
}

void startTest(testOption option)
{
	int testNumber = 1;

	option(RationalFraction(2, 3), RationalFraction(4, 27), RationalFraction(2, 27), testNumber++);

	option(RationalFraction(-2, 3), RationalFraction(4, 27), RationalFraction(2, 27), testNumber++);

	option(RationalFraction(2, 3), RationalFraction(0, 27), RationalFraction(2, 3), testNumber++);

	option(RationalFraction(2, 3), RationalFraction(1, 1), RationalFraction(1, 3), testNumber++);

	option(RationalFraction(2, -3), RationalFraction(-2, 3), RationalFraction(2, 3), testNumber++);
}

int testGCF(RationalFraction lho, RationalFraction rho, RationalFraction expected, int testNumber)
{
	RationalFraction actual = greatestCommonFactor(lho, rho);

	if (actual == expected)
	{
		cout << " Test " << testNumber << " is ok." << endl;
		return 1;
	}
	else
	{
		cout << " Test " << testNumber << " is failed." << endl;
		return 0;
	}
}
