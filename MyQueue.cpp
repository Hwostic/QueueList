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
		// ���� ������� �����, ����� ���� ���������� � �������, � ������
		front = back = newNode;
	}
	else 
	{
		back->next = newNode; // ��������� ����� ���� � �����
		newNode->prev = back; // ������������� ��������� prev ��� ������ ����
		back = newNode;       // ��������� ��������� back
	}
}

template <typename T>
T MyQueue<T>::popFront()
{
	if (IsEmpty())
	{
		cerr << "������� �����! ������ ������� �������." << endl;
		throw runtime_error("������� �����!"); // ������� ����������, ���� ������� �����

	}
	else
	{
		Node* temp = front; // ��������� ��������� �� ��������� ����
		T deleteValue = front->data; // ��������� �������� ���������� ��������
		front = front->next; // ��������� ������� �������
		
		if (front != nullptr) {
			front->prev = nullptr; // ��������� ��������� prev � ������ front
		}
		else {
			// ���� ������� ��������� �������, �������� back
			back = nullptr;
		}

		delete temp; // ������� ����

		size--;      // ��������� ������ �������

		return deleteValue; // ���������� �������� ���������� ��������
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
		cerr << "������� �����!" << endl;
		throw runtime_error("������� �����!");
	}
	return front->data;
}

template <typename T>
T MyQueue<T>::getBack() const
{
	if (IsEmpty()) {
		cerr << "������� �����!" << endl;
		throw runtime_error("������� �����!");
	}
	return back->data;
}

template <typename T>
void MyQueue<T>::show() const
{
	if (IsEmpty()) {
		cout << "������� �����." << endl;
		return;
	}
	Node<T>* current = front;
	cout << "������� (������ " << size << "): " <<endl;

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