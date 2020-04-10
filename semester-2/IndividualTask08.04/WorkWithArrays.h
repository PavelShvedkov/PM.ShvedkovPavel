#pragma once
#include <ctime>
#include <iostream>

using namespace std;

typedef int(Rule)(int, int);

namespace myArrays
{
	void bubleSort(int*, int);
	void selectionSort(int*, int);
	void insertSort(int*, int);
	void swap(int&, int&);
	void swap(int*&, int*&);
	void randomArray(int*, int, int);
	int** createRandomMatrix(int, int);
	int** createMatrix(int*, int, int);
	int** readSquareMatrix(int& , istream& );
	int* generateIncreasingSortedArray(int, int, int);
	int* generateDecreasingSortedArray(int, int, int);
	int* createKeys(int**, int, int, Rule);
	int* resizeArray(int*, int);
	void shuffleArray(int*, int);
	void displayArray(int*, int);
	void displayArray(double*, int);
	int* allocateMemory(int);
	void deleteMemory(int*);
	void deleteMemory(int**, int);
	bool areEqual(int*, int, int*, int);
	void writeMatrix(int** , int , int , ostream& );
	void isDataValid(int*, int);
	void isDataValid(double*, int);
	void initArray(int[], int);
	void testCase(int*, int, int*, int);
	void testCaseV2(int, int, int);
	void runTests();
	void elementSortMatrix(int**, int, int, Rule);
	int elementPosition(int*, int, Rule);
	void bubleSortMaxElement(int**, int, int*);
	void displayMatrix(int**, int, int);
	int increase(int, int);
	int decrease(int, int);

	int** readSquareMatrix(int& edge, istream& in)
	{
		int n = 100, i = 0;
		int* buffer = new int[n];

		while (!in.eof())
		{
			in >> buffer[i];
			++i;
		}

		int* resizeBuffer = resizeArray(buffer, i);
		int columns = sqrt(i), rows = sqrt(i);
		edge = columns;

		return createMatrix(resizeBuffer, columns, rows);
	}

	void writeMatrix(int** source, int rows, int columns, ostream& out)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				out << source[i][j] << ' ';
			}
			out << '\n';
		}
	}


	int* resizeArray(int* source, int newLength)
	{
		int* newArray = new int[newLength];

		for (int i = 0; i < newLength; i++)
		{
			newArray[i] = source[i];
		}

		return newArray;
	}

	int increase(int lho, int rho)
	{
		return  rho - lho;
	}

	int decrease(int lho, int rho)
	{
		return  lho - rho;
	}

	void bubleSortMaxElement(int** matrix, int rows, int* keys)
	{
		bool isSorted = false;
		int i = 0;

		while (!isSorted)
		{
			isSorted = true;
			for (int j = rows - 1; j > i; j--)
			{
				if (keys[j] < keys[j - 1])
				{
					swap(keys[j], keys[j - 1]);
					swap(matrix[j], matrix[j - 1]);
					isSorted = false;
				}
			}
			i++;
		}
	}

	int* createKeys(int** matrix, int rows, int colmns, Rule comparator)
	{
		int* keys = new int[rows];

		for (int i = 0; i < rows; i++)
		{
			keys[i] = matrix[i][elementPosition(matrix[i], colmns, comparator)];
		}

		return keys;
	}

	int elementPosition(int* array, int size, Rule comparator)
	{
		int max = 0;

		for (int i = 0; i < size; i++)
		{
			if (comparator(array[i], array[max]) > 0)
			{
				max = i;
			}
		}

		return max;
	}

	void displayMatrix(int** matrix, int rows, int columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout.width(5);
				cout << matrix[i][j];
			}

			cout << endl;
		}
	}

	int** createMatrix(int* source, int rows, int columns)
	{
		int** matrix = new int* [rows];

		for (int i = 0, k = 0; i < rows; i++)
		{
			matrix[i] = new int[columns];

			for (int j = 0; j < columns; j++, k++)
			{
				matrix[i][j] = source[k];
			}
		}

		return matrix;
	}

	int** createRandomMatrix(int rows, int columns)
	{
		srand(time(0));

		int** matrix = new int* [rows];

		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[columns];

			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = rand() % 100;
			}
		}

		return matrix;
	}

	void elementSortMatrix(int** matrix, int rows, int columns, Rule comparator)
	{
		int index1 = 0, index2 = 0;
		for (int i = 0; i < rows - 1; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				index1 = elementPosition(matrix[j], columns, comparator);
				index2 = elementPosition(matrix[j + 1], columns, comparator);
				if (matrix[j][index1] < matrix[j + 1][index2])
				{
					swap(matrix[j], matrix[j + 1]);
					continue;
				}

				break;
			}
		}
	}

	void deleteMemory(int** matrix, int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
	}

	void insertSort(int* sourceArray, int n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0 && sourceArray[j - 1] > sourceArray[j]; j--)
			{
				swap(sourceArray[j - 1], sourceArray[j]);
			}
		}


		//for (int i = 0; i < n - 1; i++)
		//{
		//	for (int j = i;j>0 /*sourceArray[j] >= sourceArray[0]*/; j--)
		//	{
		//		if (sourceArray[j] > sourceArray[j + 1])
		//		{
		//			swap(sourceArray[j], sourceArray[j + 1]);
		//			continue;
		//		}
		//		break;
		//	}
		//}
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

	void isDataValid(double* array, int n)
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

	void displayArray(double* array, int n)
	{
		isDataValid(array, n);


		for (double* p = array; p < array + n; p++)
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

	void swap(int*& a, int*& b)
	{
		int* t = a;
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
}