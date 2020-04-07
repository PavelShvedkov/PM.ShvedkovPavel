#pragma once
#include <iostream>

using namespace std;

bool polindromTaste(int);
int digitReplacement(int, short, short);
bool sampleNumber(int);
int deleteDigitInNumber(int, short);
void sequence(int, short&, short&, short&, short&, short&);
int unitsInBinary(int);
int hexadecimalCharacter(int, char);
void hexRepresentation(int);

//void hexRepresentation(int number)
//{
//	bool sign=0;
//
//	if (number>=0)
//	{
//		sign = 1;
//	}
//
//	number = abs(number);
//	char symbols[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//	char* hexRepr = "", *reverseHexRepr = "";
//	int quotient=number, reminder;
//
//	if (number<16)
//	{
//		if (!sign)
//		{
//			reverseHexRepr ='-'+ symbols[number];
//		}
//		else
//		{
//			reverseHexRepr = symbols[number];
//		}
//
//		cout << reverseHexRepr<<'\t';
//		return;
//	}
//	else
//	{
//		while (quotient)
//		{
//			reminder = number % 16;
//			quotient = (number / 16);
//			hexRepr += symbols[reminder];
//			number = quotient;
//		}
//
//		if (!sign)
//		{
//			hexRepr += '-';
//		}
//
//		for (int i = hexRepr.length(); i >= 0; i--)
//		{
//			reverseHexRepr += hexRepr[i];
//		}
//
//		cout << reverseHexRepr<<'\t';
//	}
//}


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

int unitsInBinary(int decimalNumber)
{
	int counter = 0;

	for (; decimalNumber > 0; decimalNumber /= 2)
	{
		if (decimalNumber % 2)
		{
			counter++;
		}
	}
	return counter;
}

void sequence(int number, short& requality, short& rmore, short& rsmaller, short& rmorePerUnit, short& rsmallerPerUnit)
{
	number = abs(number);

	for (; number >= 10; number /= 10)
	{
		if ((number % 10) < ((number / 10) % 10))
		{
			((number % 10) == (((number / 10) % 10) - 1)) ? rsmallerPerUnit++ : rsmaller++;
		}
		else
		{
			if ((number % 10) > ((number / 10) % 10))
			{
				((number % 10) == (((number / 10) % 10) + 1)) ? rmorePerUnit++ : rmore++;
			}
			else
			{
				requality++;
			}
		}

	}
}

int deleteDigitInNumber(int number, short removable)
{
	int reflection = 0;

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

	return number;
}

bool sampleNumber(int number)
{
	bool check = false;

	number = abs(number);

	for (int k = 2; k < number; k++)
	{
		if (number % k == 0)
		{
			return check;
		}

		check = true;
	}
	return check;
}

int digitReplacement(int number, short removable, short deputy)
{
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

	return number;
}

bool polindromTaste(int number)
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

	return out;
}

