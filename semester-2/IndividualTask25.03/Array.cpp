#include "Array.h"
#include <ctime>

using namespace std;

Array::Array(int length)
{
	setLength(length);

	int n = getLength();

	array = new int[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = 0;
	}
}
Array::Array(Array& other)
{
	this->setLength(other.getLength());

	array = new int[getLength()];

	for (int i = 0; i < getLength(); i++)
	{
		array[i] = other[i];
	}
}
Array::~Array()
{
	delete[]array;
	setLength(0);
	cout << " Memory is clean" << endl;
}

int Array::getLength() const
{
	return length;
}
void Array::setLength(int length)
{
	if (length < 0)
	{
		throw std::invalid_argument(" Length must be positive");
	}

	this->length = length;
}
void Array::setItem(int index, int value)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	array[index] = value;
}
int Array::getItem(int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return array[index];
}

void Array::display() const
{
	for (int i = 0; i < getLength(); i++)
	{
		cout << array[i] << '\t';
	}
}
void Array::sort()
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = getLength() - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}
void Array::sort(Comparer comparer)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = getLength() - 1; j > i; j--)
		{
			if (comparer(array[j], array[j - 1]) > 0)
			{
				swap(array[j], array[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}
void Array::inverted()
{
	int n = getLength();

	for (int i = 0; i < getLength() / 2; i++, n--)
	{
		swap(array[i], array[n - 1]);
	}
}
void Array::randomFilling(int limit)
{
	srand(time(NULL));

	for (int i = 0; i < getLength(); i++)
	{
		setItem(i, (rand() % limit / 2)*pow(-1,rand()%2));
	}
}
void Array::shuffle()
{
	int shuffles = getLength();

	for (int index1 = 0, index2 = 0, i = 0; i <= shuffles; i++)
	{
		index1 = ((rand() / rand()) % shuffles + ((rand() * 22) / 9)) % shuffles;
		index2 = ((rand() / rand()) % shuffles + ((rand() * 22) / 9)) % shuffles;
		swap(array[index1], array[index2]);
	}

}
void Array::shift(int steps, bool direction)
{
	int length = getLength();

	if (direction)
	{
		for (int i = 0; i < steps; i++)
		{
			int temp = this->array[length - 1];

			for (int j = length; j >0; j--)
			{
				this->array[j] = this->array[j - 1];
			}

			this->array[0] = temp;
		}
	}
	else
	{
		for (int i = 0; i < steps; i++)
		{
			int temp = this->array[0];

			for (int j = 0; j <length; j++)
			{
				this->array[j] = this->array[j + 1];
			}

			this->array[length - 1] = temp;
		}
	}
}
int Array::counter(int pattern, Comparer comparer) const
{
	int counter = 0;

	for (int i = 0; i < getLength(); i++)
	{
		if (comparer(array[i], pattern))
		{
			counter++;
		}
	}
	return counter;
}
int* Array::selection(int& newLength, Filter filter) const
{
	newLength = 0;

	int length = getLength();
	int* buffer = new int[length];

	for (int i = 0; i < length; i++)
	{
		if (filter(array[i]))
		{
			buffer[newLength] = array[i];
			++newLength;
		}
	}

	int* newArray = new int[newLength];

	for (int i = 0; i < newLength; i++)
	{
		newArray[i] = buffer[i];
	}

	delete[]buffer;

	return newArray;
}
int* Array::search(int& indexArrayLength, Filter filter)
{
	indexArrayLength = 0;
	int length = getLength();
	int* buffer = new int[length];

	for (int i = 0, j = 0; i < length; i++)
	{
		if (filter(array[i]))
		{
			++indexArrayLength;
			buffer[j] = i;
			++j;
		}
	}

	int* indexArray = new int[indexArrayLength];

	for (int i = 0; i < indexArrayLength; i++)
	{
		indexArray[i] = buffer[i];
	}

	delete[]buffer;

	return indexArray;
}


void Array::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int& Array::operator[](const int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return array[index];
}
const int& Array::operator[](int index)const
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return array[index];
}
bool Array::operator==(Array& rho)
{
	if (this->getLength() != rho.getLength())
	{
		return false;
	}

	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->array[i] != rho[i])
		{
			return false;
		}
	}

	return true;
}
bool Array::operator !=(Array& rho)
{
	return !(*this == rho);
}

 Array& Array:: operator=( Array& rho)
{
	int newLength = rho.getLength();

	this->setLength(newLength);

	if (this->array != nullptr)
	{
		delete[] this->array;
	}

	this->array = new int[newLength];

	for (int i = 0; i < newLength; i++)
	{
		this->setItem(i,rho.getItem(i));
	}

	return *this;
}


