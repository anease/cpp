#include "pch.h"
#include "Shelf.h"
#include "ShelfError.h"
#include <iostream>

void Shelf::pushBack(BoardGame input) {

	if (top < MAX_SIZE) {
		gameShelf[top] = input;
		top++;

	}
	else {
		throw ShelfError("\nThis shelf is full!\n");
	}
}

BoardGame Shelf::popBack() {
	if (top > 0) {
		top--;
		return gameShelf[top];
	}
	else {
		throw ShelfError("\nThis shelf is empty!\n");
	}
}

int Shelf::sizeOf() {

	return top;
}