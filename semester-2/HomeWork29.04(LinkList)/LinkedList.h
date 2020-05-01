#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(int*, int);
	~LinkedList();

	bool isEmpty()const;
	void addFirst(int);
	void addLast(int);
	void addBeforeItem(int, int);
	void addAfterItem(int, int);
	void removeFirst();
	void removeLast();
	void removeItem(int);
	int* copyToArray(int&);
	void clear();

	friend ostream& operator <<(ostream&, const LinkedList&);


private:
	struct Node
	{
		Node() :next(nullptr), previous(nullptr) {		}
		Node(int value) :item(value), next(nullptr), previous(nullptr) {		}

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
		Node* previous;
	};
	Node* head;
	Node* tail;
	static int* resize(int*, int, int);
};
#endif LINKEDLIST_H
//в node добавить Node* previos; в LinkList добавть Node* tail;