#include <iostream>
#include "Array.h"
#include "WorkWithArrays.h"

using namespace std;

void foo(const Array&);
int toGroser(int, int);
int toLower(int, int);
bool isEven(int);
bool isPrimeNumber(int);
Array test();

int main()
{
	Array a(6);
	Array again(a);

	a.randomFilling(50);
	a.display();
	cout << endl;
	a.shift(3, 1);
	a.display();

	/*int n = 0;
	int* p = a.selection(n, isEven);

	myArrays::displayArray(p,n);*/
}

Array test()
{
	int len = 3;
	Array test(len);
	return test;
}

int toGroser(int lho, int rho)
{
	return lho - rho;
}

int toLower(int lho, int rho)
{
	return rho - lho;
}

bool isEven(int a)
{
	return !(a % 2);
}

bool isPrimeNumber(int a)
{
	bool check = true;

	a = abs(a);

	if (a == 1 || a == 0)
	{
		return false;
	}

	for (int k = 2; k < a; k++)
	{
		if (a % k == 0)
		{
			return false;
		}
	}
	return check;
}

void foo(const Array& array)
{
	array.display();
}
