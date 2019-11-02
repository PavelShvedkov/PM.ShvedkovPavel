#include <iostream>
#include <ctime>

using namespace std;

void sequenceType(int[],int[], int);
void generateRandomArray(int array[], int n);
short sequenceAnalisys(int[]);
void initArray(int array[], int n);
void workWithConsole();
void testCase(int, int, int, int, int, int, int, int,int);
void runTests();
void menu();
void menuText();
void displayResault(short);


int main()
{
	menu();

}

void runTests()
{
	int testNr = 1;

	testCase(testNr++,1,2,3,4,5,4,0,0);
	testCase(testNr++,5,4,3,2,1,0,4,0);
	testCase(testNr++,1,2,2,3,4,3,0,1);
	testCase(testNr++,5,4,4,3,1,0,3,1);
	testCase(testNr++,1,1,1,1,1,0,0,4);
	testCase(testNr++,1,2,2,4,1,2,1,1);

}

void testCase(int testNr, int el1, int el2, int el3, int el4, int el5, int expel1, int expel2, int expel3)
{
	int const n = 5;
	int testArray[n];

	testArray[0] = el1;
	testArray[1] = el2;
	testArray[2] = el3;
	testArray[3] = el4;
	testArray[4] = el5;

	int expAnalysisArray[3];

	expAnalysisArray[0] = expel1;
	expAnalysisArray[1] = expel2;
	expAnalysisArray[2] = expel3;

	int analysisArray[3] = { 0 };

	sequenceType(testArray, analysisArray,n);

	bool answer = 1;

	for (int i = 0; i < n; i++)
	{
		if (analysisArray[i] != expAnalysisArray[i])
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

void primeArray()
{
}

bool sampleNumber(int[])
{
	return false;
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
	int const n = 10;
	int array[n] = { 0 };

	generateRandomArray(array, n);
	//initArray(array, n);

	int analysisArray[3] = { 0 };

	sequenceType(array, analysisArray, n);

	displayResault(sequenceAnalisys(analysisArray));
}

void initArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << (i + 1) << "]= ";
		cin >> array[i];
	}
}

void sequenceType(int array[],int analysisArray[], int n)
{
	for (int i = 1; i < n; i++)
	{
			if (array[i-1] < array[i])
			{
				analysisArray[0]++;//первый меньше второго
			}
			else
			{
				if (array[i-1] > array[i])
				{
					analysisArray[1]++;//первый больше второго
				}
				else
				{
					analysisArray[2]++;//первый равен второму
				}
			}
	}
	cout<< sequenceAnalisys(analysisArray);
}

short sequenceAnalisys(int analysisArray[])
{
	short resultAnalysis;

	if (analysisArray[0] == 0 && analysisArray[1] == 0 )
	{
		resultAnalysis = 1;// монотонная
	}
	else
	{
		if (analysisArray[2] == 0 && analysisArray[1] == 0 )
		{
			resultAnalysis = 2;// возрастающая
		}
		else
		{
			if (analysisArray[2] == 0 && analysisArray[0] == 0)
			{
				resultAnalysis = 3;// убывающая
			}
			else
			{
				if (analysisArray[1] ==0)
				{
					resultAnalysis = 4;// неубывающая
				}
				else
				{
					if (analysisArray[0] ==0)
					{
						resultAnalysis = 5;// невозрастающая
					}
					else
					{
						resultAnalysis = 6;// неупорядоченная
					}
				}
			}

		}
	}

	return resultAnalysis;
}

void generateRandomArray(int array[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 10;
	}
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}

void displayResault(short resultAnalysis)
{

	switch (resultAnalysis)
	{
	case 1:
		cout << " Array is a monotonus sequence" << endl;
		break;
	case 2:
		cout << " Array is a increasing sequence" << endl;
		break;
	case 3:
		cout << " Array  is a decreasing  sequence" << endl;
		break;
	case 4:
		cout << " Array is a not decreasing sequence" << endl;
		break;
	case 5:
		cout << " Array is a not increasing sequence" << endl;
		break;
	default:
		cout << " Array is a disordered sequence" << endl;
		break;
	}
}
