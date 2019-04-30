#pragma once
#include "BoardGame.h"

class Shelf {
public:

	Shelf() { top = 0; };
	const static int MAX_SIZE = 10;
	void pushBack(BoardGame);
	BoardGame popBack();
	int sizeOf();


private:
	BoardGame gameShelf[MAX_SIZE];
	int top;

};