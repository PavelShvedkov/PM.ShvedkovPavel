#include <iostream>
#include "RationalFraction.h"

using namespace std;

RationalFraction::RationalFraction()
{
	numerator = 0;
	denominator = 1;
}
RationalFraction::RationalFraction(int num, int denom)
{
	numerator = num;
	denominator = denom;
}

int RationalFraction::getNumerator() const
{
	return numerator;
}
int RationalFraction::getDenominator() const
{
	return denominator;
}

void RationalFraction::enter()
{
	cout << " Enter integer numerator: ";
	cin >> numerator;

	cout << " Enter integer denominator: ";
	cin >> denominator;
}
void RationalFraction::display(bool  newString)
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

bool RationalFraction::operator ==(const RationalFraction& rho)const
{
	return (numerator == rho.getNumerator() && denominator == rho.getDenominator());
}
bool RationalFraction::operator !=(const RationalFraction& rho)const
{
	return (numerator != rho.getNumerator() || denominator != rho.getDenominator());
}
bool RationalFraction::operator>(const RationalFraction& rho)const
{
	int denominator = this->getDenominator() * rho.getDenominator();
	int numeratorThis = (denominator / this->getDenominator()) * this->getNumerator();
	int numerator = (denominator / rho.getDenominator()) * rho.getNumerator();

	return numeratorThis > numerator;
}
bool RationalFraction::operator>=(const RationalFraction& rho)const
{
	int denominator = this->getDenominator() * rho.getDenominator();
	int numeratorThis = (denominator / this->getDenominator()) * this->getNumerator();
	int numerator = (denominator / rho.getDenominator()) * rho.getNumerator();

	return numeratorThis >= numerator;
}
bool RationalFraction::operator<(const RationalFraction& rho)const
{
	int denominator = this->getDenominator() * rho.getDenominator();
	int numeratorThis = (denominator / this->getDenominator()) * this->getNumerator();
	int numerator = (denominator / rho.getDenominator()) * rho.getNumerator();

	return numeratorThis < numerator;
}
bool RationalFraction::operator<=(const RationalFraction& rho)const
{
	int denominator = this->getDenominator() * rho.getDenominator();
	int numeratorThis = (denominator / this->getDenominator()) * this->getNumerator();
	int numerator = (denominator / rho.getDenominator()) * rho.getNumerator();

	return numeratorThis <= numerator;
}
RationalFraction RationalFraction::operator +(const RationalFraction& rho)const
{
	RationalFraction sum = *this;
	return sum += rho;
}
RationalFraction& RationalFraction::operator += (const RationalFraction& rho)
{
	int numerator, denominator;

	denominator = this->getDenominator() * rho.getDenominator();
	numerator = (denominator / this->getDenominator()) * this->getNumerator() + (denominator / rho.getDenominator()) * rho.getNumerator();

	int commonFactor = GCF(numerator, denominator);
	numerator /= commonFactor;
	denominator /= commonFactor;

	*this = RationalFraction(numerator, denominator);

	return *this;
}
RationalFraction RationalFraction::operator-(const RationalFraction& rho)const
{
	RationalFraction difference = *this;

	return difference -= rho;
}
RationalFraction& RationalFraction:: operator -=(const RationalFraction& rho)
{
	int numerator, denominator;

	denominator = this->getDenominator() * rho.getDenominator();
	numerator = (denominator / this->getDenominator()) * this->getNumerator() - (denominator / rho.getDenominator()) * rho.getNumerator();

	int commonFactor = GCF(numerator, denominator);
	numerator /= commonFactor;
	denominator /= commonFactor;

	*this = RationalFraction(numerator, denominator);

	return *this;
}
RationalFraction RationalFraction:: operator *(const RationalFraction& rho)const
{
	int numerator, denominator;

	numerator = this->getNumerator() * rho.getNumerator();
	denominator = this->getDenominator() * rho.getDenominator();

	return RationalFraction(numerator, denominator);
}
RationalFraction& RationalFraction:: operator *=(const RationalFraction& rho)
{
	int numerator, denominator;

	numerator = this->getNumerator() * rho.getNumerator();
	denominator = this->getDenominator() * rho.getDenominator();

	*this = RationalFraction(numerator, denominator);

	return *this;
}
RationalFraction RationalFraction::operator /(const RationalFraction& rho)const
{
	if (rho.getNumerator() == 0)
	{
		cout << " The universe collapsed, you divided by zero..." << endl << " The original fraction is returned" << endl;

		return *this;
	}

	return (*this * RationalFraction(rho.getDenominator(), rho.getNumerator()));
}
RationalFraction& RationalFraction::operator /=(const RationalFraction& rho)
{
	if (rho.getNumerator() == 0)
	{
		cout << " The universe collapsed, you divided by zero..." << endl << " The original fraction is returned" << endl;

		return *this;
	}

	return *this *= RationalFraction(rho.getDenominator(), rho.getNumerator());
}

