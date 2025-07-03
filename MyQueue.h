#include <iostream>
using namespace std;
#pragma once

template <typename T>
class MyQueue
{
private:

	template <typename T>
	struct Node
	{

		T data;
		Node* next;
		Node* prev;

		Node(const T& value) : data(value), next(nullptr), prev(nullptr) {};

	};

	Node<T>* front; //указатель на начало очереди (первый элемент)
	Node<T>* back; //указатель на конец очереди (последний элемент)
	int size; //текущий размер очереди

public:

	MyQueue() :front(nullptr), back(nullptr), size(0) {};

	~MyQueue()
	{
		while (!IsEmpty())
		{
			popFront();
		}

	}

	bool IsEmpty();

	void pushBack(const T& value);

	T popFront();

	int getSize();

	T getFront() const;

	T getBack() const;

	void show() const;
};

