#include "pch.h"
#include "VideoGame.h"
#include <iostream>
#include <string>

using namespace std;

VideoGame::VideoGame() {
	instructions = "Mashing Buttons";
	results = "Winner, winner, chicken dinner!";
	score = "New High Score!";
}
VideoGame::VideoGame(string instructions_in, string results_in, string score_in) {
	instructions = instructions_in;
	results = results_in;
	score = score_in;
}

void VideoGame::setScore(string score_in) {
	score = score_in;
}

string VideoGame::getScore() {
	return score;
}

void VideoGame::display() {
	cout << endl << instructions << endl << results << endl << score << endl;
}