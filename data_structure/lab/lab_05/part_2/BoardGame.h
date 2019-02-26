#pragma once
#include <string>
#include "Games.h"

class BoardGame: public Games {

public:
	BoardGame();
	BoardGame(string, string, string);
	void setDanceMoves(string);
	string getDanceMoves();
	void display();


protected:

	string danceMoves;
};

