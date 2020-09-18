#ifndef ARRAYOFSTRINGS_H
#define ARRAYOFSTRINGS_H

#include <iostream>
#include <fstream>

using namespace std;

typedef bool (*Comparer)(string, string);
class ArrayOfStrings
{
public:
	ArrayOfStrings() :length(0), array(nullptr) {}
	ArrayOfStrings(const string*, int);
	ArrayOfStrings(const char**, int);
	ArrayOfStrings(const ArrayOfStrings&);

	void setLength(int);

	int getLength()const;

	ArrayOfStrings& elementwise—oncatenation(const ArrayOfStrings&)const;
	ArrayOfStrings mergeAndRemoveRepits(const ArrayOfStrings&)const;
	ArrayOfStrings& addToEnd(const string&);
	ArrayOfStrings deleteElement(int);
	void lexicalBubleSort(Comparer);
	void displayArray()const;
	void dispalayString(const string&)const;

	const string& operator[](int)const;
	string& operator[](int);
	ArrayOfStrings& operator=(const ArrayOfStrings&);
	ArrayOfStrings operator +(const ArrayOfStrings&);
	ArrayOfStrings operator +(const string&);
	ArrayOfStrings operator *(const ArrayOfStrings&)const;
	friend ostream& operator << (ostream&, const ArrayOfStrings&);
	friend istream& operator >> (istream&, const ArrayOfStrings&);

	~ArrayOfStrings();
private:
	string* array;
	int length;
};

#endif // !ARRAYOFSTRINGS_H

