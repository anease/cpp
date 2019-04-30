#pragma once
#include "Node.h"
#include "ListError.h"
#include <iostream>

using namespace std;

template <class T>

class Tree {
public:
	Tree();
	void insert(T);
	Node<T>* find(T);
	int size();
	Node<T>** getAllAscending();
	Node<T>** getAllDescending();
	Node<T>* findParent(T);
	void emptyTree();
	void display();
	Node<T>* remove(T);
	void balanceTree();
	~Tree() { delete parent; }
private:

	Node<T>** nodeArray;
	Node<T>* removedNode;
	void getAllHelper(Node<T>* &);
	void displayHelper(Node<T>*);
	void emptyTreeHelper(Node<T>*&);
	Node<T>* removeLeastGreater(Node<T>*);
	Node<T>* root;
	void insertNode(Node<T>*);
	int count;
	int recursionIndex;
	Node<T>* parent;
};


template <class T>

Tree<T>::Tree() {
	root = nullptr;
	count = 0;
	removedNode = new Node<T>;
	parent = new Node<T>;
}


template <class T>

void Tree<T>::balanceTree() {

	if (count == 0)
		throw ListError("This tree is empty");

	if (count >= 4) {

		nodeArray = getAllAscending();
		int midPoint = count / 2;

		Node<T>** balanceArray = new Node<T>*[count];

		for (int j = 0; j < count; j++) {
			balanceArray[j] = new Node<T>(nodeArray[j]->data, nodeArray[j]->count);
		}

		int tempCount = count;

		emptyTree();

		insertNode(balanceArray[midPoint]);

		if (tempCount % 2 != 0) {
			for (int i = 1; i <= (tempCount / 2); i++) {
				insertNode(balanceArray[midPoint + i]);
				insertNode(balanceArray[midPoint - i]);
			}
		}

		else {
			for (int i = 1; i < (tempCount / 2); i++) {
				insertNode(balanceArray[midPoint + i]);
				insertNode(balanceArray[midPoint - i]);
			}
			insertNode(balanceArray[0]);
		}

	}
}


template <class T>

void Tree<T>::insertNode(Node<T>* inVal) {

	Node<T>* ptr = root;

	if (root == nullptr) {
		root = inVal;
		count++;
		return;
	}

	while (((inVal->data > ptr->data) && (ptr->right != nullptr)) || ((inVal->data < ptr->data) && (ptr->left != nullptr))) {
		if (inVal->data > ptr->data) ptr = ptr->right;
		else ptr = ptr->left;
	}

	if (inVal->data < ptr->data) {
		ptr->left = inVal;
	}

	else {
		ptr->right = inVal;
	}
	count++;
}


template <class T>

