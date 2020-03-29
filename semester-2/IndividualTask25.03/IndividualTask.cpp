#include <fstream>
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
void deleteElement(Array&, int);
void deleteRepits(Array&);
void copyArrayAfter(Array&, Array&, int);
void copyArrayTo(Array&, Array&, int);
void findCorrespNumbers(Array&, Array&, Filter);
void quickSort(Array&, Array&, Comparer);
void quickSort(Array&, Array&, int, int, Comparer);
void mergeSort(Array&, Array&, Comparer);
void mergeSort(Array&, Array&, Comparer);
int findFirstCorrespNumber(Array&, Filter);
bool isPositive(int);
bool isEven(int);
bool isPositivEven(int);
bool isNegativ(int);
int increase(int, int);
int decrease(int, int);
void fillingMethod(Array&);
void outMethod(Array&);



int main()
{
	int n = 10, maxRandom = 10;
	Array source(n), newArray(n);;

	fillingMethod(source);

	createPositivEvenArray(source, newArray);
	sortByNumberOfCharInHex(source, decrease);
	deleteRepits(source);

	outMethod(newArray);
}

void fillingMethod(Array& source)
{
	string path = "";
	ifstream fin;
	Array source(1);
	int button = 0, max = 10;
	cout << " Enter 1 to fill out from the keyboard." << endl;
	cout << " Enter 2 for automatic filling." << endl;
	cout << " Enter 3 to fill out from a file." << endl;

	cin >> button;

	switch (button)
	{
	case 1:
		for (int i = 0; i < source.getLength(); i++)
		{
			cout << " Enter " << i + 1 << " element" << endl;
			cin >> source[i];
		}
		break;
	case 2:
		cout << " Enter max element random fill." << endl;
		cin >> max;
		source.randomFilling(max);
		break;
	case 3:
		cout << " Enter path to file or file name." << endl;
		cin >> path;

		fin.open(path, ifstream::in);

		if (!fin.is_open())
		{
			cout << "Cannot open file to read!" << endl;
			system("pause");
			exit(1);
		}

		fin.read((char*)&source, sizeof(Array));
		fin.close();
		break;
	default:
		cout << " Not valid data." << endl;
		break;
	}
}

void outMethod(Array& result)
{
	ofstream fout;
	string path;
	int button = 0;

	cout << " Enter 1 to display result." << endl;
	cout << " Enter 2 to send result in file." << endl;

	cin >> button;

	switch (button)
	{
	case 1:
		result.display();
		cout << endl;
		break;
	case 2:
		cout << " Enter path to file or file name." << endl;
		cin >> path;

		fout.open(path);

		if (!fout.is_open())
		{
			cout << "Cannot open file to read!" << endl;
			system("pause");
			exit(1);
		}

		fout.write((char*)&result, sizeof(Array));
		fout.close();
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
	findCorrespNumbers(newArray, buffer1, isEven);
	deleteCorresp(buffer1, isEven);
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
		mergeSort(source, keySymbolsInHex, comparator);
	}
}

void createKeysSymbolsInHex(Array& keys, Array& source)
{
	int count, length = source.getLength();
	Array copySource = source;
	Array buffer(length);

	for (int i = 0; i < length; ++i)
	{
		count = 0;

		while (copySource[i])
		{
			abs(copySource[i]);

			if ((copySource[i] % 16) < 10)
			{
				copySource[i] /= 16;
				continue;
			}

			copySource[i] /= 16;
			++count;
		}

		buffer[i] = count;
	}

	keys = buffer;
}

void deleteRepits(Array& source)
{
	for (int i = 0, k = 0; i < source.getLength(); ++i)
	{
		for (int j = i + 1; j < source.getLength(); ++j)
		{
			if (source[i] == source[j])
			{
				deleteElement(source, j);
			}
		}
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
}

void deleteCorresp(Array& source, Filter rule)
{
	int sourceLength = source.getLength(), newLength = 0;
	Array buffer(sourceLength);

	for (int i = 0, j = 0; i < sourceLength; ++i)
	{
		if (!rule(source[i]))
		{
			buffer[newLength] = source[i];
			++newLength;
		}
	}

	Array buffer2(newLength);

	for (int i = 0; i < newLength; i++)
	{
		buffer2[i] = buffer[i];
	}

	source = buffer2;
}

void deleteElement(Array& source, int index)
{
	int length = source.getLength();

	if (index >= length)
	{
		throw std::invalid_argument(" Index can't be more than source length !");
	}

	if (index < 0)
	{
		throw std::invalid_argument(" Index can't be less than zero length !");
	}

	Array buffer(length - 1);

	for (int i = 0, j = 0; i < length; ++i)
	{
		if (i == index)
		{
			continue;
		}

		buffer[j] = source[i];
		++j;
	}

	source = buffer;
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

	quickSort(source, key, first, last, comparator);
}

void quickSort(Array& source, Array& key, int first, int last, Comparer comparator)
{
	if (source.getLength() != key.getLength())
	{
		throw std::invalid_argument(" Keys do not match array!");
	}

	int f = first, l = last, mid = key[(f + l) / 2];

	do
	{
		while /*(key[f] > mid)*/ (comparator(key[f], mid) > 0)
		{
			++f;
		}
		while /*(key[l] < mid)*/ (comparator(mid, key[l]) > 0)
		{
			--l;
		}

		if (f <= l)
		{
			swap(key[f], key[l]);
			swap(source[f], source[l]);
			++f;
			--l;
		}
	} while (f < l);

	if (first < l)
	{
		quickSort(source, key, first, l, comparator);
	}
	if (f < last)
	{
		quickSort(source, key, f, last, comparator);
	}
}

void mergeSort(Array& source, Array& key, Comparer comparator)
{
	if (source.getLength() != key.getLength())
	{
		throw std::invalid_argument(" Keys do not match array!");
	}

	int length = source.getLength();
	int mid = length / 2, h = 1;

	if (length % 2 == 1)
	{
		mid++;
	}

	Array sourcesBuffer(length);
	Array keysBuffer(length);
	int step;

	while (h < length)
	{
		step = h;
		int i = 0;
		int j = mid;
		int k = 0;
		while (step <= mid)
		{
			while ((i < step) && (j < length) && (j < (mid + step)))
			{
				if (comparator(key[i], key[j]) > 0)
				{
					keysBuffer[k] = key[i];
					sourcesBuffer[k] = source[i];
					i++;
					k++;
				}
				else
				{
					keysBuffer[k] = key[j];
					sourcesBuffer[k] = source[j];
					j++;
					k++;
				}
			}
			while (i < step)
			{
				keysBuffer[k] = key[i];
				sourcesBuffer[k] = source[i];
				i++;
				k++;
			}
			while ((j < (mid + step)) && (j < length))
			{
				keysBuffer[k] = key[j];
				sourcesBuffer[k] = source[j];
				j++;
				k++;
			}

			step = step + h;
		}

		h = h * 2;

		for (i = 0; i < length; i++)
		{
			key[i] = keysBuffer[i];
			source[i] = sourcesBuffer[i];
		}
	}
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

int increase(int lho, int rho)
{
	return  rho - lho;
}

int decrease(int lho, int rho)
{
	return  lho - rho;
}