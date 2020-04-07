#define _CRT_SECURE_NO_WARNINGS
#include "Array.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"

using namespace std;
using namespace myArrays;



void createPositivEvenArray(Array&, Array&);
void sortByNumberOfCharInHex(Array&, Comparer);
void createKeysSymbolsInHex(Array&, Array&);
void createKeysIndRepits(Array&, Array&);
void catArray(Array&, Array&);
void deleteCorresp(Array&, Filter);
void deleteRepits(Array&);
void copyArrayAfter(Array&, Array&, int);
void copyArrayTo(Array&, Array&, int);
void findCorrespNumbers(Array&, Array&, Filter);
void quickSort(Array&, Array&, Comparer);
void mergeSort(Array&, Array&, Comparer);
int findFirstCorrespNumber(Array&, Filter);
bool isPositive(int);
bool isEven(int);
bool isPositivEven(int);
bool isNegativ(int);
bool isThereLetter(int);
int increase(int, int);
int decrease(int, int);
void fillingMethod(Array&);
void outMethod(Array&);
void readBinFile(const char*, Array&);
void readTxtFile(const char*, Array&);
void writeBinFile(const char*, Array&);
void stringToArray(char*, Array&);



int main()
{
	int n = 10, maxRandom = 10;
	Array source(n), buffer(n), newArray(n);
	ofstream fout;
	char path[] = "test.txt";
	int example[10] = { 12,43,29,171,2731,424,699387,22,-1,4 };

	for (int i = 0; i < n; i++)
	{
		buffer[i] = example[i];
	}

	buffer.writeBinFile(path);

	fillingMethod(source);
	source.display();
	createPositivEvenArray(source, newArray);
	sortByNumberOfCharInHex(source, decrease);
	source.deleteRepits();
	outMethod(newArray);
}

void fillingMethod(Array& source)
{
	char* path = new char[100];
	int button = 0, max = 10;
	cout << " Enter 1 to fill out from the keyboard." << endl;
	cout << " Enter 2 for automatic filling." << endl;
	cout << " Enter 3 to fill out from a file." << endl;

	cin >> button;
	system("cls");

	switch (button)
	{
	case 1:
		for (int i = 0; i < source.getLength(); i++)
		{
			cout << " Enter " << i + 1 << " element" << endl;
			cin >> source[i];
			system("cls");
		}
		break;
	case 2:
		cout << " Enter max element random fill." << endl;
		cin >> max;
		system("cls");

		source.randomFilling(max);
		break;
	case 3:
		cout << " Enter path to file or file name." << endl;
		cin >> path;
		system("cls");
		source.display();
		source.readBinFile(path);

		delete[]path;
		break;
	default:
		cout << " Not valid data." << endl;
		break;
	}
}

void outMethod(Array& result)
{
	char* path = new char[100];
	int button = 0;

	system("cls");

	cout << " Enter 1 to display result." << endl;
	cout << " Enter 2 to send result in file." << endl;

	cin >> button;
	system("cls");

	switch (button)
	{
	case 1:
		result.display();
		cout << endl;
		break;
	case 2:
		cout << " Enter path to file or file name." << endl;
		cin >> path;
		system("cls");

		result.writeBinFile(path);

		delete[]path;
		break;
	default:
		cout << " Not valid data." << endl;
		break;
	}
}

void createPositivEvenArray(Array& source, Array& newArray)
{
	int index = findFirstCorrespNumber(source, isNegativ);

	Array buffer1(1), buffer2(1);

	copyArrayTo(buffer1, source, index);
	buffer1.selection(newArray, isEven);
	buffer1.screening(isEven);
	copyArrayAfter(buffer2, source, index);
	catArray(buffer1, buffer2);

	source = buffer1;
}

void sortByNumberOfCharInHex(Array& source, Comparer comparator)
{
	Array keySymbolsInHex(source.getLength());

	createKeysSymbolsInHex(keySymbolsInHex, source);

	if (source.getLength() % 2)
	{
		quickSort(source, keySymbolsInHex, comparator);
	}
	else
	{
		source.mergeSort(keySymbolsInHex, comparator);
	}
}