void Tree<T>::insert(T inVal) {

	Node<T>* ptr = root;

	Node<T>* tempFind = this->find(inVal);

	if (tempFind != nullptr) {
		tempFind->count++;
	}

	else {

		if (root == nullptr) {
			root = new Node<T>(inVal);
			root->count++;
			count++;
			return;
		}

		while (((inVal > ptr->data) && (ptr->right != nullptr)) || ((inVal < ptr->data) && (ptr->left != nullptr))) {
			if (inVal > ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}

		if (inVal < ptr->data) {
			ptr->left = new Node<T>(inVal);
			ptr->left->count++;
		}

		else {
			ptr->right = new Node<T>(inVal);
			ptr->right->count++;
		}

		count++;
	}
	this->balanceTree();
}


template <class T>

Node<T>* Tree<T>::find(T inVal) {
	Node<T>* ptr = root;
	while (ptr != nullptr) {
		if (ptr->data > inVal) {
			ptr = ptr->left;
		}
		else if (ptr->data < inVal) {
			ptr = ptr->right;
		}
		else
			return ptr;
	}
	return nullptr;
}


template <class T>

int Tree<T>::size() {
	return count;
}


template <class T>

Node<T>** Tree<T>::getAllAscending() {

	if (count == 0)
		throw ListError("This tree is empty");

	else {
		nodeArray = new Node<T>*[count];
		recursionIndex = 0;
		getAllHelper(root);

		int i, j;
		Node<T>* temp;

		if (count > 1) {

			for (i = 0; i < count; i++)
			{
				for (j = i + 1; j < count; j++)
				{
					if (nodeArray[i]->data > nodeArray[j]->data)
					{
						temp = nodeArray[i];
						nodeArray[i] = nodeArray[j];
						nodeArray[j] = temp;
					}
				}
			}
		}

		return nodeArray;
	}
}


template <class T>

void Tree<T>::getAllHelper(Node<T>* &in) {
	if (in != nullptr) {
		nodeArray[recursionIndex] = in;
		recursionIndex++;
	}
	else return;

	getAllHelper(in->left);
	getAllHelper(in->right);
}


template <class T>

Node<T>** Tree<T>::getAllDescending() {
	if (count == 0)
		throw ListError("This tree is empty");
	else {
		nodeArray = new Node<T>*[count];
		recursionIndex = 0;
		getAllHelper(root);

		int i, j;
		Node<T>* temp;

		if (count > 1) {
			for (i = 0; i < count; i++)
			{
				for (j = i + 1; j < count; j++)
				{
					if (nodeArray[i]->data < nodeArray[j]->data)
					{
						temp = nodeArray[i];
						nodeArray[i] = nodeArray[j];
						nodeArray[j] = temp;
					}
				}
			}
		}

		return nodeArray;
	}
}


template <class T>

void Tree<T>::emptyTree() {
	emptyTreeHelper(root);
	count = 0;
}

template <class T>

void Tree<T>::emptyTreeHelper(Node<T>* &in) {
	Node<T>* temp;
	if (in == nullptr) return;

	emptyTreeHelper(in->left);
	emptyTreeHelper(in->right);

	temp = in;
	in = nullptr;
	delete temp;
	
}

template <class T>

Node<T>* Tree<T>::findParent(T in) {

	Node<T>* curr = root;
	T leftVal;
	T rightVal;
	parent->left = root;

	if (curr != nullptr && curr->data == in)
		return parent;

	//Deals with comparing nullptrs in following while loop
	if (curr->left != nullptr)
		leftVal = curr->left->data;
	else
		leftVal = T();
	if (curr->right != nullptr)
		rightVal = curr->right->data;
	else
		rightVal = T();

	//Find parent of value to be removed
	while (leftVal != in && rightVal != in) {
		if (curr->data < in)
			curr = curr->right;
		else
			curr = curr->left;

		if (curr->left != nullptr)
			leftVal = curr->left->data;
		else
			leftVal = T();
		if (curr->right != nullptr)
			rightVal = curr->right->data;
		else
			rightVal = T();
	}
	return curr;
}

template <class T>

Node<T>* Tree<T>::remove(T in) {

	if (root == nullptr)
		return nullptr;

	Node<T>* curr = this->findParent(in);
	Node<T>* val = this->find(in);
	Node<T>* temp;
	removedNode->count = val->count;
	removedNode->data = val->data;

	if (val == nullptr)
		return nullptr;

	// No children 
	if (val->left == nullptr && val->right == nullptr) {

		if (curr->left != nullptr && curr->left->data == in) {
			temp = curr->left;
			if (curr->left == root)
				root = nullptr;
			curr->left = nullptr;
			delete temp;
			count--;
		}
		else {
			temp = curr->right;
			if (curr->right == root)
				root = nullptr;
			curr->right = nullptr;
			delete temp;
			count--;
		}
	}

	// 1 children
	else if ((val->left != nullptr && val->right == nullptr) || (val->left == nullptr && val->right != nullptr)) {

		if (val->left != nullptr) {
			if (curr->left != nullptr && curr->left->data == in) {
				temp = curr->left;
				if (curr->left == root)
					root = val->left;
				curr->left = val->left;
				delete temp;
				count--;
			}
			else {
				temp = curr->right;
				curr->right = val->left;
				delete temp;
				count--;
			}
		}

		else {
			if (curr->left != nullptr && curr->left->data == in) {
				temp = curr->left;
				if (curr->left == root)
					root = val->right;
				curr->left = val->right;
				delete temp;
				count--;
				
			}
			else {
				temp = curr->right;
				curr->right = val->right;
				delete temp;
				count--;
				
			}
		}
	}

	// 2 children
	else {

		//left side
		if (curr->left != nullptr && curr->left->data == in) {
			Node<T>* replace = removeLeastGreater(curr->left);
			replace->left = curr->left->left;
			replace->right = curr->left->right;
			temp = curr->left;
			if (curr->left == root)
				root = replace;
			curr->left = replace;
			delete temp;
			count--;
		}

		//right side
		else {
			Node<T>* replace = removeLeastGreater(curr->right);
			replace->left = curr->right->left;
			replace->right = curr->right->right;
			temp = curr->right;
			curr->right = replace;
			delete temp;
			count--;
		}
	}
	if(count != 0)
		this->balanceTree();
	return removedNode;
}

template <class T>

Node<T>* Tree<T>::removeLeastGreater(Node<T>* ptr) {
	Node<T>* temp = ptr->right;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	Node<T>* parent = findParent(temp->data);
	if (parent->right != nullptr && parent->right->data == temp->data)
		parent->right = nullptr;
	else
		parent->left = nullptr;
	return temp;
}

template <class T>

void Tree<T>::display() {
	displayHelper(root);
}

template <class T>

void Tree<T>::displayHelper(Node<T>* in)
{
	if (in == nullptr)
		return;
	else {
		cout << in->data.word << "[" << in->count << "], ";
		if (in->left != nullptr)
			cout << in->left->data.word << "[" << in->left->count << "], ";
		else
			cout << "__, ";
		if (in->right != nullptr)
			cout << in->right->data.word << "[" << in->right->count << "], " << endl;
		else
			cout << "__" << endl;

		displayHelper(in->left);
		displayHelper(in->right);
	}
}
