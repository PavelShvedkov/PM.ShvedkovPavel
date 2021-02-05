#include <iostream>
#include <ctime>
#include "LinkedList.h"

using namespace std;

bool decrease(int, int);
bool increase(int, int);
int* createAndFillRandomArray(int);
void deleteArray(int*);
void showArray(int*, int);

int main()
{
	srand(time(NULL));

	int size = 5;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin>>array[i];
	}

	LinkedList list(array, size);
	list.bubleSortList(decrease);
	cout << list;
	list.insertSortList(decrease);
	cout << list;
	list.selectSortList(decrease);
	cout << list;

	//int* array1=createAndFillRandomArray(size);
	//LinkedList a(array1, size);
	//cout << a << endl;
	//cout << "----------------------------------------" << endl;
	//a.bubleSortList(decrease);
	//cout << a << endl;
	//a.insertSortList(decrease);
	//cout << a << endl;
	//a.selectSortList(decrease);
	//cout << a << endl;

	//int* array2 = createAndFillRandomArray(2*size);
	//LinkedList b(array2, 2 * size);
	//cout << b << " not sorted" << endl;
	//cout << "----------------------------------------" << endl;	b.bubleSortList(increase);
	//cout << b << endl;
	//b.insertSortList(increase);
	//cout << b << endl;
	//b.selectSortList(increase);
	//cout << b << endl;

	//deleteArray(array1);
	//deleteArray(array2);
}

bool increase(int lho, int rho)
{
	return rho > lho;
}
bool decrease(int lho, int rho)
{
	return lho > rho;
}

int* createAndFillRandomArray(int length)
{
	int* array = new int[length];

	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10;
	}

	return array;
}
void deleteArray(int* array)
{
	delete[]array;
}
void showArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}