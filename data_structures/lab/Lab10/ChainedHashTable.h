#pragma once
#include "HashTable.h"
#include "List.h"
#include "Student.h"
#include <string>

using namespace std;

template <class T>

class ChainedHashTable : public HashTable<T> {

public:
	ChainedHashTable() {
		maxItems = 100;
		items = new List<T>[maxItems]();
		removedItem = new T;
		HashTable<T>::length = 0;
	};
	ChainedHashTable(int);
	void addItem(T*);
	T* removeItem(T*);
	int getItem(T*);

protected:
	List<T>* items;
	int maxItems;
	T* removedItem;
};

template <class T>

ChainedHashTable<T>::ChainedHashTable(int max_items) {
	maxItems = max_items;
	items = new List<T>[maxItems]();
	removedItem = new T;
	HashTable<T>::length = 0;
}

template <class T>

void ChainedHashTable<T>::addItem(T* in) {
	string in_ID = *in;
	if (in_ID.length() != 9)
		throw ListError("INVALID MNumber");
	if (HashTable<T>::length == maxItems)
		throw ListError("Full table");

	else {
		int index = HashTable<T>::Hash(in_ID);
		items[index].addItem(in);
		HashTable<T>::length++;
	}
}

template <class T>

T* ChainedHashTable<T>::removeItem(T* in) {
	string in_ID = *in;
	int index = HashTable<T>::Hash(in_ID);

	if (items[index].isInTheList(in) == false)
		return nullptr;

	else {
		removedItem = items[index].getItem(in);
		HashTable<T>::length--;
		return removedItem;
	}
}

template <class T>

int ChainedHashTable<T>::getItem(T* in) {
	string in_ID = *in;
	int index = HashTable<T>::Hash(in_ID);

	return items[index].findItem(in);
}