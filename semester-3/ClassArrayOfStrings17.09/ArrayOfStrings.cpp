#include "ArrayOfStrings.h"

ArrayOfStrings::ArrayOfStrings(const string* source, int length)
{
	if (length <= 0)
	{
		throw std::out_of_range("Length can't be less than zero");
	}

	this->setLength(length);
	this->array = new string[length];
	for (int i = 0; i < length; i++)
	{
		(this->array)[i] = source[i];
	}
}
ArrayOfStrings::ArrayOfStrings(const char** source, int rows)
{
	if (rows <= 0)
	{
		throw std::out_of_range("Length can't be less than zero");
	}

	this->setLength(rows);
	this->array = new string[rows];
	for (int i = 0; i < rows; i++)
	{
		(this->array)[i] = source[i];
	}
}
ArrayOfStrings::ArrayOfStrings(const ArrayOfStrings& source)
{
	int length = source.getLength();
	this->setLength(length);
	this->array = new string[length];

	for (int i = 0; i < length; i++)
	{
		(this->array)[i] = source.array[i];
	}
}

void ArrayOfStrings::setLength(int length)
{
	this->length = length;
}

int ArrayOfStrings::getLength() const
{
	return length;
}

ArrayOfStrings& ArrayOfStrings::elementwiseÑoncatenation(const ArrayOfStrings& other) const
{
	int min = 0;

	ArrayOfStrings* buffer = new ArrayOfStrings;

	if (this->getLength() < other.getLength())
	{
		*buffer = other;
		min = this->getLength();
	}
	else
	{
		*buffer = *this;
		min = other.getLength();
	}

	for (int i = 0; i < min; i++)
	{
		(*buffer)[i] = (*this)[i] + other[i];
	}

	return *buffer;
}
ArrayOfStrings ArrayOfStrings::mergeAndRemoveRepits(const ArrayOfStrings& other) const
{
	int newLength = this->getLength() + other.getLength();
	int thisLength = this->getLength();
	int otherLength = other.getLength();

	ArrayOfStrings buffer;

	for (int i=0; i < thisLength; i++)
	{
		buffer = buffer + (*this)[i];
	}
	for (int i = 0; i < otherLength; i++)
	{
		buffer = buffer +other[i];
	}

	for (int i = 0; i < newLength; i++)
	{
		string compared = buffer[i];

		for (int j = i+1; j < newLength; j++)
		{
			if (compared==buffer[j])
			{
				buffer = buffer.deleteElement(j );
				newLength--;
			}
		}
	}
	
	return buffer;
}
ArrayOfStrings& ArrayOfStrings::addToEnd(const string& element)
{
	if (!element[0])
	{
		return *this;
	}

	int newLength = this->getLength()+1;
	string* buffer = new string[newLength];

	for (int i = 0; i < newLength-1; i++)
	{
		if (!(newLength-1))
		{
			continue;
		}
		buffer[i] = (*this)[i];
	}

	buffer[newLength-1] = element;

	ArrayOfStrings* result=new ArrayOfStrings(buffer, newLength );

	delete[]buffer;

	return *result;
}
ArrayOfStrings ArrayOfStrings::deleteElement(int index)
{
	int length = this->getLength();

	/*if (index < 0 || index >= getLength());
	{
		throw std::out_of_range("");
	}*/

	ArrayOfStrings buffer;

	for (int i = 0; i < length; i++)
	{
		if (i==index)
		{
			continue;
		}

		buffer=buffer+ (*this)[i];
	}

	 buffer;

	return buffer;
}
void ArrayOfStrings::lexicalBubleSort(Comparer comparator)
{
	int length = this->getLength();
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;

		for (int j = length - 1; j > i; j--)
		{
			if (comparator((*this)[j], (*this)[j - 1]))
			{
				swap((*this)[j], (*this)[j - 1]);
				isSorted = false;
			}
		}

		i++;
	}
}

void ArrayOfStrings::displayArray() const
{
	cout << *this << endl;
}
void ArrayOfStrings::dispalayString(const string& other) const
{
	for (int i = 0; i < this->getLength(); i++)
	{
		if (other == (*this)[i])
		{
			cout << (*this)[i] << endl;
			return;
		}
	}

	cout << " String not found!" << endl;
}

string& ArrayOfStrings::operator [](int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return array[index];
}

const string& ArrayOfStrings::operator[](int index)const
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range(" Out of range");
	}

	return array[index];
}

ArrayOfStrings& ArrayOfStrings::operator=(const ArrayOfStrings& other)
{
	int length = other.getLength();
	this->setLength(length);
	this->array = new string[length];

	for (int i = 0; i < length; i++)
	{
		(this->array)[i] = other.array[i];
	}

	return *this;
}

ArrayOfStrings ArrayOfStrings::operator+(const ArrayOfStrings& rho)
{
	return ArrayOfStrings(this->elementwiseÑoncatenation(rho));
}

ArrayOfStrings ArrayOfStrings::operator+(const string& other)
{
	ArrayOfStrings buffer(this->addToEnd(other));

	return buffer;
}

ArrayOfStrings ArrayOfStrings::operator*(const ArrayOfStrings& rho) const
{
	return ArrayOfStrings(this->mergeAndRemoveRepits(rho));
}

ostream& operator<<(ostream& out, const ArrayOfStrings& source)
{
	int length = source.getLength();

	for (int i = 0; i < length; i++)
	{
		out << source[i] << " ";
	}

	out << endl;

	return out;
}

istream& operator>>(istream& in, const ArrayOfStrings& source)
{
	//
	return in;
}

ArrayOfStrings::~ArrayOfStrings()
{
	delete[]array;
}


