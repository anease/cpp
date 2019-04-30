#include "pch.h"
#include "BoardGame.h"
#include <iostream>
#include <string>

using namespace std;

BoardGame::BoardGame() {
	instructions = "Roll the dice.";
	results = "Dancing time.";
	danceMoves = "Cupid Shuffle";
}
BoardGame::BoardGame(string instructions_in, string results_in, string dance_in) {
	instructions = instructions_in;
	results = results_in;
	danceMoves = dance_in;
}

void BoardGame::setDanceMoves(string dance_in) {
	danceMoves = dance_in;
}

string BoardGame::getDanceMoves() {
	return danceMoves;
}

void BoardGame::display() {
	cout << endl << instructions << endl << results << endl << danceMoves << endl;
}