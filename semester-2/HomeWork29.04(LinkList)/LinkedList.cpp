#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() :head(nullptr), tail(nullptr)
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
		addFirst(values[i]);
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
void LinkedList::addFirst(int value)
{
	Node* node = new Node(value);

	if (!head)
	{
		head = node;
		tail = node;
		return;
	}

	node->next = head;
	node->previous = nullptr;
	head->previous = node;
	head = node;
}
void LinkedList::addLast(int value)
{
	Node* node = new Node(value);

	if (!head)
	{
		head = node;
		tail = node;
		return;
	}

	node->next = nullptr;
	node->previous = tail;
	tail->next = node;
	tail = node;
}
void LinkedList::addBeforeItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}

	Node* current = head;// , * previous = current;

	while (current)
	{
		if (current->item == tag)
		{
			if (current == head)
			{
				addFirst(value);
			}
			else
			{
				Node* node = new Node(value), *previous=current->previous;

				previous->next = node;
				node->previous = previous;
				node->next = current;
			}
			return;
		}
		current = current->next;
	}
}
void LinkedList::addAfterItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}

	Node* current = head;

	while (current)
	{
		if (current->item == tag)
		{
			Node* node = new Node(value);

			node->next = current->next;
			node->previous = current;
			current->next = node;

			return;
		}
		current = current->next;
	}

}
void LinkedList::removeFirst()
{
	if (!head)
	{
		cout << " List is empty." << endl;
		return;
	}

	head = head->next;
	delete head->previous;
	head->previous = nullptr;
}
void LinkedList::removeLast()
{
	if (!tail)
	{
		cout << " List is empty." << endl;
		return;
	}

	tail = tail->previous;
	delete tail->next;
	tail->next = nullptr;
}
void LinkedList::removeItem(int tag)
{
	if (isEmpty())
	{
		return;
	}

	Node* current = head;

	while (current)
	{
		if (current->item == tag)
		{
			if (!current->previous)
			{
				this->removeFirst();
			}
			else if (!current->next)
			{
				this->removeLast();
			}
			else
			{
				Node* previous = current->previous;
				Node* next = current->next;

				previous->next = next;
				next->previous = previous;
				delete current;
			}
			return;
		}
		current = current->next;
	}
}

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

		array=resize(array, length++, length);
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
