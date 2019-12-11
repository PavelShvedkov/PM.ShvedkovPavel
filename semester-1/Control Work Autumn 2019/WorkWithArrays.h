#pragma once
#include <iostream>
#include <ctime>

using namespace std;

void bubleSort(int*, int);
void selectionSort(int*, int);
void insertSort(int*, int);
void swap(int&, int&);
void randomArray(int*, int, int);
int* generateIncreasingSortedArray(int, int, int);
int* generateDecreasingSortedArray(int, int, int);
void shuffleArray(int*, int);
void displayArray(int*, int);
int* allocateMemory(int);
void deleteMemory(int*);
bool areEqual(int*, int, int*, int);
void isDataValid(int*, int);
void initArray(int[], int);
void testCase(int*, int, int*, int);
void testCaseV2(int, int, int);
void runTests();

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
	isDataValid(sourceArray, n);

	for (int* unsortedEl = sourceArray, *currentMin = sourceArray, i = 0; unsortedEl < sourceArray + n; i++, unsortedEl++, currentMin = unsortedEl)
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

void isDataValid(int* array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}
}

bool areEqual(int* lhs, int n, int* rhs, int m)
{
	isDataValid(lhs, n);
	isDataValid(rhs, m);

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
	isDataValid(array, n);


	for (int* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}

	cout << endl;

}

void randomArray(int* array, int n, int max)
{
	isDataValid(array, n);

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
	isDataValid(sourceArray, n);

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

void testCaseV2(int size, int startValue, int step)
{
	int* array = generateIncreasingSortedArray(size, startValue, step);

	shuffleArray(array, size);
	//Operation with array(sorting)

	if (areEqual(generateIncreasingSortedArray(size, startValue, step), size, array, size))
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}
}

void testCase(int* expected, int n, int* actual, int m)
{
	//Sort Function

	if (areEqual(expected, n, actual, m))
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}


}

void runTests()
{
	int testNumber = 1;

	int n = 5;

	int* expected = new int[n] { 1, 2, 3, 4, 5 };
	int* actual = new int[n] {5, 4, 3, 2, 1};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	actual = new int[n] {5, 4, 3, 2, 1, 8, 7, 10, 6, 9};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	actual = new int[n] {3, 3, 1, 1, 2, 2, 5, 5, 4, 4};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);


}

void runTestsV2()
{
	testCaseV2(20, 0, 5);
	testCaseV2(5, -3, 2);
	testCaseV2(50, 0, 1);
	testCaseV2(100, -50, 1);
	testCaseV2(3, -10, 2);

}

int* generateDecreasingSortedArray(int size, int startValue, int step)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	int* array = new int[size];

	for (int* p = array, i = startValue; p < array + size; p++)
	{
		*p = startValue;
		startValue -= step;
	}

	return array;
}

int* generateIncreasingSortedArray(int size, int startValue, int step)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	int* array = new int[size];

	for (int* p = array, i = startValue; p < array + size; p++)
	{
		*p = startValue;
		startValue += step;
	}

	return array;
}

void shuffleArray(int* array, int size)
{
	isDataValid(array, size);

	int shuffles = size;

	for (int index1 = 0, index2 = 0, i = 0; i <= shuffles; i++)
	{
		index1 = ((rand() / rand()) % size + ((rand() * 22) / 9)) % size;
		index2 = ((rand() / rand()) % size + ((rand() * 22) / 9)) % size;
		swap(array[index1], array[index2]);
	}

}
