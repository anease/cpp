#pragma once
#include "ListError.h"
#include "Student.h"
#include <string>

using namespace std;

template <class T>

class HashTable {
public:
	HashTable() {
		maxItems = 100;
		items = new T*[maxItems]();
		removedItem = new T;
		length = 0;
	};
	HashTable(int);
	void addItem(T*);
	T* removeItem(T*);
	int getItem(T*);
	int getLength() { return length; }
	~HashTable() { delete removedItem; delete items; }
protected:
	int Hash(string);
	int maxItems;
	int length;
	T** items;
	T* removedItem;
};

template <class T>

HashTable<T>::HashTable(int max_items) {
	maxItems = max_items;
	items = new T*[maxItems]();
	removedItem = new T;
	length = 0;
}

template <class T>

void HashTable<T>::addItem(T* in) {
	string in_ID = *in;
	if (in_ID.length() != 9)
		throw ListError("INVALID MNumber");
	if (length == maxItems)
		throw ListError("Full table");
	else {
		int index = Hash(in_ID);
		while (items[index] != nullptr) {
			if (index == (maxItems - 1))
				index = 0;
			else
				index = index + 1;
		}
		items[index] = in;
		length++;
	}
}

template <class T>

T* HashTable<T>::removeItem(T* in) {
	string in_ID = *in;
	int ctr = 0;
	int index = Hash(in_ID);
	while (items[index] != in && ctr < maxItems) {
		if (index == (maxItems - 1))
			index = 0;
		else
			index = index + 1;
		ctr++;
	}
	if (items[index]->getID() != in->getID())
		return nullptr;
	else {
		*removedItem = items[index];
		delete items[index];
		items[index] = nullptr;
		length--;
		return removedItem;
	}
}


template <class T>

int HashTable<T>::getItem(T* in) {
	int spotsChecked = 0;
	string in_ID = *in;
	int ctr = 0;
	int index = Hash(in_ID);
	spotsChecked++;
	while (items[index] != in && ctr < maxItems) {
		if (index == (maxItems - 1))
			index = 0;
		else
			index = index + 1;
		ctr++;
		spotsChecked++;
	}
	if (ctr >= maxItems)
		return 0;
	else {
		return spotsChecked;
	}
}

template <class T>

int HashTable<T>::Hash(string in) {
	int sum = 0;
	for (unsigned int i = 0; i < in.length(); i++) {
		sum = sum + in[i];
	}

	return sum % maxItems;
}