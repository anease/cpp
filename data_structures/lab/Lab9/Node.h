#pragma once
#include <string>
using namespace std;

template <class T>

class Node {
public:
	Node();
	Node(T);
	Node(T, int);
	T data;
	int count;
	Node* left;
	Node* right;
	~Node() {}
};

template <class T>

Node<T>::Node() {
	data = T();
	count = 0;
	left = nullptr;
	right = nullptr;
}

template <class T>

Node<T>::Node(T word_in) {
	data = word_in;
	count = 0;
	left = nullptr;
	right = nullptr;
}

template <class T>

Node<T>::Node(T word_in, int count_in) {
	data = word_in;
	count = count_in;
	left = nullptr;
	right = nullptr;
}