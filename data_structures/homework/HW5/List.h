#pragma once
#include "pch.h"
#include "ListError.h"
#include <iostream>

using namespace std;

template <class T>

class List {

public:
	List();
	List(int);
	void addItem(T*);
	void removeItem(int);
	T* findItem(int);
	void makeEmpty();
	bool isEmpty();
	bool isFull();
	int getMax() { return MAX_ITEMS; };
	T* getStart() { return list[0]; };
	T* getLast();
	int getLength() { return length; };
	template <class T>
	friend void printList(List<T>);
	~List() {};

private:
	int length;
	int MAX_ITEMS;
	T **list;
};
template <class T>

List<T>::List() {
	MAX_ITEMS = 20;
	list = new T*[MAX_ITEMS]();
	length = 0;
}

template <class T>

List<T>::List(int in_size) {
	MAX_ITEMS = in_size;
	list = new T*[MAX_ITEMS]();
	length = 0;
}

template <class T>

void List<T>::addItem(T* input) {

	int flag = 0;
	int i = 0;
	while (i < MAX_ITEMS && flag == 0) {

		if (list[i] == nullptr) {
			list[i] = input;
			length++;
			flag++;
			return;
		}
		i++;
	}
	if (flag == 0) throw ListError("\nThis list is full\n");
}

template <class T>

void List<T>::removeItem(int index) {
	T* temp;
	if (list[index] == nullptr) {
		throw ListError("\nThis index is empty\n");
	}

	else {

		temp = list[index];

		for (int i = index; i < (MAX_ITEMS); i++) {
			if (i + 1 <= MAX_ITEMS - 1) {
				list[i] = list[i + 1];
			}
		}

		list[MAX_ITEMS - 1] = nullptr;
		delete temp;
		length--;
	}
}

template <class T>

T* List<T>::findItem(int index) {
	if (index < 0 || index > MAX_ITEMS) {
		throw ListError("Index out of bounds");
	}
	return list[index];
}

template <class T>

T* List<T>::getLast() {
	if (length == 0) {
		throw ListError("This list is empty");
	}
	return list[length - 1];
}

template <class T>

void List<T>::makeEmpty() {

	for (int i = 0; i < MAX_ITEMS; i++) {
		delete list[i];
		list[i] = nullptr;
	}

	length = 0;
}

template <class T>

bool List<T>::isFull() {
	int count = 0;
	for (int h = 0; h < MAX_ITEMS; h++) {
		if (list[h] == nullptr)
			count++;
	}
	if (count == 0)
		return true;
	else
		return false;
}

template <class T>

bool List<T>::isEmpty() {
	if (list[0] == nullptr)
		return true;
	else
		return false;
}


template <class T>

void printList(List<T> L) {

	for (int i = 0; i < L.getLength(); i++) {

		if (L.list[i] == nullptr) {
			cout << "_";
		}
		else {
			cout << *(L.list[i]);
		}
		cout << " ";
	}
	cout << endl;
}