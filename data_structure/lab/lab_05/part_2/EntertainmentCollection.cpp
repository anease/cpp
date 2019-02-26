#include "pch.h"
#include "EntertainmentCollection.h"
#include "EntertainmentError.h"
#include <iostream>

template <class T>
void EntertainmentCollection<T>::pushBack(T input) {

	if (top < MAX_SIZE) {
		gameShelf[top] = input;
		top++;

	}
	else {
		throw EntertainmentError("\nThis collection is full!\n");
	}
}

template <class T>
T EntertainmentCollection<T>::popBack() {
	if (top > 0) {
		top--;
		return gameShelf[top];
	}
	else {
		throw EntertainmentError("\nThis collection is empty!\n");
	}
}

template <class T>
int EntertainmentCollection<T>::sizeOf() {

	return top;
}