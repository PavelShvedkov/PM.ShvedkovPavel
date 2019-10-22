#include <iostream>

using namespace std;

int enterNumber();
void displayResult(int, short);
void count(int, short&, short&, short&, short&, short&);
void menu();
void workWithConsole();
void runTests();
void countTests(int, int, short, short, short, short, short, short);
short numberAnalisys(short, short, short, short, short);
void menuText();



int main()
{
	menu();

	return 0;
}


int enterNumber()
{
	int number;

	cout << " Enter number: ";
	cin >> number;

	return number;
}

void count(int number, short& requality, short& rmore, short& rsmaller, short& rmorePerUnit, short& rsmallerPerUnit)
{
	int count = 0;

	number = abs(number);

	for (; number >= 10; number /= 10)
	{
		if ((number % 10) < ((number / 10) % 10))
		{
			((number % 10) == (((number / 10) % 10) - 1)) ? rsmallerPerUnit++ : rsmaller++;
		}
		else
		{
			if ((number % 10) > ((number / 10) % 10))
			{
				((number % 10) == (((number / 10) % 10) + 1)) ? rmorePerUnit++ : rmore++;
			}
			else
			{
				requality++;
			}
		}

	}
}

void displayResult(int number, short resultAnalysis)
{
	switch (resultAnalysis)
	{
	case 1:
		cout << " A number ' " << number << " ' is a monotonus sequence" << endl;
		break;
	case 2:
		cout << " A number ' " << number << " ' is a strictly decreasing sequence" << endl;
		break;
	case 3:
		cout << " A number ' " << number << " ' is a strictly increasing sequence" << endl;
		break;
	case 4:
		cout << " A number ' " << number << " ' is a decreasing sequence" << endl;
		break;
	case 5:
		cout << " A number ' " << number << " ' is a increasing sequence" << endl;
		break;
	default:
		cout << " A number ' " << number << " ' is a disordered sequence" << endl;
		break;
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
	int number = enterNumber();

	short equality = 0, more = 0, smaller = 0, smallerPerUnit = 0, morePerUnit = 0;
	short& rsmallerPerUnit = smallerPerUnit;
	short& rmorePerUnit = morePerUnit;
	short& requality = equality;
	short& rmore = more;
	short& rsmaller = smaller;

	count(number, requality, rmore, rsmaller, rmorePerUnit, rsmallerPerUnit);

	short resultAnalysis = numberAnalisys(equality, more, smaller, morePerUnit, smallerPerUnit);

	displayResult(number, resultAnalysis);
}

void runTests()
{
	int testNumber = 1;

	countTests(testNumber++, -22222222, 7, 0, 0, 0, 0, 1);
	countTests(testNumber++, 44444444, 7, 0, 0, 0, 0, 1); // тест с "монотонным" исходом
	countTests(testNumber++, 00000000, 0, 0, 0, 0, 0, 1);

	countTests(testNumber++, -12345678, 0, 0, 0, 7, 0, 3);
	countTests(testNumber++, 23456, 0, 0, 0, 4, 0, 3);// тест со "строго возрастающим" исходом
	countTests(testNumber++, 123456789, 0, 0, 0, 8, 0, 3);

	countTests(testNumber++, 987654321, 0, 0, 0, 0, 8, 2);
	countTests(testNumber++, 876543, 0, 0, 0, 0, 5, 2); // тест со "строго убывающим" исходом
	countTests(testNumber++, 987654, 0, 0, 0, 0, 5, 2);

	countTests(testNumber++, 234458, 1, 1, 0, 3, 0, 5);
	countTests(testNumber++, 123578, 0, 2, 0, 3, 0, 5); // тест с "возрастающим" исходом
	countTests(testNumber++, -234458, 1, 1, 0, 3, 0, 5);

	countTests(testNumber++, 99766430, 2, 0, 3, 0, 2, 4);
	countTests(testNumber++, 76542, 0, 0, 1, 0, 3, 4);// тест с "убывающим" исходом
	countTests(testNumber++, -99766430, 2, 0, 3, 0, 2, 4);

	countTests(testNumber++, 346234, 0, 1, 1, 3, 0, 6);
	countTests(testNumber++, 123321, 1, 0, 0, 2, 2, 6);// тест с "неупорядоченным" исходом
	countTests(testNumber++, 1100110011, 5, 0, 0, 2, 2, 6);
}

void countTests(int testNumber, int number, short expEquality, short expMore, short expSmaller, short expMorePerUnit, short expSmallerPerUnit, short expAnalysis)
{
	short equality = 0, more = 0, smaller = 0, morePerUnit = 0, smallerPerUnit = 0;
	short& requality = equality;
	short& rmore = more;
	short& rsmaller = smaller;
	short& rmorePerUnit = morePerUnit;
	short& rsmallerPerUnit = smallerPerUnit;

	count(number, requality, rmore, rsmaller, rmorePerUnit, rsmallerPerUnit);

	short resultAnalysis = numberAnalisys(equality, more, smaller, morePerUnit, smallerPerUnit);

	if (equality == expEquality && more == expMore && smaller == expSmaller && morePerUnit == expMorePerUnit && smallerPerUnit == expSmallerPerUnit && resultAnalysis == expAnalysis)
	{
		cout << "Case #" << testNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << testNumber << " IS NOT CORRECT. :(" << endl;//добавить конкретизацию ошибки
	}
}

short numberAnalisys(short equality, short more, short smaller, short morePerUnit, short smallerPerUnit)
{
	short resultAnalysis;

	if (smaller == 0 && more == 0 && morePerUnit == 0 && smallerPerUnit == 0)
	{
		resultAnalysis = 1;// монотонная последовательность
	}
	else
	{
		if (equality == 0 && smaller == 0 && more == 0 && morePerUnit == 0)
		{
			resultAnalysis = 2;// строго убывающая
		}
		else
		{
			if (equality == 0 && smaller == 0 && more == 0 && smallerPerUnit == 0)
			{
				resultAnalysis = 3;// строго возрастающая;
			}
			else
			{
				if ((morePerUnit == 0&& more == 0) && (smaller != 0 || smallerPerUnit != 0))
				{
					resultAnalysis = 4;// убывающая
				}
				else
				{
					if ((smallerPerUnit == 0 && smaller == 0) && (more != 0 || morePerUnit != 0))
					{
						resultAnalysis = 5;// возрастающая
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

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}


