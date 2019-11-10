#include <iostream>
#include <ctime>

using namespace std;

void sequenceType(int*, int[], int);
short sequenceAnalisys(int[]);
void generateRandomArray(int* array, int n);
void initArray(int*, int);
int  initSizeArray();
void workWithConsole();
void testCase(int, int, int, int, int, int, int, int, int);
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

	int tArray1[5] = { 1, 2, 3, 4, 5 };
	int tArray2[5] = { 5, 4, 3, 2, 1 };
	int tArray3[5] = { 1, 2, 2, 3, 4 };
	int tArray4[5] = { 5, 4, 4, 3, 1 };
	int tArray5[5] = { 1, 1, 1, 1, 1 };
	int tArray6[5] = { 1, 2, 2, 4, 1 };

	testCase(testNr++, 1, 2, 3, 4, 5, 4, 0, 0);
	testCase(testNr++, 5, 4, 3, 2, 1, 0, 4, 0);
	testCase(testNr++, 1, 2, 2, 3, 4, 3, 0, 1);
	testCase(testNr++, 5, 4, 4, 3, 1, 0, 3, 1);
	testCase(testNr++, 1, 1, 1, 1, 1, 0, 0, 4);
	testCase(testNr++, 1, 2, 2, 4, 1, 2, 1, 1);

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

	sequenceType(testArray, analysisArray, n);

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
	int* array=new int[n];

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
	for (int* pointer = array, i=1;i<n;i++, pointer++)
	{
		if (*(pointer) < *(pointer+1))
		{
			analysisArray[0]++;//ïåðâûé ìåíüøå âòîðîãî
		}
		else
		{
			if (*(pointer) > *(1+pointer))
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
	for (int* pointer = array; pointer < array+ n; pointer++)
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