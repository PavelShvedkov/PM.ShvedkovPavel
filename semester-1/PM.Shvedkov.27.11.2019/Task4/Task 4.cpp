#include <iostream>
#include "WorkWithStrings.h"
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"

using namespace std;

void menu();
void workWithConsole();

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
			runTests();
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
	/*int n = 255;
	char* subStringInsertiable=new char[n];
	char* subStringRemovable=new char[n];
	char* string=new char[n];*/


	char subStringInsertiable[] = "G";
	char subStringRemovable[] = "boot";
	char string[] = "Boat boot reboot boot kaput";

	/*cout << " Enter source string:  ";
	cin.getline(string);
	cout << " Enter removable string:  ";
	cin.getline(subStringRemovable);
	cout << " Enter insertiable string:  ";
	cin.getline(subStringRemovable);*/

	int sizesRelations = compressionStrings(subStringInsertiable, subStringRemovable);
	int  sizeSSR = getLenght(subStringRemovable);

	cout << trancfers(string, subStringRemovable, subStringInsertiable, sizesRelations, sizeSSR) << endl;
	
}




