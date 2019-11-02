#include <iostream>

using namespace std;

void initArray(int array[], int n);
void workWithConsole();
void testCase(int, int, int, int, int, int, int, int, int, int, int);
void runTests();
void menu();
void menuText();
void primeArray(int[], int[], int);
void display(int[], int);


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

void initArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << (i + 1) << "]= ";
		cin >> array[i];
	}
}

void runTests()
{
	int testNumber = 1;

	testCase(testNumber++, 23, 14, 11, 12, 4, 23, 0,11, 0, 0);
	testCase(testNumber++, 0, 12, 32, 42, 21, 0, 0, 0, 0, 0);
	testCase(testNumber++, 3, 5, 7, 11, 13, 3, 5, 7, 11, 13);
	testCase(testNumber++, 12, 42, 22, 13, 22, 0, 0, 0, 13, 0);
	testCase(testNumber++, 54, 23, 12, 23, 23, 0, 23, 0, 23, 23);

}

void testCase(int testNr, int el1, int el2, int el3, int el4, int el5, int expel1, int expel2, int expel3, int expel4, int expel5)
{
	int const n = 5;
	int testArray[n];

	testArray[0] = el1;
	testArray[1] = el2;
	testArray[2] = el3;
	testArray[3] = el4;
	testArray[4] = el5;

	int expArray[n];

	expArray[0] = expel1;
	expArray[1] = expel2;
	expArray[2] = expel3;
	expArray[3] = expel4;
	expArray[4] = expel5;

	int primeTestArray[n] = { 0 };

	for (int i = 0, j = 0; i < n; i++, j++)
	{
		for (int k = 2; k < testArray[i]; k++)
		{
			if (testArray[i] % k == 0)
			{
				primeTestArray[j] = 0;
				break;
			}
			else
			{
				primeTestArray[j] = testArray[i];
			}

		}
	}

	bool answer = 1;

	for (int i = 0; i < n; i++)
	{
		if (primeTestArray[i] != expArray[i])
		{
			answer = 0;
			break;
		}
	}

	if (answer)
	{
		cout << " Case #" << testNr << " ok" << endl;
	}
	else
	{
		cout << " Case #" << testNr << " has error" << endl;
	}
}

void workWithConsole()
{
	int const n = 10;
	int array[n] = { 0 };
	int primArray[n] = { 0 };

	initArray(array, n);
	primeArray(array, primArray, n);

	display(primArray, n);
}

void display(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void primeArray(int array[], int primeArray[], int n)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		for (int k = 2; k < array[i]; k++)
		{
			if (array[i] % k != 0)
			{
				primeArray[j] = array[i];
			}
		}
	}


}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}
