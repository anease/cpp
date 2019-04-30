#pragma once
#include "Card.h"
#include "StackError.h"
#include <iostream>

class SidePile {

public:
	SidePile();

	void push(int);
	int pop();
	int length();

	~SidePile() {};

private:
	int count;
	int size;
	int *stack;
};

int SidePile::length() {
	return count;
}

SidePile::SidePile() {
	stack = new int[5];
	size = 5;
	count = 0;
}


void SidePile::push(int data) {
	if (count >= size)
		throw StackError("\nThis Stack is full!\n");
	else {
		stack[count] = data;
		count++;
	}
}


int SidePile::pop() {
	if (count == 0)
		throw StackError("\nThis Stack is Empty!\n");
	else {
		count--;
		return stack[count];
	}
}
