#include <iostream>

using namespace std;

int GCF(int, int);
void swap(int*, int*);
void menu();
void menuText();
void operationList();
void workWithConsole();
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

	int* takeNumerator()
	{
		int* refNumerator = &numerator;

		return refNumerator;
	}

	int* takeDenominator()
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
};

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
	cout << "Press 3 to exit." << endl;
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
		return ;
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

RationalFraction addition(RationalFraction lho, RationalFraction rho)
{
	int numerator, denominator;

	denominator = *(lho.takeDenominator()) * *(rho.takeDenominator());
	numerator = (denominator / *(lho.takeDenominator())) * *(lho.takeNumerator()) + (denominator / *(rho.takeDenominator())) * *(rho.takeNumerator());

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

	denominator = *(lho.takeDenominator()) * *(rhFraction.takeDenominator());
	numerator = (denominator / *(lho.takeDenominator())) * *(lho.takeNumerator()) + (denominator / *(rhFraction.takeDenominator())) * *(rhFraction.takeNumerator());

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

	numerator = *(lho.takeNumerator()) * *(rho.takeNumerator());
	denominator = *(lho.takeDenominator()) * *(rho.takeDenominator());

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction multiplication(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int numerator, denominator;

	numerator = *(lho.takeNumerator()) * *(rhFraction.takeNumerator());
	denominator = *(lho.takeDenominator()) * *(rhFraction.takeDenominator());

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction division(RationalFraction lho, RationalFraction rho)
{
	if (*(rho.takeNumerator()) == 0)
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
		numerator *= *(basis.takeNumerator());
		denominator *= *(basis.takeDenominator());
	}

	RationalFraction answer(numerator, denominator);

	return answer;
}

void squareRoot(RationalFraction* fraction)
{
	*(fraction->takeNumerator()) = sqrt(*(fraction->takeNumerator()));
	*(fraction->takeDenominator()) = sqrt(*(fraction->takeDenominator()));
}

void reverseFraction(RationalFraction* fraction)
{
	if (*(fraction->takeNumerator()) == 0)
	{
		cout << " There is no reverse for zero" << endl;
		return;
	}

	swap(fraction->takeDenominator(), fraction->takeNumerator());
}

RationalFraction greatestCommonFactor(RationalFraction lho, RationalFraction rho)
{
	int leftNumerator = *(lho.takeNumerator()), leftDenominator = *(lho.takeDenominator());
	int rightNumerator = *(rho.takeNumerator()), rightDenominator = *(rho.takeDenominator());

	int numerator = GCF(*(lho.takeNumerator()), *(rho.takeNumerator()));
	int denominator = GCF(*(lho.takeDenominator()), *(rho.takeDenominator()));

	RationalFraction answer(numerator, denominator);

	return answer;
}

RationalFraction greatestCommonFactor(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int leftNumerator = *(lho.takeNumerator()), leftDenominator = *(lho.takeDenominator());
	int rightNumerator = *(rhFraction.takeNumerator()), rightDenominator = *(rhFraction.takeDenominator());

	int	numerator = GCF(*(lho.takeNumerator()), *(rhFraction.takeNumerator()));
	int	denominator = GCF(*(lho.takeDenominator()), *(rhFraction.takeDenominator()));

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
