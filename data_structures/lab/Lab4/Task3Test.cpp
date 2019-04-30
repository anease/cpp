#include "pch.h"
#include "Lab4Task1Header.h"
#include "Lab4Class1.h"
#include "Lab4Class2.h"
#include <iostream>
#include <string>

using namespace std;

void displayValues(Games game1) {
	string temp1 = "";
	cout << "Current Attributes: " << endl;
	cout << game1.getInstructions() << endl;
	cout << game1.getResults() << endl;
	cout << "Enter new instruction: ";
	cin.ignore();
	getline(cin,temp1);
	game1.setInstructions(temp1);
	cout << endl << "Enter new result: ";
	getline(cin, temp1);
	game1.setResults(temp1);
	cout << endl << endl << "New Attributes: " << endl;
	cout << game1.getInstructions() << endl;
	cout << game1.getResults() << endl << endl;
}

void displayValues(BoardGame game1) {
	string temp;
	cout << endl << "Current Attributes: " << endl;
	cout << game1.getInstructions() << endl;
	cout << game1.getResults() << endl;
	cout << game1.getDanceMoves() << endl << endl;
	cout << "Enter new instruction: ";
	cin.ignore();
	getline(cin,temp);
	game1.setInstructions(temp);
	cout << endl << "Enter new result: ";
	getline(cin, temp);
	game1.setResults(temp);
	cout << endl << "Enter new dance move: ";
	getline(cin, temp);
	game1.setDanceMoves(temp);
	cout << endl << endl << "New Attributes: " << endl;
	cout << game1.getInstructions() << endl;
	cout << game1.getResults() << endl;
	cout << game1.getDanceMoves() << endl << endl;
}

void displayValues(VideoGame game2) {
	string temp;
	cout << "Current Attributes: " << endl;
	cout << game2.getInstructions() << endl;
	cout << game2.getResults() << endl;
	cout << game2.getScore() << endl << endl;
	cout << "Enter new instruction: ";
	cin.ignore();
	getline(cin, temp);
	game2.setInstructions(temp);
	cout << endl << "Enter new result: ";
	getline(cin, temp);
	game2.setResults(temp);
	cout << endl << "Enter new score message: ";
	getline(cin, temp);
	game2.setScore(temp);
	cout << endl << endl << "New Attributes: " << endl;
	cout << game2.getInstructions() << endl;
	cout << game2.getResults() << endl;
	cout << game2.getScore() << endl << endl;
}

int main() {
	int selection;

	Games game;
	BoardGame game1;
	string temp;
	VideoGame game2;

	BoardGame game3;
	Games* bgg = &game3;

	VideoGame game4;
	Games *vgg = &game4;

	int resume =1;

	do {

		do {
			cout << "Please select 1 for game, \n 2 for board game, \n 3 for video game,\n 4 for board game declared as a game,\n or 5 for video game declared as a game: " << endl;
			cin >> selection;
		} while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5);

		switch (selection) {
		case 1:
			game.Play();
			game.Winner();
			displayValues(game);
			break;
		case 2:
			game1.Play();
			game1.Winner();
			displayValues(game1);
			break;
		case 3:
			game2.Play();
			game2.Winner();
			displayValues(game2);
			break;
		case 4:
			bgg->Play();
			bgg->Winner();
			displayValues(*bgg);
			break;
		case 5:
			vgg->Play();
			vgg->Winner();
			displayValues(*vgg);
			break;
		}
		do {
			cout << "Do you wish to continue(1 for yes, 0 for no): ";
			cin >> resume;
		} while (resume != 0 && resume != 1);
	} while (resume == 1);
}
