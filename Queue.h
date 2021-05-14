#pragma once

#include "LinkedList.h"

class Queue
{
private:
	LinkedList<myType> list;

public:
	void enqueue(myType item)
	{
		list.addBack(item);
	}

	void dequeue()
	{
		list.removeFront();
	}

	myType getFront()
	{
		ListIterator<myType> *iter = list.getIterator();
		iter->next();
		return *iter->getValue();
	}

	bool isEmpty()
	{
		return list.isEmpty();
	}
};