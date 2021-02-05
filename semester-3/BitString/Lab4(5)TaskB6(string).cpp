#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include "String.h"
#include "BitString.h"

using namespace std;

void summBitStrings();

int main()
{
	/*const int length = 10;
	char source[length] = "-111";
	BitString a(source);
	BitString b("-111");
	String d = "as";
	String c = " me";
	
	cout << (a==b);*/

	summBitStrings();
}

void summBitStrings()
{
	String lho, rho;
	char button='s';

	while (true)
	{
		cout << " Enter first string:" << endl;
		cin >> lho;
		BitString lbs = lho;
		system("cls");

		cout << " Enter second string:" << endl;
		cin >> rho;
		BitString rbs = rho;
		system("cls");

		cout << " Summ " << lbs << " and " << rbs << " = " << lbs + rbs;
		system("pause");
		system("cls");

		cout << " Enter Y to continue: " << endl;
		cin >> button;
		system("cls");

		if (button!='Y')
		{
			break;
		}
	}
}
