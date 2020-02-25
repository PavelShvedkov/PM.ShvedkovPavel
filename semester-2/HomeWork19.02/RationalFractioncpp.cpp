#include <iostream>

using namespace std;

int GCF(int, int);
void swap(int*, int*);
class RationalFraction
{
private:
	int numerator;
	int denominator;
public:
	RationalFraction()
	{
		numerator = 0;
		denominator = 1;
	}

	RationalFraction(int num, int denom)
	{
		numerator = num;
		denominator = denom;
	}

	int* TakeNumeratorAdress()
	{
		int* refNumerator = &numerator;

		return refNumerator;
	}

	int* takeDenominatorAdress()
	{
		int* refDenominator = &denominator;

		return refDenominator;
	}

	void enter()
	{
		cout << " Enter integer numerator: ";
		cin >> numerator;

		cout << " Enter integer denominator: ";
		cin >> denominator;
	}

	void display(bool newString = 1)
	{
		if (numerator == 0)
		{
			if (newString)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 0 << " ";
			}
			return;
		}

		int commonFactor = GCF(numerator, denominator);
		numerator /= commonFactor;
		denominator /= commonFactor;

		if ((numerator * denominator) > 0)
		{
			numerator = abs(numerator);
			denominator = abs(denominator);
		}
		else
		{
			if (numerator > 0)
			{
				numerator *= -1;
			}

			denominator = abs(denominator);
		}

		if (denominator == 1 || denominator == -1)
		{
			if (newString)
			{
				cout << numerator << endl;
			}
			else
			{
				cout << numerator << " ";
			}
			return;
		}

		if (newString)
		{
			cout << " " << numerator << "/" << denominator << endl;
		}
		else
		{
			cout << " " << numerator << "/" << denominator << " ";
		}
	}

	bool operator ==(RationalFraction rho)
	{
		if (numerator == *(rho.TakeNumeratorAdress()) && denominator == *(rho.takeDenominatorAdress()))
		{
			return true;
		}

		return false;
	}
};
typedef int (*testOption)(RationalFraction, RationalFraction, RationalFraction, int);

void menu();
void menuText();
void operationList();
void workWithConsole();
void tests();
void startTest(testOption);
int testGCF(RationalFraction, RationalFraction, RationalFraction, int);

RationalFraction addition(RationalFraction, RationalFraction);
RationalFraction addition(RationalFraction, int);
RationalFraction subtraction(RationalFraction, RationalFraction);
RationalFraction subtraction(RationalFraction, int);
RationalFraction multiplication(RationalFraction, RationalFraction);
RationalFraction multiplication(RationalFraction, int);
RationalFraction division(RationalFraction, RationalFraction);
RationalFraction division(RationalFraction, int);
RationalFraction power(RationalFraction, int);
void squareRoot(RationalFraction*);
void reverseFraction(RationalFraction*);
RationalFraction greatestCommonFactor(RationalFraction, RationalFraction);
RationalFraction greatestCommonFactor(RationalFraction, int);
RationalFraction leastCommonMultiple(RationalFraction, RationalFraction);
RationalFraction leastCommonMultiple(RationalFraction, int);
RationalFraction toRationalFraction(int);

int main()
{
	menu();
}

int GCF(int lho, int rho)
{
	if (lho == 0 || rho == 0)
	{
		return abs(lho - rho);
	}

	lho = abs(lho);
	rho = abs(rho);

	while (lho != rho)
	{
		if (lho > rho)
		{
			lho -= rho;
		}
		else
		{
			rho -= lho;
		}
	}

	return lho;
}

void swap(int* lho, int* rho)
{
	int temp = *lho;
	*lho = *rho;
	*rho = temp;
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
	cout << " + - addition" << endl;
	cout << " - - subtraction" << endl;
	cout << " * - multiplication" << endl;
	cout << " / - division" << endl;
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

	enum operations { addUp = 43, subtract = 45, multiple = 42, divide = 47, pow = 94, root = 35, reverse = '~', GCF = 71, LCF = 76 };//#-root;~-reverse,G-GCF,L-LCF

	cout << " Enter 1-st operand" << endl;
	a.enter();
	system("cls");

	cout << " Enter operation" << endl;
	cin >> operation;
	system("cls");

	if (operation > 42 && operation < 76)
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
	case addUp:
		r = addition(a, b);
		break;
	case subtract:
		r = subtraction(a, b);
		break;
	case multiple:
		r = multiplication(a, b);
		break;
	case divide:
		r = division(a, b);
		break;
	case pow:
		r = power(a, c);
		break;
	case root:
		squareRoot(&a);
		break;
	case reverse:
		reverseFraction(&a);
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
		a.display(0);
		cout << " " << operation << " ";
		b.display(0);
		cout << " " << "=" << " ";
		r.display(0);
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

	option(RationalFraction(2, 3), RationalFraction(4, 27), RationalFraction(2, 3), testNumber++);

	option(RationalFraction(-2, 3), RationalFraction(4, 27), RationalFraction(2, 3), testNumber++);

	option(RationalFraction(2, 3), RationalFraction(0, 27), RationalFraction(2, 3), testNumber++);

	option(RationalFraction(2, 3), RationalFraction(1, 1), RationalFraction(1, 1), testNumber++);

	option(RationalFraction(2, -3), RationalFraction(-2, 3), RationalFraction(2, 3), testNumber++);
}

