#include "Integer.h"

Integer::Integer(int source)
{
	setItem(source);
}

void Integer::setItem(int source)
{
	item = source;
}

Integer Integer::operator+(const Integer& other)
{
	return Integer(item + other.item);
}

Integer Integer::operator-(const Integer& other)
{
	return Integer(item - other.item);
}

ostream& operator << (ostream& out, const Integer& source)
{
	out << source.item;

	return out;
}
istream& operator >> (istream& in,  Integer& source)
{
	int buffer = 0;
	in >> buffer;

	source.setItem(buffer);

	return in;
}