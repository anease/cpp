#pragma once
#include "pch.h"
#include "ListError.h"
#include <iostream>

const int MAX_ITEMS = 20;

using namespace std;

//const int MAX_ITEMS = 20;

template <class T>

class List {

public:
	List();
	void addItem(T*);
	void removeItem(int);
	void makeEmpty();
	void printResults();
	bool isEmpty();
	bool isFull();
	int getAddCount() { return addCount; };
	int getSubCount() { return subCount; };
	template <class T>
	friend void printList(List<T>);
	~List() {};
private:
	int addCount;
	int subCount;
	T **list;
};


template <class T>


List<T>::List() {
	list = new T*[MAX_ITEMS]();

	addCount = 0;
	subCount = 0;
}


template <class T>


void List<T>::addItem(T* input) {

	int flag = 0;
	int i = 0;
	while (i < MAX_ITEMS && flag == 0) {

		if (list[i] == nullptr) {
			list[i] = input;
			addCount++;
			flag++;
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
				subCount++;
			}
		}

		list[MAX_ITEMS - 1] = nullptr;
		delete temp;
	}
}


template <class T>


void List<T>::makeEmpty() {

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (list[i] != nullptr) {
			delete list[i];
			list[i] = nullptr;
			
		}
	}
}


template <class T>


void List<T>::printResults() {

	cout << "Add count: " << addCount << endl;
	cout << "Remove count: " << subCount << endl;
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

	for (int i = 0; i < MAX_ITEMS; i++) {

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
