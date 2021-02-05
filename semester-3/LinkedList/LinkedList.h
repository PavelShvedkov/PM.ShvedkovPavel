#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>

typedef bool(*Comparer)(int, int);
using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(int*, int);
	LinkedList(const LinkedList&);
	~LinkedList();

	bool isEmpty()const;
	void addLast(int);
	void removeLast();
	void bubleSortList(Comparer);
	void insertSortList(Comparer);
	void selectSortList(Comparer);
	int* copyToArray(int&);
	void clear();

	friend ostream& operator <<(ostream&, const LinkedList&);

	LinkedList& operator =(const LinkedList&);

private:
	struct Node
	{
		Node() :next(nullptr) {		}
		Node(int value) :item(value), next(nullptr){		}

		friend ostream& operator <<(ostream& stream, const Node& node)
		{
			if (!node.next)
			{
				stream << node.item;
			}
			else
			{
				stream << node.item << " -> ";
			}
			return stream;
		}

		int item{ 0 };//{point, student, ....}
		Node* next;
	};
	Node* head;
	static int* resize(int*, int, int);
};
#endif LINKEDLIST_H
