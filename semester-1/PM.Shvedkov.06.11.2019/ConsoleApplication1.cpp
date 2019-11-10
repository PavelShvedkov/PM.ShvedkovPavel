#include <iostream>
#include "Service.h" 

using namespace std;

void invertedArray(int*, int*, int);
void workWithConsole();
void testCase(int, int*, int*, int);
void runTests();
void menu();
void displayArray(int*, int);
void initArray(int*, int);
int  initSizeArray();


int main()
{
	menu();
}

void invertedArray(int* sourceArray, int* invArray, int n)
{
	int* pSourceArray;
	int* pInvArray;

	for (pSourceArray = sourceArray, pInvArray = invArray + n - 1; pSourceArray < sourceArray + n; pSourceArray++, pInvArray--)
	{
		int storage = *pSourceArray;
		*pSourceArray = *pInvArray;
		*pInvArray = storage;
	}
}

void workWithConsole()
{

	int n = initSizeArray();
	int* sourceArray = new int[n];
	int* invArray = new int[n];

	initArray(sourceArray, n);
	invertedArray(sourceArray, invArray, n);
	displayArray(invArray, n);
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

void displayArray(int* invArray, int n)
{
	int j = 1;

	for (int* i = invArray; i < invArray + n; i++, j++)
	{
		cout << " a[" << j << "]= " << *i;
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

void testCase(int testNumber, int* array, int* expArray, int n)
{
	int* invTestArray = new int[n];
	invertedArray(array, invTestArray, n);

	bool answer = 1;

	for (int i = 0; i < n; invTestArray++, expArray++)
	{
		if (invTestArray != expArray)
		{
			answer = 0;
			break;
		}
	}

	if (answer)
	{
		cout << " Case #" << testNumber << " ok" << endl;

	}
	else
	{
		cout << " Case #" << testNumber << " has error" << endl;
	}
}

void runTests()
{
	int testNumber = 1;
	int const n = 5;

	int tArray[n] = { 1,2,3,4,5 };
	int tExpArray[n] = { 5,4,3,2,1 };
	int* array = tArray;
	testCase(testNumber++, array, tExpArray, n);

	int tArray1[n] = { 0,0,0,1,1};
	int tExpArray1[n] = { 1,1,0,0,0 };
	array = tArray1;
	testCase(testNumber++, array, tExpArray, n);

	int tArray3[n] = { -3,5,74,325,1234 };
	int tExpArray3[n] = { 1234,325,74,5,-3 };
	array = tArray;
	testCase(testNumber++, array, tExpArray, n);

	int tArray4[n] = { 1,1,1,1,1 };
	int tExpArray4[n] = { 1,1,1,1,1 };
	array = tArray;
	testCase(testNumber++, array, tExpArray, n);

	int tArray5[n] = { 3,3,0,3,3 };
	int tExpArray5[n] = { 3,3,0,3,3 };
	array = tArray5;
	testCase(testNumber++, array, tExpArray, n);




}