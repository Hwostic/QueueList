#include "MyQueue.h"
#include <iostream>
using namespace std;
 



template <typename T>
bool MyQueue<T>::IsEmpty()
{
	return size==0;
}

template <typename T>
void MyQueue<T>::pushBack(const T& value)
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
}

template <typename T>
T MyQueue<T>::popFront()
{
	if (IsEmpty())
	{
		cerr << "Очередь пуста! Нельзя удалить элемент." << endl;
		throw runtime_error("Очередь пуста!"); // Бросаем исключение, если очередь пуста

	}
	else
	{
		Node* temp = front; // Сохраняем указатель на удаляемый узел
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

int MyQueue<int>::getSize()
{
	return size;
}

template <typename T>
T MyQueue<T>::getFront() const
{
	if (IsEmpty()) {
		cerr << "Очередь пуста!" << endl;
		throw runtime_error("Очередь пуста!");
	}
	return front->data;
}

template <typename T>
T MyQueue<T>::getBack() const
{
	if (IsEmpty()) {
		cerr << "Очередь пуста!" << endl;
		throw runtime_error("Очередь пуста!");
	}
	return back->data;
}

template <typename T>
void MyQueue<T>::show() const
{
	if (IsEmpty()) {
		cout << "Очередь пуста." << endl;
		return;
	}
	Node<T>* current = front;
	cout << "Очередь (размер " << size << "): " <<endl;

	for (int i = 0; i < size; i++)
	{
		while (current != nullptr)
		{
			cout << ++i<<": " <<current->data << " ";
			current = current->next;
		}
	}
	
	cout << endl;
}