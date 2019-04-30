#pragma once
#include "Lab4Task1Header.h"
#include <string>


class BoardGame:public Games {

public:
	BoardGame();
	BoardGame(string, string, string);
	void setDanceMoves(string);
	string getDanceMoves();

	
protected:

	string danceMoves;
};
