#pragma once

template <class T>

class Node {
public:
	Node() { data = new(T); next = nullptr; }
	Node(T* in) { data = in; next = nullptr; }
	T* data;
	Node<T>* next;
	~Node() {}
};
