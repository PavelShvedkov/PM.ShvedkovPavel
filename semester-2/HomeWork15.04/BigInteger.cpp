#define _CRT_SECURE_NO_WARNINGS
#include "BigInteger.h"


BigInteger::BigInteger(const char* digit)
{
	setDigitLength(strlen(digit));
	setDigits(digit);
}
BigInteger::BigInteger(BigInteger const& other)
{
	this->setDigitLength(other.getLength());

	digits = new char[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
	{
		digits[i] = other.getDigit(i);
	}

	digits[getLength()] = '\0';
}
BigInteger::~BigInteger()
{
	delete[]digits;
}

int BigInteger::getLength() const
{
	return digitLength;
}
char BigInteger::getDigit(int index) const
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return digits[index];
}

void BigInteger::display() const
{
	cout << digits << endl;
}
BigInteger BigInteger::displaySum(const BigInteger& other)
{
	BigInteger sum = *this + other;
	int lhsLength = this->getLength(), rhsLength = other.getLength(), sumLength = sum.getLength();
	int firstWidth = sumLength - lhsLength, secodWidth = sumLength - rhsLength;

	for (int i = 0; i < firstWidth; i++)
	{
		cout << " ";
	}

	cout << *this << endl;
	cout << '+' << endl;

	for (int i = 0; i < secodWidth; i++)
	{
		cout << " ";
	}

	cout << other << endl;

	for (int i = 0; i < sumLength; i++)
	{
		cout << '\xcd';
	}

	cout << endl << sum << endl;

	return sum;
}
BigInteger BigInteger::displayDiff(const BigInteger& other)
{
	BigInteger diff = *this - other;
	int lhsLength = this->getLength(), rhsLength = other.getLength(), diffLength = diff.getLength();
	int firstWidth = diffLength - lhsLength, secodWidth = diffLength - rhsLength;

	for (int i = 0; i < firstWidth; i++)
	{
		cout << " ";
	}

	cout << *this << endl;
	cout << '-' << endl;

	for (int i = 0; i < secodWidth; i++)
	{
		cout << " ";
	}

	cout << other << endl;

	for (int i = 0; i < diffLength; i++)
	{
		cout << '\xcd';
	}

	cout << endl << diff << endl;

	return diff;
}

void BigInteger::randomFill(int newLength)
{
	srand(time(0));

	if (newLength<=0)
	{
		throw std::invalid_argument(" !!! ");
	}

	this->setDigitLength(newLength);
	char* buffer = new char[newLength + 1];

	for (int i = 0; i < newLength; i++)
	{
		buffer[i] = toChar(rand() % 10);
	}
	
	buffer[newLength] = '\0';

	this->setDigits(resize(buffer));

	delete[]buffer;
}

char& BigInteger::operator[](const int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return digits[index];
}
const char& BigInteger::operator [](const int index)const
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return digits[index];
}
BigInteger& BigInteger:: operator = (const BigInteger& rho)
{
	if (digits)
	{
		delete[]digits;
	}

	int newLength = rho.getLength();
	this->setDigitLength(rho.getLength());
	this->setDigits(rho.digits);

	return *this;
}
BigInteger& BigInteger::operator+=(const BigInteger& other)
{
	*this = BigInteger(resize(add(this->digits, other.digits)));

	return *this;
}
BigInteger BigInteger::operator +(const BigInteger& other)const
{
	BigInteger sum = *this;

	return sum += other;
}
BigInteger& BigInteger::operator-=(const BigInteger& other)
{
	*this = BigInteger(resize(subtract(this->digits, other.digits)));

	return *this;
}
BigInteger BigInteger::operator -(const BigInteger& other)const
{
	BigInteger sum = *this;

	return sum -= other;
}
ostream& operator << (ostream& out, const BigInteger& object)
{
	int length = object.getLength();
	char* buffer = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		buffer[i] = object.getDigit(i);
	}

	buffer[length] = '\0';

	out << buffer;

	delete[]buffer;

	return out;
}

