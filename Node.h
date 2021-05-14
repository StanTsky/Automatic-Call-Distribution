#pragma once

template <class T>
class Node
{
public:
	T data;
	Node<T> *next;

	Node()
	{
		next = nullptr;
	}

	Node(T newValue)
	{
		data = newValue;
		next = nullptr;
	}
};
