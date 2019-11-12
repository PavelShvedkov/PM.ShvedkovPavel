#include <iostream>
#include <ctime>

using namespace std;

void sequenceType(int*, int[], int);
short sequenceAnalisys(int[]);
void generateRandomArray(int* array, int n);
void initArray(int*, int);
int  initSizeArray();
void workWithConsole();
void testCase(int, int*, int*, int);
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
	int const n = 5;
	int testNr = 1;

	int tArray1[n] = { 1, 2, 3, 4, 5 };
	int tExpArray1[3] = { 4, 0, 0 };
	testCase(testNr++, tArray1, tExpArray1, n);

	int tArray2[n] = { 5, 4, 3, 2, 1 };
	int tExpArray2[3] = { 0, 4, 0 };
	testCase(testNr++, tArray2, tExpArray2, n);

	int tArray3[n] = { 1, 2, 2, 3, 4 };
	int tExpArray3[3] = { 3, 0, 1 };
	testCase(testNr++, tArray3, tExpArray3, n);

	int tArray4[n] = { 5, 4, 4, 3, 1 };
	int tExpArray4[3] = { 0, 3, 1 };
	testCase(testNr++, tArray4, tExpArray4, n);

	int tArray5[n] = { 1, 1, 1, 1, 1 };
	int tExpArray5[3] = { 0, 0, 4 };
	testCase(testNr++, tArray5, tExpArray5, n);

	int tArray6[n] = { 1, 2, 2, 4, 1 };
	int tExpArray6[3] = { 2, 1, 1 };
	testCase(testNr++, tArray6, tExpArray6, n);

}

void testCase(int testNr, int* array, int* expArray, int n)
{
	int analysisArray[3] = { 0 };

	for (int* pointer = array, i = 1; i < n; i++, pointer++)
	{
		if (*(pointer) < *(pointer + 1))
		{
			analysisArray[0]++;//ïåðâûé ìåíüøå âòîðîãî
		}
		else
		{
			if (*(pointer) > * (1 + pointer))
			{
				analysisArray[1]++;//ïåðâûé áîëüøå âòîðîãî
			}
			else
			{
				analysisArray[2]++;//ïåðâûé ðàâåí âòîðîìó
			}
		}
	}

	bool answer = 1;

	for (int* pointerAnalysis = analysisArray; pointerAnalysis < analysisArray + 3; pointerAnalysis++, expArray++)
	{
		if (*pointerAnalysis != *expArray)
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
	int n = initSizeArray();
	int* array = new int[n];

	initArray(array, n);

	int analysisArray[3] = { 0 };

	sequenceType(array, analysisArray, n);

	displayResault(sequenceAnalisys(analysisArray));
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

void sequenceType(int* array, int analysisArray[], int n)
{
	for (int* pointer = array, i = 1; i < n; i++, pointer++)
	{
		if (*(pointer) < *(pointer + 1))
		{
			analysisArray[0]++;//ïåðâûé ìåíüøå âòîðîãî
		}
		else
		{
			if (*(pointer) > * (1 + pointer))
			{
				analysisArray[1]++;//ïåðâûé áîëüøå âòîðîãî
			}
			else
			{
				analysisArray[2]++;//ïåðâûé ðàâåí âòîðîìó
			}
		}
	}
	cout << sequenceAnalisys(analysisArray);
}

short sequenceAnalisys(int analysisArray[])
{
	short resultAnalysis;

	if (analysisArray[0] == 0 && analysisArray[1] == 0)
	{
		resultAnalysis = 1;// ìîíîòîííàÿ
	}
	else
	{
		if (analysisArray[2] == 0 && analysisArray[1] == 0)
		{
			resultAnalysis = 2;// âîçðàñòàþùàÿ
		}
		else
		{
			if (analysisArray[2] == 0 && analysisArray[0] == 0)
			{
				resultAnalysis = 3;// óáûâàþùàÿ
			}
			else
			{
				if (analysisArray[1] == 0)
				{
					resultAnalysis = 4;// íåóáûâàþùàÿ
				}
				else
				{
					if (analysisArray[0] == 0)
					{
						resultAnalysis = 5;// íåâîçðàñòàþùàÿ
					}
					else
					{
						resultAnalysis = 6;// íåóïîðÿäî÷åííàÿ
					}
				}
			}

		}
	}

	return resultAnalysis;
}

void generateRandomArray(int* array, int n)
{
	srand(time(0));
	for (int* pointer = array; pointer < array + n; pointer++)
	{
		*pointer = rand() % 10;
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