void BigInteger::setDigitLength(int length)
{
	if (length < 0)
	{
		throw std::out_of_range(" Invalid size");
	}

	digitLength = length;
}
void BigInteger::setDigits(const char* digit)
{
	if (!digit)
	{
		throw std::invalid_argument(" !!! ");
	}

	if (!isDataValid(digit))
	{
		throw std::invalid_argument(" !!! ");
	}

	if (digits)
	{
		delete[]digits;
	}

	digits = new char[digitLength + 1];

	strcpy(digits, digit);
}

char* BigInteger::resize(const char* source)
{
	int i = 0, sign = 0;

	if (source[0] == '-')
	{
		++i;
		sign = 1;
	}

	while (source[i] == '0')
	{
		++i;
	}

	int newLength = strlen(source) + sign - i;
	char* buffer = new char[newLength + 1]{ 0 };

	if (sign)
	{
		strcpy(buffer, "-");
	}

	strcat(buffer, source + i);

	return buffer;
}
char* BigInteger::add(char* lhs, char* rhs)
{
	int lhsLength = strlen(lhs), rhsLength = strlen(rhs);

	if (lhsLength < rhsLength)
	{
		swap(lhs, rhs);
		lhsLength = strlen(lhs);
		rhsLength = strlen(rhs);
	}

	char* result = new char[lhsLength + 2];
	result[lhsLength + 1] = '\0';
	strcpy(result, "0");
	int unit = 0;
	int a = 0, b = 0, i = 0, j = 0, k = 0;

	for (i = lhsLength - 1, j = rhsLength - 1, k = lhsLength; i >= lhsLength - rhsLength; --i, --j, --k)
	{
		a = b = 0;
		a = toDigit(lhs[i]) + unit;
		b = toDigit(rhs[j]);
		int c = a + b;
		unit = c / 10;
		c %= 10;
		result[k] = toChar(c);
	}

	for (; i >= 0; --i, --k)
	{
		a = toDigit(lhs[i]) + unit;
		unit = a / 10;
		a %= 10;
		result[k] = toChar(a);
	}

	result[k] = toChar(unit);

	return result;
}
char* BigInteger::subtract(char* lhs, char* rhs)
{
	int lhsLength = strlen(lhs), rhsLength = strlen(rhs);
	bool sign = 0;

	if (lhsLength < rhsLength)
	{
		swap(lhs, rhs);
		lhsLength = strlen(lhs);
		rhsLength = strlen(rhs);
		sign = 1;
	}

	char* result = new char[lhsLength + 2];

	if (sign)
	{
		strcpy(result, "-");
	}
	else
	{
		strcpy(result, "0");
	}

	result[lhsLength + 1] = '\0';

	int unit = 0;
	int a = 0, b = 0, i = 0, j = 0, k = 0;

	for (i = lhsLength - 1, j = rhsLength - 1, k = lhsLength; i >= lhsLength - rhsLength; --i, --j, --k)
	{
		a = b = 0;
		a = toDigit(lhs[i]) - unit;
		b = toDigit(rhs[j]);
		if (a < b)
		{
			a += 10;
			unit = 1;
		}
		int c = a - b;
		result[k] = toChar(c);
	}

	for (; i >= 0; --i, --k)
	{
		a = toDigit(lhs[i]) - unit;
		if (a < 0)
		{
			a += 10;
		}
		result[k] = toChar(a);
	}

	return result;
}
void BigInteger::swap(char*& lhs, char*& rhs)
{
	char* temp = lhs;
	lhs = rhs;
	rhs = temp;
}
int BigInteger::toDigit(char symbol)
{
	return symbol - '0';
}
char BigInteger::toChar(int digit)
{
	if (digit < '\0')
	{
		return 0;
	}

	return digit + '0';
}
bool BigInteger::isDataValid(const char* digit)
{
	int i = 0;

	if (digit[0] == '-')
	{
		++i;
	}

	for (; i < strlen(digit); ++i)
	{
		if (digit[i] < '0' || digit[i]>'9')
		{
			return false;
		}
	}

	return true;
}

