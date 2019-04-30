#pragma once
#include "Node.h"
#include "ListError.h"

template <class T>

class List {
public:
	List();
	void addItem(T*);
	T* getItem(T*);
	int findItem(T*);
	bool isInTheList(T*);
	bool isEmpty();
	int size();

	void reset();
	//overloaded operators
	bool operator<(const List<T>&);
	bool operator>(const List<T>&);
	bool operator==(List<T>);
	~List() {}
private:
	//instance variables(Node pointers)
	int length;
	Node<T>* first;
	Node<T>* last;
	Node<T>* nextPtr;
};

template <class T>

List<T>::List() {
	length = 0;
	first = nullptr;
	last = nullptr;
	nextPtr = first;
}

template <class T>

void List<T>::addItem(T* in) {

	Node<T>* newNode;
	Node<T>* temp;
	newNode = new Node<T>(in);

	if (first == nullptr) {
		first = newNode;
		last = newNode;
		nextPtr = newNode;
	}

	else {
		temp = last;
		last = newNode;
		temp->next = last;
	}

	length++;
}

template <class T>

T* List<T>::getItem(T* in) {

	T* returnVal;
	Node<T>* nodePtr;
	Node<T>* prevNode;

	if (first == nullptr) return nullptr;

	if (*(first->data) == *in) {
		returnVal = first->data;
		nodePtr = first->next;
		delete first;
		first = nodePtr;
		length--;
		return returnVal;
	}

	else {
		nodePtr = first;

		while (nodePtr->next != nullptr && *(nodePtr->next->data) != *in) {
			nodePtr = nodePtr->next;
		}

		if (nodePtr->next != nullptr && *(nodePtr->next->data) == *in) {
			returnVal = nodePtr->next->data;
			prevNode = nodePtr->next;
			nodePtr->next = nodePtr->next->next;
			if (nodePtr->next == nullptr)
				last = nodePtr;
			delete prevNode;
			length--;
			return returnVal;
		}

		else return nullptr;
	}
}

template <class T>

bool List<T>::isInTheList(T* in) {
	Node<T>* nodePtr;
	nodePtr = first;

	while (nodePtr != nullptr && *(nodePtr->data) != *in) {
		nodePtr = nodePtr->next;
	}

	if (nodePtr == nullptr) return false;
	else return true;
}

template <class T>

int List<T>::findItem(T* in) {
	int spotsChecked = 0;
	Node<T>* nodePtr;
	nodePtr = first;
	spotsChecked++;
	while (nodePtr != nullptr && *(nodePtr->data) != *in) {
		nodePtr = nodePtr->next;
		spotsChecked++;
	}

	if (nodePtr == nullptr) return 0;
	else return spotsChecked;
}

template <class T>

bool List<T>::isEmpty() {
	if (length > 0)
		return false;
	else
		return true;
}

template <class T>

int List<T>::size() {
	return length;
}

template <class T>

void List<T>::reset() {

	nextPtr = first;
}

template <class T>

bool List<T>::operator<(const List<T>& rhs) {

	if (rhs.size() > length) {
		return true;
	}

	else return false;
}

template <class T>

bool List<T>::operator>(const List<T>& rhs) {

	if (rhs.size() > length) {
		return false;
	}

	else return true;
}

template <class T>

bool List<T>::operator==(List<T> rhs) {
	if (length == 0 && rhs.size() == 0)
		return true;
	if (rhs.size() != length) return false;
	T* temp = nextPtr;
	bool result = true;
	this->reset();
	rhs.reset();
	T* temp2 = this->seeNext();
	while (temp2 != nullptr) {
		if (temp2 != rhs.seeNext())
			result = false;
		temp2 = this->seeNext();
	}
	nextPtr = temp;
	rhs.reset();
	return result;
}