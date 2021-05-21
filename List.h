#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node
{
	public:
		T data;
		Node* next;

		// Methods
		Node(T data);
};

// NODE METHODS
template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
}


template <typename T>
class LinkedList
{
	public:
		Node<T>* head;
		Node<T>* tail;

		// Methods
		LinkedList();
		~LinkedList();

		void addToFront(T data);
		void addToEnd(T data);
		void addAtIndex(T data, int index);
		T removeFromFront();
		T removeFromEnd();
		T removeTheFirst(T data);
		void removeAllOf(T data);
		bool elementExists(T data);
		T find(T data);
		int indexOf(T data);
		T retrieveFront();
		T retrieveEnd();
		T retrieve(int index);
		void printList();
		void empty();
		int length();
};


// LINKED LIST METHODS 

template <typename T>
LinkedList<T>::LinkedList()
{
	this->head = NULL;
	this->tail = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* node = head;
	Node<T>* temp;

	if (head != NULL)
	{
		while (node->next != NULL)
		{
			temp = node->next;
			delete node;
			node = temp->next;
		}
	}
}

template <typename T>
void LinkedList<T>::addToFront(T data)
{
	Node<T>* node = new Node<T>(data);

	if (tail == NULL) // check if there is a tail
	{
		tail = node; // if no tail, head becomes tail
		head = tail;
	}
	else
	{
		node->next = head;
		head = node;
	}
}

template <typename T>
void LinkedList<T>::addToEnd(T data)
{
	Node<T>* node = new Node<T>(data);

	if (tail == NULL)
	{
		tail = node;
		head = tail;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}

template <typename T>
void LinkedList<T>::addAtIndex(T data, int index)
{
	if (index > length()) // check that index is within range
	{
		cout << "Node cannot be inserted because the index is greater than the length of the linked list." << endl;
		return;
	}
	
	Node<T>* node = head;
	Node<T>* newNode = new Node<T>(data);

	while ((index-1) > 1) // stop so that node->next = the node before the selected index
	{
		node = node->next;
		index--; // decrement index until we stop at index
	}

	newNode->next = node->next;
	node->next = newNode;
	
	return;
}

template <typename T>
T LinkedList<T>::removeFromFront()
{
	if (head != NULL)
	{
		Node<T>* node = head;
		if (head == tail)
			tail = tail->next;
		head = head->next;
		
		T data = node->data;
		delete node;
		return data;
	}
}

template <typename T>
T LinkedList<T>::removeFromEnd()
{
	Node<T>* node = head;

	if (head == NULL) // check if head null, return null
		return NULL;
	else if (head->next == NULL) // check if head next node is null, delete head and return head
	{
		delete head;
		return node->data; // previously set node = head, therefore node->data = head->data
	}

	// If head != NULL and head->next != NULL, loop to find second to last element in linked list
	while (node->next->next != NULL)
		node = node->next;
	
	// Now node = second to last node (node before tail)
	T data = tail->data;
	delete node->next; // delete tail
	tail = node;
	tail->next = NULL;
	return data;
}

template <typename T>
T LinkedList<T>::removeTheFirst(T data)
{
	if (head->data == data) // check the first node 
		return removeFromFront();
	else if (head->next == tail && tail->data == data)
		return removeFromEnd();
	else 
	{
		Node<T>* node = head;
		while (node->next != NULL)
		{
			if (node->next->data == data)
			{
				node->next = node->next->next;
				return data;
			}
			node = node->next;
		}
		return data;
	}
	return NULL;
}

template <typename T>
void LinkedList<T>::removeAllOf(T data)
{
	if (head->data == data) // check if head contains data in question, delete
		removeFromFront();
	else if (tail->data == data) // check if tail contains data in question, delete
		removeFromEnd();

	Node<T>* node = head;
	while (node->next != NULL) // iterate through each node
	{
		if (node->next->data == data && node->next->next != NULL) // check if node data = data in question, remove if so
			node->next = node->next->next;
		else if (node->next->data == data)
		{
			node->next = NULL;
			break;
		}
		
		node = node->next;
	}

}

template <typename T>
bool LinkedList<T>::elementExists(T data)
{
	if (head->data == data) // check if head contains data, return true (data exists)
		return true;
	else if (tail->data == data) // check if tail contains data, return truee
		return true;
	
	Node<T>* node = head;
	while (node->next != NULL) // iterate through nodes
	{
		if (node->next->data == data) // check if node data = data, return true
			return true;

		node = node->next;
	}
	return false; // if there are no nodes containing data in question, return false (data does not exist)
}

template <typename T>
T LinkedList<T>::find(T data)
{
	if (head->data == data) // check if head contains data, return head node
		return head->data;
	else if (tail->data == data) // check if tail contains data, return tail node
		return tail->data;

	Node<T>* node = head;
	while (node->next != NULL) // iterate through nodes
	{
		if (node->next->data == data) // check if node data = data, return node
			return node->next->data;

		node = node->next;
	}
	return NULL; // if no nodes contain data in question, return NULL
}

template <typename T>
int LinkedList<T>::indexOf(T data)
{
	if (head->data == data) // if head contains data, return 1 as index
		return 1;
	else if (tail->data == data) // if tail contains data, return length (end index) as index
		return length();

	int index = 1;
	Node<T>* node = head;
	while (node->next != NULL) // iterate through nodes
	{
		if (node->data == data) // if a node contains the data, return the index
			return index;

		index++; // increment index if node did not contain data
	}
	return 0; // return 0 if data was not found within linked list
}

template <typename T>
T LinkedList<T>::retrieveFront()
{
	if (head == NULL)
		return NULL;
	return head->data;
}

template <typename T>
T LinkedList<T>::retrieveEnd()
{
	if (tail == NULL)
		return NULL;
	return tail->data;
}

template <typename T>
T LinkedList<T>::retrieve(int index)
{
	if (index > length()) // check if index is within range of length, return NULL if it is not
		return NULL;
	else if (index == length())
		return tail->data;

	Node<T>* node = head;
	while (index > 0) // iterate through loop until we reach index
	{
		node = node->next;
		index--;
	}

	return node->data; // return node at inputted index
}


template <typename T>
void LinkedList<T>::printList()
{
	Node<T>* node = head;

	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::empty()
{
	if (head == NULL)
		return;

	while (head != tail)
		removeFromFront();

	removeFromEnd();
}

template <typename T>
int LinkedList<T>::length()
{
	Node<T>* node = head;

	if (head == NULL) // check if linked list is empty, return 0
		return 0;
	else if (tail == NULL) // check if head is not empty, but tail is, return 1
		return 1;

	int length = 0;

	while (node != NULL)
	{
		node = node->next;
		length++; // increment length for each node looped
	}

	return length;
}



#endif