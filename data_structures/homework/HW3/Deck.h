#pragma once
#include "SidePile.h"
#include "Card.h"
#include <iostream>
#include <ctime>

class Deck {

public:

	Deck();
	void addCard(int);
	int removeCard();
	int numCards();
	int peek();
	
	~Deck() {};

private:

	int size;
	SidePile sidePile;
	Card* first;
	Card* last;
};


Deck::Deck() {
	first = nullptr;
	last = nullptr;
	size = 0;
}

int Deck::peek() {
	return first->value;
}

int Deck::numCards() {

	return size;
}

int Deck::removeCard() {

	if (first != nullptr) {
		int val = first->value;
		Card* temp = first;
		first = temp->next;
		delete temp;
		size--;
		return val;
	}

	else {
		throw StackError("This Deck is Empty!");
	}

}


void Deck::addCard(int in) {
	if (first == nullptr) {
		first = new Card(in);
		last = first;
	}

	else {
		last->next = new Card(in);
		last = last->next;
	}

	size++;
}
