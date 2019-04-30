#pragma once
#include "Lab4Task1Header.h"
#include <string>


class VideoGame :public Games {

public:
	VideoGame();
	VideoGame(string, string, string);
	void setScore(string);
	string getScore();

protected:
	string score;
};
