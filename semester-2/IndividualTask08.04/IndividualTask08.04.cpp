#include <iostream>
#include <fstream>
#include "WorkWithArrays.h"

using namespace std;
using namespace myArrays;

typedef int*(Scope)(int**,int&, int, int, int);

int* elementsInScopeV12(int**, int&, int, int, int);
int** scopingValuesMatrix(int**, int, Scope, Rule);
int vision(int, int, int, int);

int main()
{
	const char* path1 = "matrix(8x8).txt";
	const char* path2 = "matrix(4x4).txt";
	ifstream in(path2);
	ofstream out(path2, ios::app);
	int edge = 0;

	int** matrix = readSquareMatrix(edge, in);
	int** resultMatrix = scopingValuesMatrix(matrix, edge, elementsInScopeV12, increase);

	out << endl;
	
	writeMatrix(resultMatrix, edge, edge, out);

	deleteMemory(matrix, edge);
	deleteMemory(resultMatrix, edge);

	in.close();
	out.close();
}


int* elementsInScopeV12(int** matrix, int& sizeScope, int rows, int fixRow, int fixColumn)
{
	if (fixRow > rows || fixRow < 0)
	{
		throw std::out_of_range(" Going beyond matrix rows!!! ");
	}
	if (fixColumn > rows || fixColumn < 0)
	{
		throw std::out_of_range(" Going beyond matrix columns!!! ");
	}

	int* buffer = new int[rows * rows];
	sizeScope = 0;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= vision(rows, fixRow, fixColumn, i); j++)
		{
			buffer[sizeScope] = matrix[i][j];
			++sizeScope;
		}
	}

	int* elementsArray = resizeArray(buffer, sizeScope);

	deleteMemory(buffer);

	return elementsArray;
}

int** scopingValuesMatrix(int** sourceMatrix, int edge, Scope scope, Rule rule)
{
	int* resultArray = new int[edge * edge];
	int sizeScope = 0, k = 0;

	for (int i = 0; i < edge; ++i)
	{
		for (int j = 0; j < edge; ++j, ++k)
		{
			int* currentScope = scope(sourceMatrix, sizeScope, edge, i, j);
			int elementIndex = elementPosition(currentScope, sizeScope, rule);
			int currentElement = currentScope[elementIndex];
			resultArray[k] = currentElement;
			deleteMemory(currentScope);
		}
	}

	int** resultMatrix = createMatrix(resultArray, edge, edge);

	deleteMemory(resultArray);

	return resultMatrix;
}

int vision(int rows, int fixRow, int fixColumn, int currentRow)
{
	int maxColumn = 0;

	if (currentRow > fixRow)
	{
		maxColumn = fixColumn - currentRow + fixRow;
	}
	else
	{
		maxColumn = fixColumn - fixRow + currentRow;
	}

	return maxColumn;
}
