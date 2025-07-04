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
	T size; //текущий размер очереди

public:

	MyQueue() :front(nullptr), back(nullptr), size(0) {};

	~MyQueue()
	{
		while (!IsEmpty())
		{
			popFront();
		}

	};

	// Проверка, пуста ли очередь
	bool IsEmpty()
	{
		return size == 0;
	}

	// Добавление элемента в конец очереди
	void pushBack(T value)
	{
		Node<T>* newNode = new Node<T>(value);

		if (IsEmpty())
		{
			// Если очередь пуста, новый узел становится и началом, и концом
			front = back = newNode;
		
		}
		else
		{
			back->next = newNode; // Добавляем новый узел в конец
			newNode->prev = back; // Устанавливаем указатель prev для нового узла
			back = newNode;       // Обновляем указатель back
			
		}
		size++;
	}

	// Удаление элемента из начала очереди
	T popFront()
	{
		if (IsEmpty())
		{
			cerr << "Очередь пуста! Нельзя удалить элемент." << endl;
			throw runtime_error("Очередь пуста!"); // Бросаем исключение, если очередь пуста

		}
		else
		{
			Node<T>* temp = front; // Сохраняем указатель на удаляемый узел
			T deleteValue = front->data; // Сохраняем значение удаляемого элемента
			front = front->next; // Обновляем верхний элемент

			if (front != nullptr) {
				front->prev = nullptr; // Обновляем указатель prev у нового front
			}
			else {
				// Если удаляем последний элемент, обнуляем back
				back = nullptr;
			}

			delete temp; // Удаляем узел

			size--;      // Уменьшаем размер очереди

			return deleteValue; // Возвращаем значение удаляемого элемента
		}
	}

	int getSize()
	{
		return size;
	}

	T getFront() 
	{
		if (IsEmpty()) 
		{
			cerr << "Очередь пуста!" << endl;
			throw runtime_error("Очередь пуста!");
		}
		return front->data;
	}


	T getBack() 
	{
		if (IsEmpty()) 
		{
			cerr << "Очередь пуста!" << endl;
			throw runtime_error("Очередь пуста!");
		}
		return back->data;
	}

	void show() 
	{
		if (IsEmpty())
		{
			cerr << "Очередь пуста!" << endl;
			throw runtime_error("Очередь пуста!");
		}
		else
		{
			Node<T>* current = front;
			cout << "Очередь (размер " << size << "): " << endl;

			for (int i = 0; i < size; i++) //только для нумерации элементов
			{
				while (current != nullptr)
				{
					cout << ++i << ": " << current->data << endl;
					current = current->next;
				}
			}

			cout << endl;
		}
	}
};

