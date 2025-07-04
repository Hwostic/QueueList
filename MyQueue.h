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

	Node<T>* front; //��������� �� ������ ������� (������ �������)
	Node<T>* back; //��������� �� ����� ������� (��������� �������)
	T size; //������� ������ �������

public:

	MyQueue() :front(nullptr), back(nullptr), size(0) {};

	~MyQueue()
	{
		while (!IsEmpty())
		{
			popFront();
		}

	};

	// ��������, ����� �� �������
	bool IsEmpty()
	{
		return size == 0;
	}

	// ���������� �������� � ����� �������
	void pushBack(T value)
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
		size++;
	}

	// �������� �������� �� ������ �������
	T popFront()
	{
		if (IsEmpty())
		{
			cerr << "������� �����! ������ ������� �������." << endl;
			throw runtime_error("������� �����!"); // ������� ����������, ���� ������� �����

		}
		else
		{
			Node<T>* temp = front; // ��������� ��������� �� ��������� ����
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

	int getSize()
	{
		return size;
	}

	T getFront() 
	{
		if (IsEmpty()) 
		{
			cerr << "������� �����!" << endl;
			throw runtime_error("������� �����!");
		}
		return front->data;
	}


	T getBack() 
	{
		if (IsEmpty()) 
		{
			cerr << "������� �����!" << endl;
			throw runtime_error("������� �����!");
		}
		return back->data;
	}

	void show() 
	{
		if (IsEmpty())
		{
			cerr << "������� �����!" << endl;
			throw runtime_error("������� �����!");
		}
		else
		{
			Node<T>* current = front;
			cout << "������� (������ " << size << "): " << endl;

			for (int i = 0; i < size; i++) //������ ��� ��������� ���������
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

