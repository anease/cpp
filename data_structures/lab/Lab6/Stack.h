#include "pch.h"
#include "StackError.h"
#include <iostream>
#pragma once

using namespace std;

template <class T>

class Stack {
public:
	Stack();
	Stack(int);
	void push(T*);
	T* pop();
	T* top();
	int length();
	void empty();
	template <class T>
	friend void print(Stack<T>);
	~Stack() {};
private:
	int count;
	int size;
	T **stack;
};

template <class T>

Stack<T>::Stack(int size_in) {
	stack = new T*[size_in];
	size = size_in;
	count = 0;
}

template <class T>

Stack<T>::Stack() {
	stack = new T*[5];
	size = 5;
	count = 0;
}

template <class T>

void Stack<T>::push(T* data) {
	if (count >= size)
		throw StackError("\nThis Stack is full!\n");
	else {
		stack[count] = data;
		count++;
	}
}

template <class T>

T* Stack<T>::pop() {
	if (count == 0)
		throw StackError("\nThis Stack is Empty!\n");
	else {
		count--;
		return stack[count];
	}
}

template <class T>

T* Stack<T>::top() {
	if (count == 0)
		throw StackError("\nThis Stack is Empty!\n");
	else
		return stack[count-1];
}

template <class T>

int Stack<T>::length() {
	return count;
}

template <class T>

void Stack<T>::empty() {
	count = 0;
	delete[] stack;
	stack = new T*[size];
}

template <class T>

void print(Stack<T> s) {
	for (int i = 0; i < s.count; i++) {
		if (i < s.count - 1)
			cout << *(s.stack[i]) << ", ";
		else
			cout << *(s.stack[i]);
	}
	cout << endl;
}
