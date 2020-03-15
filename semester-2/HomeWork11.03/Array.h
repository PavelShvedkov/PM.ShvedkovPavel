#include <iostream>
#include "ctime"

typedef int(*Comparer)(int, int);
typedef bool(*Filter)(int);

class Array
{
public:
	Array(int);
	Array(Array&);
	~Array();

	inline	int getLength()const;
	//int* getArray()const ÏËÎÕÎ
	//{
	//	return array;
	//}
	void setItem(int, int);
	int getItem(int);

	void display()const;
	void sort();
	void sort(Comparer);
	void inverted();
	void randomFilling(int);
	void shuffle();
	int counter(int, Comparer)const;
	int* selection(int&, Filter)const;
	int* search(int&, Filter);


	int& operator [](int);
	Array& operator =( Array&);//íóæíà ïîìîùü

private:
	int* array;
	int length;
	static void swap(int&, int&);
	inline void setLength(int);
};
