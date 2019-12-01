#include <iostream>
#include "WorkWithStrings.h"
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"

using namespace std;

void testCase(int, short, char*);
void runTestTrancfer();

int main()
{ 
	runTestTrancfer();
}

void runTestTrancfer()
{
	char* expAnswer = new char[255]{ '1','1','0','0','1','0','0',0 };
	testCase(100, 2, expAnswer);
	deleteMemory(expAnswer);

	expAnswer = new char[255]{'1','2',0  };
	testCase(10, 8, expAnswer);
	deleteMemory(expAnswer);

	expAnswer = new char[255]{ 'F','F','F',0 };
	testCase(4095, 16, expAnswer);
	deleteMemory(expAnswer);

	expAnswer = new char[255]{ 'E','A','C',0 };
	testCase(3312, 15, expAnswer);
	deleteMemory(expAnswer);

	expAnswer = new char[255]{ '4','4','4',0 };
	testCase(124, 5, expAnswer);
	deleteMemory(expAnswer);

}

void testCase(int number, short order, char* expAnswer)
{
	if (areEqual(trancferToP(number, order), expAnswer))
	{
		cout << " )))" << endl;
	}
	else
	{
		cout << " (((" << endl;
	}
}

