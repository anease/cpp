#pragma once
#include "pch.h"
#include "ListError.h"
#include <vector>
#include <iostream>

using namespace std;

template <class T>

class Queue {
private:
	vector<T> data;
public:
	Queue() {};
	void enqueue(T);
	T dequeue();
	T peek();
	int length();
	bool isEmpty();
	void makeEmpty();
	void print();
	~Queue() {};
};

template <class T>

void Queue<T> ::enqueue(T in_val) {
	data.push_back(in_val);
}

template <class T>

T Queue<T> ::dequeue() {
	if (data.size() == 0)
		throw ListError("This Queue is empty!");
	else {
		T out_val = data.at(0);
		data.erase(data.begin());
		return out_val;
	}
}

template <class T>

T Queue<T>::peek() {
	if (data.size() == 0)
		throw ListError("This Queue is empty!");
	else
		return data[0];
}

template <class T>

int Queue<T>::length() {
	return data.size();
}

template <class T>

void Queue<T>::makeEmpty() {
	data.clear();
}

template <class T>

bool Queue<T> ::isEmpty() {
	if (data.size() == 0)
		return true;
	else
		return false;
}

template <class T>

void Queue<T> ::print() {
	for (int i = 0; i < data.size(); i++) {
		if (i < data.size() - 1)
			cout << data[i] << ", ";
		else
			cout << data[i] << endl;
	}
}