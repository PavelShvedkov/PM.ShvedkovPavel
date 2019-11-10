#include <iostream>
#include <ctime>

using namespace std;

int lessThanThis(int*, int, int);
void generateNotDecreasingArray(int*, int);
int enterNumber();
void workWithConsole();
void display(int*, int);
void testCase(int, int, int, int, int, int, int, int);
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

void testCase(int testNr, int el1, int el2, int el3, int el4, int el5, int digit, int expAnswer)
{
	int const n = 5;
	int testArray[n];

	testArray[0] = el1;
	testArray[1] = el2;
	testArray[2] = el3;
	testArray[3] = el4;
	testArray[4] = el5;

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

	testCase(testNumber++, 23, 43, 53, 352, 31, 400, 5);
	testCase(testNumber++, 224, 241, 124, 532, 132, 12, 0);
	testCase(testNumber++, 63, 63, 63, 63, 43, 63, 1);
	testCase(testNumber++, 124, 42, 12, 54, 132, 53, 2);
	testCase(testNumber++, 12, 3, 123, 2, 1, 4, 3);

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