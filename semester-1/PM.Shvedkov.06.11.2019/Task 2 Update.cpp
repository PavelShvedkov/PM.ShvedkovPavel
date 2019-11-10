#include <iostream>

using namespace std;

void initArray(int*, int);
int  initSizeArray();
void displayArray(int*, int);
void menu();
void menuText();
void primeArray(int*, int*, int);
void workWithConsole();
void testCase(int, int, int, int, int, int, int, int, int, int, int);
void runTests();


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

void initArray(int* array, int n)
{
	int j = 1;

	for (int* i = array; i < array + n; i++, j++)
	{
		cout << " a [" << j << "]= ";
		cin >> *i;
	}
}

int initSizeArray()
{
	int n;

	cout << " Enter size source array:= ";
	cin >> n;
	return n;
}

void runTests()
{
	int testNumber = 1;

	testCase(testNumber++, 23, 14, 11, 12, 4, 23, 0, 11, 0, 0);
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
	int n = initSizeArray();
	int* sourceArray = new int[n];
	int* primArray = new int[n];
	

	initArray(sourceArray, n);
	primeArray(sourceArray, primArray, n);
	displayArray(primArray, n);

	
}

void displayArray(int* invArray, int n)
{
	int j = 1;

	for (int* i = invArray; i < invArray + n; i++, j++)
	{
		cout << " a[" << j << "]= " << *i;
	}
}

void primeArray(int* array, int* primeArray, int n)
{
	int* pArray = array;
	int* pPrimeArray = primeArray;

	for (; pArray < array+n; pArray++)
	{
		for (int k = 2; k < *pArray; k++)
		{
			if (*pArray % k != 0)
			{
				*pPrimeArray = *pArray;
				pPrimeArray++;
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