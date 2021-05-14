#pragma once

#include "Node.h"
#include "Call.h"
#include <string>

// note: commented out typedef can be used to switch to double data type

//typedef int myType;
//typedef std::string myType;
typedef Call myType;

//typedef char myType;

template <class T>
class ListIterator
{
private:
	Node<T> * current;

public:
	ListIterator(Node<T> *n)
	{
		current = n;
	}

	bool next()
	{
		if (current->next != nullptr)
		{
			current = current->next;
			return true;
		}

		return false;
	}

	myType* getValue()
	{
		if (current != nullptr)
			return &current->data;
		return nullptr;
	}
};

template <class T>
class LinkedList
{
private:
	Node<T> *first;

public:
	LinkedList()
	{
		first = new Node<T>();
	}


	bool isEmpty()
	{
		return first->next == nullptr;
	}

	void addFront(myType value)
	{
		// Create a new node with the input value.
		Node<T> *newNode = new Node<T>(value);

		// Attach new node to the list.
		newNode->next = first->next;
		first->next = newNode;
	}

	void addBack(myType value)
	{
		Node<T> *temp = first;  // Declare a traversal pointer and start it at the beginning

		while (temp->next != nullptr)  // Find the end of the list
			temp = temp->next;

		// Create a new node with new data.
		Node<T> *newNode = new Node<T>(value);

		temp->next = newNode;  // Attach new node to end of list
	}

	void removeFront()
	{
		// Point a temp pointer to the first node.
		Node<T> *temp = first->next;

		// Reassign dummy node's link to the following node.
		first->next = temp->next;
		temp->next = nullptr;

		// Delete the temp pointer.
		delete temp;
	}

	void removeBack()
	{
		// Point trailer pointer to dummy
		Node<T> *trailer = first;

		// Point temp pointer to trailer's next
		Node<T> *temp = trailer->next;

		// Traverse list until temp is on last node
		while (temp->next != nullptr)
		{
			trailer = temp;
			temp = temp->next;
		}

		// Set trailer's next to null
		trailer->next = nullptr;

		// Delete temp
		delete temp;
	}


	Node<T> *find(int value)
	{
		Node<T> *temp = first->next;

		while (temp != nullptr)
		{
			if (temp->data == value)
				return temp;

			temp = temp->next;
		}

		return nullptr;
	}


	void display()
	{
		Node<T> *temp = first->next;

		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	ListIterator<T>* getIterator()
	{
		ListIterator<T> *iter = new ListIterator<T>(first); //->next
		return iter;
	}
};