RationalFraction RationalFraction::reverseFraction()
{
	RationalFraction reverse = *this;

	if (reverse.getNumerator() == 0)
	{
		cout << " There is no reverse for zero" << endl;
		return reverse;
	}

	return RationalFraction(reverse.getDenominator(), reverse.getNumerator());
}
int RationalFraction::GCF(int lho, int rho)
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

RationalFraction addition(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int numerator, denominator;

	denominator = lho.getDenominator() * rhFraction.getDenominator();
	numerator = (denominator / lho.getDenominator()) * lho.getNumerator() + (denominator / rhFraction.getDenominator()) * rhFraction.getNumerator();

	return 	RationalFraction(numerator, denominator);

}

RationalFraction subtraction(RationalFraction minuend, int subtrahend)
{
	subtrahend *= -1;

	return addition(minuend, subtrahend);
}

RationalFraction multiplication(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);
	int numerator, denominator;

	numerator = lho.getNumerator() * rhFraction.getNumerator();
	denominator = lho.getDenominator() * rhFraction.getDenominator();

	return 	RationalFraction(numerator, denominator);

}

RationalFraction division(RationalFraction lho, int rho)
{
	if (rho == 0)
	{
		cout << " The universe collapsed, you divided by zero..." << endl;
		cout << "The original fraction is returned" << endl;

		return lho;
	}

	RationalFraction rhFraction = toRationalFraction(rho);

	return (lho * rhFraction.reverseFraction());
}

RationalFraction power(RationalFraction basis, int exponent)
{
	int numerator = 1, denominator = 1;

	if (exponent < 0)
	{
		basis = basis.reverseFraction();
	}

	for (int i = 0; i < abs(exponent); i++)
	{
		numerator *= basis.getNumerator();
		denominator *= basis.getDenominator();
	}

	return 	RationalFraction(numerator, denominator);
}

RationalFraction squareRoot(RationalFraction fraction)
{
	int numerator = sqrt(fraction.getNumerator()), denominator = sqrt(fraction.getDenominator());

	return RationalFraction(numerator, denominator);
}

RationalFraction greatestCommonFactor(RationalFraction lho, RationalFraction rho)
{
	if (lho.getNumerator() == 0 || rho.getNumerator() == 0)
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

RationalFraction greatestCommonFactor(RationalFraction lho, int rho)
{
	return	greatestCommonFactor(lho, toRationalFraction(rho));
}

RationalFraction leastCommonMultiple(RationalFraction lho, RationalFraction rho)
{
	return ((lho * rho) / greatestCommonFactor(lho, rho));
}

RationalFraction leastCommonMultiple(RationalFraction lho, int rho)
{
	RationalFraction rhFraction = toRationalFraction(rho);

	return ((lho * rhFraction) / greatestCommonFactor(lho, rho));
}

RationalFraction toRationalFraction(int number)
{
	return RationalFraction(number, 1);
}

RationalFraction abs(const RationalFraction& rho)
{
	if (rho.getNumerator() < 0&& rho.getDenominator() > 0)
	{
		return rho * RationalFraction(-1, 1);
	}
	else if (rho.getNumerator() > 0&&rho.getDenominator() < 0)
	{
		return rho * RationalFraction(1, -1);
	}

	return rho;
}