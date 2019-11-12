#include <iostream>
#include <ctime>

using namespace std;

int lessThanThis(int*, int, int);
void generateNotDecreasingArray(int*, int);
int enterNumber();
void workWithConsole();
void display(int*, int);
void testCase(int, int*, int, int,int);
void runTests();
void menu();
void menuText();



int main()
{
	menu();
}

void workWithConsole()
{
	int const n = 10;
	int array[n] = { 0 };
	int digit = enterNumber();

	generateNotDecreasingArray(array, n);

	display(array, n);
	
	cout << " Numbers smaller than '" << digit << "' in array:"<< lessThanThis(array, n, digit)<<endl;
}

void testCase(int testNr, int* array, int digit, int expAnswer, int n)
{
	int* testArray=array;

	

	if (lessThanThis(testArray, n, digit) == expAnswer)
	{
		cout << " Case #" << testNr << " ok" << endl;

	}
	else
	{
		cout << " Case #" << testNr << " has error" << endl;
	}
}

void runTests()
{
	int testNumber = 1;
	int const n = 5;

	int tArray1[n] = { 23, 43, 53, 352, 31 };
	testCase(testNumber++,tArray1,  400, 5,n);

	int tArray2[n] = { 224, 241, 124, 532, 132 };
	testCase(testNumber++, tArray2,  12, 0,n);

	int tArray3[n] = { 63, 63, 63, 63, 43 };
	testCase(testNumber++, tArray3, 63, 1,n);

	int tArray4[n] = { 124, 42, 12, 54, 132 };
	testCase(testNumber++, tArray4, 53, 2,n);

	int tArray5[n] = { 12, 3, 123, 2, 1 };
	testCase(testNumber++, tArray5, 4, 3,n);

}

int lessThanThis(int* array, int n, int digit)
{
	int lessles = 0;
	for (int* pointer = array; pointer < array+n; pointer++)
	{
		if (*pointer < digit)
		{
			lessles++;
		}
	}

	return lessles;
}

void display (int* array, int n)
{
	cout << " In array: {";

	for (int* pointer = array; pointer < array + n; pointer++)
	{
		cout << *pointer<<" ";
	}

	cout << "}" << endl;
}

void generateNotDecreasingArray(int* nDArray, int n)
{
	int p = 100;
	srand(time(0));
	for (int* pointer = nDArray, k; pointer < nDArray+n; pointer++)
	{
		k = rand() % p;
		if (k >= *pointer)
		{
			*pointer = k;
		}
	}
}

int enterNumber()
{
	int number;

	cout << " Enter the number below which you want to search:= ";
	cin >> number;

	return number;
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
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