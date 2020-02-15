#include"HeaderForHW.h"
#include <iostream>

using namespace std;

void menu();
void workWithConsole();
void runTests();
void testCase(int);
void menuText();

int main()
{
	menu();

	return 0;
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
	int n;

	cout << " Enter array size vectors" << endl << " n: ";
	cin >> n;

	point* vectors = initArray(n);

	fillingArray(vectors, n);

	cout << " Unsorting vectors:" << endl;
	displayPoints(vectors, n);

	sortVectors(vectors,n);

	cout << " Sorting vectors:" << endl;
	displayPoints(vectors, n);

	delete[]vectors;
}

void runTests()
{
	int testNumber = 1;

	testCase(testNumber++);
	testCase(testNumber++);
	testCase(testNumber++);
	testCase(testNumber++);
	testCase(testNumber++);
}

void testCase(int number)
{
	const int n = 5;

	point* actual=initArray(n, 1);
	point* expected=initArray(n, 1);
	
	shuffleArray(actual, n);
	sortVectors(actual, n);

	if (areEqual(actual, n,expected, n))
	{
		cout << " Test #" << number << " is ok" << endl;
	}
	else
	{
		cout << " Test #" << number << " is failed" << endl;
	}
	
	delete[]actual;
	delete[]expected;
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}
