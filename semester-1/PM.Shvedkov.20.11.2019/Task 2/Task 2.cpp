#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"

using namespace std;

void workWithConsole();
void menu();
void runTest();

int main()
{
	menu();
}


void workWithConsole()
{
	char* stringA = new char[100];
	char* stringB = new char[100];

	cout << " Enter string A" << endl;
	cin >> stringA;

	cout << " Enter string B" << endl;
	cin >> stringB;


	if (compressionStrings(stringA, stringB)==1)
	{
		cout << " String:" << stringA << " is equal to string: " << stringB << endl;
	}
	else
	{
		if (compressionStrings(stringA, stringB) == 3)
		{
			cout << " String: '" << stringA << "' more string: '" << stringB <<"'"<< endl;
		}
		else
		{
			cout << " String: '" << stringA << "' less string: '" << stringB <<"'"<< endl;
		}
	}
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

void testCase(char* stringA, char* stringB, bool expAnswer)
{
	if (expAnswer == equivalenceStrings(stringA, stringB))
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}
}
