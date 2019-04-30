#pragma once

using namespace std;

class Card {

public:
	Card() { value = 0; next = nullptr; };
	Card(int in) { value = in; next = nullptr; };
	int value;
	Card* next;
	~Card() {}
};
