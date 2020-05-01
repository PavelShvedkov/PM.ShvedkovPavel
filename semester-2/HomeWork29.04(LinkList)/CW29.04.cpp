#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList linkedList;

	int n = 0;
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkedList linkList2(array,10);

	int* array2=linkList2.copyToArray(n);

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << '\t';
	}
	cout << endl;

	linkList2.addAfterItem(5,43);
	cout << linkList2;
	linkList2.addAfterItem(10,4);
	cout << linkList2;
	linkList2.addAfterItem(1, 4);
	cout << linkList2;

	linkList2.removeFirst();
	cout << linkList2;
	linkList2.removeLast();
	cout << linkList2;
	linkList2.removeItem(1);
	cout << linkList2;
}

