#pragma once
#include "List.h"


template <class T>


class EndList : public List<T> {
public:
	EndList();
	void addItem(T*);
	void removeItem(int);
	void makeEmpty();
	bool isEmpty();
	bool isFull();
	void printResults();
	int getAddCount() { return addCount; };
	int getSubCount() { return subCount; };
	template <class T>
	friend void printList(EndList<T>);
	~EndList() {};
private:
	int addCount;
	int subCount;
	T** list;
};


template <class T>


EndList<T>::EndList() {
	list = new T*[MAX_ITEMS]();
	addCount = 0;
	subCount = 0;
}


template <class T>


void EndList<T>::addItem(T* input) {

	int flag = 0;
	int i = MAX_ITEMS - 1;
	while (i >= 0 && flag == 0) {

		if (list[i] == nullptr) {
			list[i] = input;
			addCount++;
			flag++;
		}

		i--;
	}
	if (flag == 0) throw ListError("\nThis list is full\n");
}


template <class T>


void EndList<T>::removeItem(int index) {
	T* temp;
	if (list[index] == nullptr) {
		throw ListError("\nThis index is empty\n");
	}

	else {

		temp = list[index];
		
		for (int i = index; i > -1; i--) {
			if (i - 1 >= 0) {
				list[i] = list[i - 1];
				subCount++;
			}
		}

		list[0] = nullptr;
		delete temp;

	}
}


template <class T>


void EndList<T>::makeEmpty() {

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (list[i] != nullptr) {
			delete list[i];
			list[i] = nullptr;
			
		}
	}
}


template <class T>


void EndList<T>::printResults() {

	cout << "Add count: " << addCount << endl;
	cout << "Remove count: " << subCount << endl;
}


template <class T>


bool EndList<T>::isEmpty() {
	if (list[MAX_ITEMS - 1] == nullptr)
		return true;
	else
		return false;
}


template <class T>


bool EndList<T>::isFull() {
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


void printList(EndList<T> L) {

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