void createKeysSymbolsInHex(Array& keys, Array& source)
{
	Array indices(1);
	Array copySource = source;
	source.search(indices, isThereLetter);
	int count, currentIndex;

	for (int i = 0; i < indices.getLength(); ++i)
	{
		count = 0;
		currentIndex = indices[i];

		while (copySource[currentIndex])
		{
			abs(copySource[currentIndex]);

			if ((copySource[i] % 16) < 10)
			{
				copySource[i] /= 16;
				continue;
			}

			copySource[i] /= 16;
			++count;
		}

		keys[currentIndex] = count;
	}
}

void catArray(Array& destination, Array& source)
{
	int destLength = destination.getLength(), sourceLength = source.getLength(), i = 0;
	Array buffer(destLength + sourceLength);

	for (; i < destLength; ++i)
	{
		buffer[i] = destination[i];
	}

	for (int j = 0; j < sourceLength; ++j, ++i)
	{
		buffer[i] = source[j];
	}

	destination = buffer;

	system("cls");
}

void copyArrayAfter(Array& destination, Array& source, int index)
{
	int sourceLength = source.getLength(), destLength = sourceLength - index;

	if (index > sourceLength)
	{
		throw std::invalid_argument(" Index can't be more than source length !");
	}

	if (index < 0)
	{
		throw std::invalid_argument(" Index can't be less zero source length !");
	}

	Array buffer(destLength);

	for (int i = 0; i < destLength; ++index, ++i)
	{
		buffer[i] = source[index];
	}

	destination = buffer;

	system("cls");
}

void copyArrayTo(Array& destination, Array& source, int index)
{
	int sourceLength = source.getLength(), destLength = index;

	if (index > sourceLength)
	{
		throw std::invalid_argument(" Index can't be more than source length !");
	}

	if (index < 0)
	{
		throw std::invalid_argument(" Index can't be less than zero length !");
	}

	Array buffer(destLength);

	for (int i = 0; i < destLength; ++i)
	{
		buffer[i] = source[i];
	}

	destination = buffer;

	system("cls");
}

void findCorrespNumbers(Array& destination, Array& source, Filter rule)
{
	int sourceLength = source.getLength(), destLength = 0;
	Array buffer(sourceLength);

	for (int i = 0; i < sourceLength; ++i)
	{
		if (rule(source[i]))
		{
			buffer[destLength] = source[i];
			++destLength;
		}
	}

	Array buffer2(destLength);

	for (int i = 0; i < destLength; ++i)
	{
		buffer2[i] = buffer[i];
	}

	destination = buffer2;

	system("cls");
}

int findFirstCorrespNumber(Array& source, Filter rule)
{
	for (int i = 0; i < source.getLength(); ++i)
	{
		if (rule(source[i]))
		{
			return i;
		}
	}

	cout << " No numbers matching the rule" << endl;

	return -1;
}

void quickSort(Array& source, Array& key, Comparer comparator)
{
	if (source.getLength() != key.getLength())
	{
		throw std::invalid_argument(" Keys do not match array!");
	}

	int first = 0, last = source.getLength() - 1;

	source.quickSort(key, first, last, comparator);
}

bool isPositive(int number)
{
	return number > 0;
}

bool isEven(int number)
{
	return !(number % 2);
}

bool isPositivEven(int number)
{
	return (isPositive(number) && isEven(number));
}

bool isNegativ(int number)
{
	return !isPositive(number);
}

bool isThereLetter(int number)
{
	while (number)
	{
		if ((number % 16) >= 10 || (number % 16) < 16)
		{
			return true;
		}

		number /= 16;
	}

	return false;
}
int increase(int lho, int rho)
{
	return  rho - lho;
}

int decrease(int lho, int rho)
{
	return  lho - rho;
}