int testGCF(RationalFraction lho, RationalFraction rho, RationalFraction expected, int testNumber)
{
	int numeratorLHO = *(lho.TakeNumeratorAdress()), numeratorRHO = *(rho.TakeNumeratorAdress());
	int denominatorLHO = *(lho.takeDenominatorAdress()), denominatorRHO = *(rho.takeDenominatorAdress());

	RationalFraction actual(GCF(numeratorLHO, numeratorRHO), (GCF(denominatorLHO, denominatorRHO)));

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

RationalFraction addition(RationalFraction lho, RationalFraction rho)
{
	int numerator, denominator;

	denominator = *(lho.takeDenominatorAdress()) * *(rho.takeDenominatorAdress());
	numerator = (denominator / *(lho.takeDenominatorAdress())) * *(lho.TakeNumeratorAdress()) + (denominator / *(rho.takeDenominatorAdress())) * *(rho.TakeNumeratorAdress());

	int commonFactor = GCF(numerator, denominator);
	numerator /= commonFactor;
	denominator /= commonFactor;

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction addition(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int numerator, denominator;

	denominator = *(lho.takeDenominatorAdress()) * *(rhFraction.takeDenominatorAdress());
	numerator = (denominator / *(lho.takeDenominatorAdress())) * *(lho.TakeNumeratorAdress()) + (denominator / *(rhFraction.takeDenominatorAdress())) * *(rhFraction.TakeNumeratorAdress());

	int commonFactor = GCF(numerator, denominator);
	numerator /= commonFactor;
	denominator /= commonFactor;

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction subtraction(RationalFraction minuend, RationalFraction subtrahend)
{
	return addition(minuend, multiplication(subtrahend, -1));
}

RationalFraction subtraction(RationalFraction minuend, int subtrahend)
{
	subtrahend *= -1;

	return addition(minuend, subtrahend);
}

RationalFraction multiplication(RationalFraction lho, RationalFraction rho)
{
	int numerator, denominator;

	numerator = *(lho.TakeNumeratorAdress()) * *(rho.TakeNumeratorAdress());
	denominator = *(lho.takeDenominatorAdress()) * *(rho.takeDenominatorAdress());

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction multiplication(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int numerator, denominator;

	numerator = *(lho.TakeNumeratorAdress()) * *(rhFraction.TakeNumeratorAdress());
	denominator = *(lho.takeDenominatorAdress()) * *(rhFraction.takeDenominatorAdress());

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction division(RationalFraction lho, RationalFraction rho)
{
	if (*(rho.TakeNumeratorAdress()) == 0)
	{
		cout << " The universe collapsed, you divided by zero..." << endl << "The original fraction is returned" << endl;

		return lho;
	}

	reverseFraction(&rho);

	return multiplication(lho, rho);
}

RationalFraction division(RationalFraction lho, int rho)
{
	if (rho == 0)
	{
		cout << " The universe collapsed, you divided by zero..." << endl << "The original fraction is returned" << endl;

		return lho;
	}

	RationalFraction rhFraction = toRationalFraction(rho);

	reverseFraction(&rhFraction);

	return multiplication(lho, rhFraction);
}

RationalFraction power(RationalFraction basis, int exponent)
{
	int numerator = 1, denominator = 1;

	if (exponent < 0)
	{
		reverseFraction(&basis);
	}

	for (int i = 0; i < abs(exponent); i++)
	{
		numerator *= *(basis.TakeNumeratorAdress());
		denominator *= *(basis.takeDenominatorAdress());
	}

	RationalFraction answer(numerator, denominator);

	return answer;
}

void squareRoot(RationalFraction* fraction)
{
	*(fraction->TakeNumeratorAdress()) = sqrt(*(fraction->TakeNumeratorAdress()));
	*(fraction->takeDenominatorAdress()) = sqrt(*(fraction->takeDenominatorAdress()));
}

void reverseFraction(RationalFraction* fraction)
{
	if (*(fraction->TakeNumeratorAdress()) == 0)
	{
		cout << " There is no reverse for zero" << endl;
		return;
	}

	swap(fraction->takeDenominatorAdress(), fraction->TakeNumeratorAdress());
}

RationalFraction greatestCommonFactor(RationalFraction lho, RationalFraction rho)
{
	int leftNumerator = *(lho.TakeNumeratorAdress()), leftDenominator = *(lho.takeDenominatorAdress());
	int rightNumerator = *(rho.TakeNumeratorAdress()), rightDenominator = *(rho.takeDenominatorAdress());

	int numerator = GCF(*(lho.TakeNumeratorAdress()), *(rho.TakeNumeratorAdress()));
	int denominator = GCF(*(lho.takeDenominatorAdress()), *(rho.takeDenominatorAdress()));

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction greatestCommonFactor(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int leftNumerator = *(lho.TakeNumeratorAdress()), leftDenominator = *(lho.takeDenominatorAdress());
	int rightNumerator = *(rhFraction.TakeNumeratorAdress()), rightDenominator = *(rhFraction.takeDenominatorAdress());

	int	numerator = GCF(*(lho.TakeNumeratorAdress()), *(rhFraction.TakeNumeratorAdress()));
	int	denominator = GCF(*(lho.takeDenominatorAdress()), *(rhFraction.takeDenominatorAdress()));

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction leastCommonMultiple(RationalFraction lho, RationalFraction rho)
{
	return division(multiplication(lho, rho), greatestCommonFactor(lho, rho));
}

RationalFraction leastCommonMultiple(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);

	return division(multiplication(lho, rhFraction), greatestCommonFactor(lho, rho));
}

RationalFraction toRationalFraction(int number)
{
	RationalFraction answer(number, 1);

	return answer;
}
