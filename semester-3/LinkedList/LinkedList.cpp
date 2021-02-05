#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() :head(nullptr)
{
}
LinkedList::LinkedList(int* values, int n)
{
	if (!values)
	{
		throw std::invalid_argument(" Values not found!");
	}

	if (n <= 0)
	{
		throw std::invalid_argument(" Count of values can't be null!");
	}

	for (int i = n - 1; i >= 0; --i)
	{
		addLast(values[i]);
	}
}
LinkedList::LinkedList(const LinkedList& other)
{
	if (other.head != this->head)
	{
		this->clear();

		Node* current = other.head;

		while (!current)
		{
			this->addLast(current->item);
			current = current->next;
		}
	}
}
LinkedList::~LinkedList()
{
	clear();
}

bool LinkedList::isEmpty()const
{
	return !head;
}
void LinkedList::addLast(int value)
{
	Node* node = new Node(value);

	if (!head)
	{
		head = node;
		node->next = nullptr;
	}
	else
	{
		Node* current = head;

		while (current)
		{
			if (!(current->next))
			{
				current->next = node;
				node->next = nullptr;
				break;
			}

			current = current->next;
		}
	}
}
//void LinkedList::addBeforeItem(int tag, int value)
//{
//	if (isEmpty())
//	{
//		return;
//	}
//
//	Node* current = head;// , * previous = current;
//
//	while (current)
//	{
//		if ((current->next)->item == tag)
//		{
//				Node* node = new Node(value);
//
//				node->next = current->next;
//				current->next = node;
//			return;
//		}
//		current = current->next;
//	}
//}
//void LinkedList::addAfterItem(int tag, int value)
//{
//	if (isEmpty())
//	{
//		return;
//	}
//
//	Node* current = head;
//
//	while (current)
//	{
//		if (current->item == tag)
//		{
//			Node* node = new Node(value);
//
//			node->next = current->next;
//			current->next = node;
//
//			return;
//		}
//		current = current->next;
//	}
//
//}
void LinkedList::removeLast()
{
	if (!isEmpty())
	{
		Node* previous = nullptr;
		Node* current = head;

		if (!(current->next))
		{
			this->clear();
			return;
		}
		while (current)
		{
			if (!(current->next))
			{
				delete[]current;

				previous->next = nullptr;

				return;
			}

			previous = current;
			current = current->next;
		}
	}
}
void LinkedList::bubleSortList(Comparer comparator)
{
	if (isEmpty())
	{
		return;
	}

	Node* t, * m, * a, * b;

	if (head == NULL)
	{
		return;
	}

	for (bool go = true; go; ) 
	{
		go = false;
		a = t = head;
		b = head->next;

		while (b)
		{
			if (comparator(b->item , a->item)) 
			{
				if (t == a)
				{
					head = b;
				}
				else
				{
					t->next = b;
				}

				a->next = b->next;
				b->next = a;

				m = a, a = b, b = m;
				go = true;
			}

			t = a;
			a = a->next;
			b = b->next;
		}
	}
}
void LinkedList::insertSortList(Comparer comparer)
{
	if (isEmpty())
	{
		return;
	}

	Node* a, * b, * p, * h = NULL;

	for (Node* i = head; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;

		for (p = NULL; (b != NULL) && comparer(b->item, a->item); )
		{
			p = b;
			b = b->next;
		}

		if (p == NULL)
		{
			a->next = h;
			h = a;
		}
		else
		{
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
	{
		head = h;
	}
}
void LinkedList::selectSortList(Comparer comparer)
{
	if (isEmpty())
	{
		return;
	}

	Node* a, * b;
	    Node* p1, * p2, * r1, * r2;
	
	    for (p1 = r1 = head; p1 != NULL; p1 = p1->next) {
	        a = p2 = r2 = p1;
	        for (b = p1->next; b != NULL; b = b->next) {
	            if (comparer(b->item , p2->item))
				{
	                r2 = a;
	                p2 = b;
	            }

	            a = b;
	        }
	
	        if (p1 != p2) 
			{
				if (p1 == head)
				{
					head = p2;
				}
				else
				{
					r1->next = p2;
				}
	
	            b = p2->next; 

	            if (p1 == r2) 
				{
	                p2->next = p1;
	                p1->next = b;
	            }
	            else {
	                a = p1->next;
	                r1->next = p2;
	                r2->next = p1;
	                p1->next = b;
	                p2->next = a;
	            }

	            p1 = p2;
	        }

	        r1 = p1;
	    }
}
//void LinkedList::removeItem(int tag)
//{
//	if (isEmpty())
//	{
//		return;
//	}
//
//	Node* current = head->next;
//	Node* previous = head;
//
//	while (current)
//	{
//		if (current->item == tag)
//		{
//			Node* next = current->next;
//
//			previous->next = next;
//			delete current;
//		}
//		current = previous;
//		previous = previous -> next;
//	}
//}

int* LinkedList::copyToArray(int& length)
{
	if (isEmpty())
	{
		length = 0;

		return nullptr;
	}

	length = 1;

	Node* current = head;
	int* array = new int[length];

	while (current)
	{
		array[length - 1] = current->item;

		if (!current->next)
		{
			return array;
		}

		current = current->next;

		array = resize(array, length++, length);
	}
}
void LinkedList::clear()
{
	Node* current = head;

	while (current)
	{
		head = current->next;
		delete current;
		current = head;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (head == other.head)
	{
		return *this;
	}
	else
	{
		this->clear();
	}

	Node* current = other.head;
	while (current)
	{
		this->addLast(current->item);
		current = current->next;
	}
}

int* LinkedList::resize(int* source, int sourceLength, int newLength)
{
	int* buffer = new int[newLength];

	for (int i = 0; i < sourceLength; i++)
	{
		buffer[i] = source[i];
	}

	delete[]source;
	source = buffer;

	return source;
}

ostream& operator<<(ostream& stream, const LinkedList& list)
{
	LinkedList::Node* current = list.head;

	if (list.isEmpty())
	{
		stream << " List is empty.";
		return stream;
	}

	while (current)
	{
		stream << *current;
		current = current->next;
	}

	stream << endl;

	return stream;
}
