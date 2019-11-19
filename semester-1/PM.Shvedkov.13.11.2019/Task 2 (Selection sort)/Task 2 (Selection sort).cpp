#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"

using namespace std;

void menu();
void workWithConsole();
void runTests();


int main()
{
	menu();
}

void workWithConsole()
{
	int n=enterNumber();
	int* array = allocateMemory(n);
	randomArray(array, n, 10);
	displayArray(array, n);
	selectionSort(array, n);
	displayArray(array, n);
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

void testCase(int* expected, int n, int* actual, int m)
{
	selectionSort(actual, m);

	if (areEqual(expected, n, actual, m))
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}


}

void runTests()
{
	int testNumber = 1;

	int n = 5;

	int* expected = new int[n] { 1, 2, 3, 4, 5 };
	int* actual = new int[n] {5, 4, 3, 2, 1};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	actual = new int[n] {5, 4, 3, 2, 1, 8, 7, 10, 6, 9};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	actual = new int[n] {3, 3, 1, 1, 2, 2, 5, 5, 4, 4};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);


}
