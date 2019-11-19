#pragma once
#include <iostream>
#include <ctime>

using namespace std;

void bubleSort(int*, int);
void selectionSort(int*, int);
void insertSort(int*, int);
void swap(int&, int&);
void randomArray(int*, int, int);
void displayArray(int*, int);
int* allocateMemory(int);
void deleteMemory(int*);
bool areEqual(int*, int, int*, int);
bool isDataValid(int*, int);
void initArray(int[], int);

void insertSort(int* sourceArray, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; sourceArray[j] >= sourceArray[0]; j--)
		{
			if (sourceArray[j] > sourceArray[j + 1])
			{
				swap(sourceArray[j], sourceArray[j + 1]);
				continue;
			}
			break;
		}
	}
}

void selectionSort(int* sourceArray, int n)
{
	if (!isDataValid(sourceArray, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	for (int *unsortedEl = sourceArray, *currentMin = sourceArray, i = 0; unsortedEl < sourceArray + n; i++, unsortedEl++, currentMin = unsortedEl)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (*currentMin == *(unsortedEl + j))
			{
				continue;
			}
			if (*currentMin > * (unsortedEl + j))
			{
				swap(*currentMin, *(unsortedEl + j));
				continue;
			}
			swap(*currentMin, *unsortedEl);
		}

	}
}

bool isDataValid(int* array, int n)
{
	if (array == nullptr)
	{
		return false;
	}

	if (n <= 0)
	{
		return false;
	}
}

bool areEqual(int* lhs, int n, int* rhs, int m)
{
	if (!isDataValid(lhs, n) || !isDataValid(rhs, m))
	{
		cout << " Invalid data!!!" << endl;
		return false;
	}

	if (n != m)
	{
		return false;
	}

	for (int* p = lhs, *q = rhs; p < lhs + n; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}

	return true;
}

void deleteMemory(int* sourceArray)
{
	delete[]sourceArray;
}

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		cout << " N <= 0. Error!!!" << endl;
		return nullptr;
	}

	int* a = new int[n];

	return  a;
}

void displayArray(int* array, int n)
{
	if (!isDataValid(array, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	for (int* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}

	cout << endl;

}

void randomArray(int* array, int n, int max)
{
	if (!isDataValid(array, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max - max / 2;//<- 0..max
	}
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void bubleSort(int* sourceArray, int n)
{
	if (!isDataValid(sourceArray, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (sourceArray[j] < sourceArray[j - 1])
			{
				swap(sourceArray[j], sourceArray[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}

void initArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << (i + 1) << "]= ";
		cin >> array[i];
	}
}
