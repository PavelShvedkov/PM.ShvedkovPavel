#include <iostream>
#include "JobWithArrays.h"
#include "Service.h" 

using namespace std;

int invertedArray(int[], int[], int);
void workWithConsole();
void testCase(int,int , int , int , int , int , int , int , int , int , int );
void runTests();
void menu();


int primeArray(int[], int)
{
	return 0;
}

int main()
{
		menu();
}

int invertedArray(int sourceArray[], int invArray[], int const n)
{
	for (int i = 0, j = n - 1; i < n; i++, j--)
	{
		invArray[i] = sourceArray[j];
	}

	return 0;
}

void workWithConsole()
{

	int const n = 10;
	int sourceArray[n] = { 0 };
	int invArray[n] = { 0 };

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

void testCase(int testNumber,int el1, int el2, int el3, int el4, int el5, int expel1, int expel2, int expel3, int expel4, int expel5)
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

	int invertedTestArray[n] = { 0 };

	invertedArray(testArray, invertedTestArray, n);

	bool answer = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (invertedTestArray[i] != expArray[i])
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

	testCase(testNumber++,1,2,3,4,5,5,4,3,2,1);
	testCase(testNumber++,0,0,0,1,1,1,1,0,0,0);
	testCase(testNumber++,-3,5,74,325,1234,1234,325,74,5,-3);
	testCase(testNumber++,1,1,1,1,1,1,1,1,1,1);
	testCase(testNumber++,3,3,0,3,3,3,3,0,3,3);
}
