#pragma once
#include "List.h"


template <class T>


class BlankSpotList : public List<T> {
public:
	BlankSpotList();
	void addItem(T*);
	void removeItem(int);
	void makeEmpty();
	void printResults();
	bool isEmpty();
	bool isFull();
	int getAddCount() { return addCount; };
	int getSubCount() { return subCount; };
	template <class T>
	friend void printList(BlankSpotList<T>);
	~BlankSpotList() {};
private:
	T** list;
	int addCount;
	int subCount;

};


template <class T>


BlankSpotList<T>::BlankSpotList() {
	list = new T*[MAX_ITEMS]();
	addCount = 0;
	subCount = 0;
}


template <class T>


void BlankSpotList<T>::addItem(T* input) {

	T* here = input;
	T* next = nullptr;
	if (this->isFull())
		throw ListError("List is full.");
	else {
		if (list[MAX_ITEMS / 2] == nullptr) {
			list[MAX_ITEMS / 2] = input;
			addCount++;
		}

		else {

			for (int i = ((MAX_ITEMS / 2) - 1); i < (MAX_ITEMS - 1); i++) {
			
				next = list[i + 1];
				list[i + 1] = here;
				addCount++;
				here = next;
				
				if (here == nullptr) return;
			}

			for (int i = (-1); i < (MAX_ITEMS / 2 - 1); i++) {
				
				next = list[i + 1];
				list[i + 1] = here;
				addCount++;
				here = next;
				
				if (here == nullptr) return;
			}
		}
	}
}


template <class T>


void BlankSpotList<T>::removeItem(int index) {

	
	if (list[index] == nullptr) {
		throw ListError("\nThis index is empty\n");
	}

	delete list[index];
	list[index] = nullptr;
	
	subCount++;

}


template <class T>


void printList(BlankSpotList<T> L) {

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


template <class T>


void BlankSpotList<T>::printResults() {

	cout << "Add count: " << addCount << endl;
	cout << "Remove count: " << subCount << endl;
}


template <class T>


void BlankSpotList<T>::makeEmpty() {

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (list[i] != nullptr) {
			delete list[i];
			list[i] = nullptr;
			
		}
	}
}


template <class T>


bool BlankSpotList<T>::isFull() {
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


bool BlankSpotList<T>::isEmpty() {
	int count = 0;
	for (int h = 0; h < MAX_ITEMS; h++) {
		if (list[h] == nullptr)
			count++;
	}
	if (count == MAX_ITEMS)
		return true;
	else
		return false;
}
