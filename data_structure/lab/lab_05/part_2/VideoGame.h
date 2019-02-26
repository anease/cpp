#pragma once
#include "Games.h"
#include <string>


class VideoGame :public Games {

public:
	VideoGame();
	VideoGame(string, string, string);
	void setScore(string);
	string getScore();
	void display();

protected:
	string score;
};
