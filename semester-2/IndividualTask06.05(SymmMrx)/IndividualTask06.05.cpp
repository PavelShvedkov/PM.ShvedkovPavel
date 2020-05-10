//Option 10
#include <iostream>
#include <fstream>

using namespace std;

typedef void(*FillingRule)(int**&, int, int, int);
typedef bool(*Comparator)(int**, int, int);

void work(const char*, const char*, const char*, int, int, Comparator);
void writeMrxInBin(const char*, int, int, int, int, FillingRule);
void writeMrxInBin(const char*, int**, int, int);
void readFromBin(const char*, int, int);
int* createLinearMrx(int, int);
int** createMrx(int, int);
void fillMrx(int**&, int, int, int, FillingRule);
void fillMrx(int*&, int, int, int, FillingRule);
void randomFill(int**&, int, int, int);
void symmetricalFill(int**&, int, int, int);
bool isSymmetrical(int**, int, int);
void displayMrx(int**, int, int);
void displayMrx(int*, int, int);
int** convert(int* array, int, int);
int* convert(int** array, int, int);
bool isValidSize(int, int);
void deleteMrx(int**, int);
void deleteMrx(int*);

int main()
{
	int rows = 6, columns = 6, max = 100;
	int** matrix = createMrx(rows, columns);
	int* array = createLinearMrx(rows, columns);

	writeMrxInBin("source.txt", rows, columns, 2, max, randomFill);
	writeMrxInBin("source.txt", rows, columns, 1, max, symmetricalFill);
	writeMrxInBin("source.txt", rows, columns, 1, max, randomFill);

	work("source.txt", "Relevant.txt", "Other.txt", columns, rows, isSymmetrical);

	cout << " Relevant:" << endl;
	readFromBin("Relevant.txt", rows, columns);
	cout << " Other:" << endl;
	readFromBin("Other.txt", rows, columns);
}

void work(const char* source, const char* destForRelevant, const char* destForNonRelevant, int rows, int columns, Comparator comparator)
{
	ofstream outForRelevant(destForRelevant, ios::binary);
	ofstream outForNonRelevant(destForNonRelevant, ios::binary);
	ifstream in(source, ios::binary);

	if (!isValidSize(rows, columns))
	{
		return;
	}

	int buffSize = rows * columns * sizeof(int);
	int* array = createLinearMrx(rows, columns);
	int** matrix = nullptr;

	while (in.read((char*)array, buffSize))
	{
		matrix = convert(array, rows, columns);
		if (comparator(matrix, rows, columns))
		{
			array = convert(matrix, rows, columns);
			outForRelevant.write((char*)array, buffSize);
		}
		else
		{
			array = convert(matrix, rows, columns);
			outForNonRelevant.write((char*)array, buffSize);
		}
		deleteMrx(matrix, rows);
	}

	outForRelevant.close();
	outForNonRelevant.close();
	in.close();
}

void writeMrxInBin(const char* path, int rows, int columns, int quantity, int max, FillingRule rule)
{
	ofstream out(path, ios::binary | ios::app);

	if (!isValidSize(rows, columns))
	{
		return;
	}
	if (quantity < 0)
	{
		cout << " Cannot fill a file with a negative number of matrices" << endl;
		return;
	}

	int* matrix = createLinearMrx(rows, columns);
	int buffSize = rows * columns * sizeof(int);

	for (int i = 0; i < quantity; i++)
	{
		fillMrx(matrix, rows, columns, max, rule);
		out.write((char*)matrix, buffSize);
	}

	deleteMrx(matrix);
	out.close();
}
void writeMrxInBin(const char* path, int** matrix, int rows, int columns)
{
	ofstream out(path, ios::binary | ios::app);

	if (!isValidSize(rows, columns))
	{
		return;
	}

	int* array = convert(matrix, rows, columns);
	int buffSize = rows * columns * sizeof(int);

	out.write((char*)matrix, buffSize);

	deleteMrx(array);
	out.close();
}

void readFromBin(const char* path, int rows, int columns)
{
	ifstream in(path, ios::binary);

	int* matrix = createLinearMrx(rows, columns);
	int buffSize = rows * columns * sizeof(int);

	while (in.read((char*)matrix, buffSize))
	{
		displayMrx(matrix, rows, columns);
		cout << endl;
	}

	deleteMrx(matrix);
	in.close();
}

int* createLinearMrx(int rows, int columns)
{
	int* matrix = new int[columns * rows];

	return matrix;
}
int** createMrx(int rows, int columns)
{
	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}

	return matrix;
}

void fillMrx(int**& matrix, int rows, int columns, int max, FillingRule rule)
{
	rule(matrix, rows, columns, max);
}
void fillMrx(int*& matrix, int rows, int columns, int max, FillingRule rule)
{
	int** buffer = convert(matrix, rows, columns);

	rule(buffer, rows, columns, max);

	matrix = convert(buffer, rows, columns);

	deleteMrx(buffer, rows);
}

void randomFill(int**& matrix, int rows, int columns, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = rand() % max + 1;
		}
	}
}
void symmetricalFill(int**& matrix, int rows, int columns, int max)
{
	if (rows != columns)
	{
		cout << " Can't symmetricaly fill not square matrix" << endl;
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < columns; j++)
		{
			int value = rand() % max + 1;
			matrix[i][j] = value;
			matrix[j][i] = value;
		}
	}
}

bool isSymmetrical(int** matrix, int rows, int columns)
{
	if (rows != columns)
	{
		return false;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < columns; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

void displayMrx(int** matrix, int rows, int columns)
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
void displayMrx(int* matrix, int rows, int columns)
{
	for (int* p = matrix, i = 0; p < matrix + rows * columns; ++i, ++p)
	{
		if (!(i % columns))
		{
			cout << endl;
		}

		cout.width(5);
		cout << *p << '\t';
	}
}

int** convert(int* array, int rows, int columns)
{
	int** matrix = createMrx(rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = array[i * columns + j];
		}
	}

	return matrix;
}
int* convert(int** matrix, int rows, int columns)
{
	int* array = createLinearMrx(rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i * columns + j] = matrix[i][j];
		}
	}

	return array;
}

bool isValidSize(int rows, int columns)
{
	if (rows <= 0)
	{
		cout << " The number of lines must be greater than zero" << endl;
		return false;
	}
	if (columns <= 0)
	{
		cout << " Number of columns must be greater than zero" << endl;
		return false;
	}
	return true;
}

void deleteMrx(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}

	delete[]matrix;
}
void deleteMrx(int* matrix)
{
	delete[]matrix;
}

