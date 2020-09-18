#include <iostream>
#include "ArrayOfStrings.h"

using namespace std;

bool decrease(string, string);
bool increase(string, string);
ArrayOfStrings mergeArraysOfStrings(const ArrayOfStrings*, int,Comparer);

int main()
{
	int length1 = 3;
	int length2 = 4;
	int length3 = 2;
	string* array = new string[length1]{ "great","warior","wars" };
	string* array2 = new string[length2]{ "not","make","one", "great" };
	ArrayOfStrings test(array, length1);
	ArrayOfStrings test2(array2, length2);
	ArrayOfStrings* arrayOfObjects = new ArrayOfStrings[length3]{ test,test2 };

	cout <<mergeArraysOfStrings(arrayOfObjects, length3,increase);
}

ArrayOfStrings mergeArraysOfStrings(const ArrayOfStrings* lho,int length,Comparer comparator)
{
	ArrayOfStrings buffer(lho[0]);

	for (int i = 1; i < length; i++)
	{
		buffer =buffer+lho[i];
	}

	buffer.lexicalBubleSort(comparator);

	return buffer;
}
 
bool increase(string lho, string rho)
{
	return rho > lho;
}

bool decrease(string lho, string rho)
{
	return lho > rho;
}
