#include <iostream>

using namespace std;

int main()
{
	int number;
	string DOZENS = "", UNITS = "";
	char ok = 'r', space = 0;

	while (ok == 'r')
	{
		int	units = 0, dozens = 0;

		cout << " Enter number smaller 100: ";
		cin >> number;

		if (number >= 13)
		{
			dozens = number / 10;
			units = number % 10;
		}
		else
		{
			if (number != 0)
			{
				units = number;
			}
			else
			{
				UNITS = "Null";
				DOZENS = "";
			}
		}
		switch (units)
		{
		case 1:
			UNITS = "One";
			break;
		case 2:
			UNITS = "Two";
			break;
		case 3:
			UNITS = "Three";
			break;
		case 4:
			UNITS = "Four";
			break;
		case 5:
			UNITS = "Five";
			break;
		case 6:
			UNITS = "Six";
			break;
		case 7:
			UNITS = "Seven";
			break;
		case 8:
			UNITS = "Eith";
			break;
		case 9:
			UNITS = "Nine";
			break;
		case 10:
			UNITS = "Ten";
			break;
		case 11:
			UNITS = "Eleven";
			break;
		case 12:
			UNITS = "Twelve";
			break;
		default:
			;
		}
		switch (dozens)
		{
		case 1:
			DOZENS = "teen";
			break;
		case 2:
			DOZENS = "Twenty";
			break;
		case 3:
			DOZENS = "Thirty";
			break;
		case 4:
			DOZENS = "Fourty";
			break;
		case 5:
			DOZENS = "Fifty";
			break;
		case 6:
			DOZENS = "Sixty";
			break;
		case 7:
			DOZENS = "Seventy";
			break;
		case 8:
			DOZENS = "Eighty";
			break;
		case 9:
			DOZENS = "Ninty";
			break;
		default:
			;
		}

		if (number >= 100)
		{
			cout << " I'ts not twodigits "  << endl;
		}
		else
		{
			if (number>=20)
			{
				cout << " I'ts " << DOZENS << space << UNITS << endl;
			}
			else
			{
				cout << " I'ts " << UNITS << DOZENS << endl;
			}
		}

		cout << " Press r to continue " << endl;
		cin >> ok;
		system("cls");

	}
	return 0;
}