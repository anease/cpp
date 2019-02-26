#include "pch.h"
#include <iostream>
#include <string>
#include "Shelf.h"
using namespace std;

int main()
{
	Shelf gameShelf;
	int response = 0;
	string response2;
	while (response != 4) {
		do {
			cout << "Press 1 to add a board game to the shelf." << endl;
			cout << "Press 2 to remove a board game from the shelf." << endl;
			cout << "Press 3 to see how many board games are currently on the shelf." << endl;
			cout << "Press 4 to quit." << endl;
			cin >> response;
		} while (response != 1 && response != 2 && response != 3 && response != 4);
		switch (response) {
		case 1:
			try {
				BoardGame* newBoardGame;
				newBoardGame = new BoardGame;
				cout << endl << "Enter board game instructions: ";
				cin.ignore();
				getline(cin, response2);
				newBoardGame->setInstructions(response2);
				cout << "Enter board game results: ";
				getline(cin, response2);
				newBoardGame->setResults(response2);
				cout << "Enter board game dance moves: ";
				getline(cin, response2);
				newBoardGame->setDanceMoves(response2);
				gameShelf.pushBack(*newBoardGame);
				cout << endl;
			}
			catch (exception& e) {
				cerr << e.what();
			}
			break;
		case 2:
			try {
				gameShelf.popBack().display();
				cout << endl;
			}
			catch (exception& e) {
				cerr << e.what();
			}
			break;
		case 3:
			cout << endl << gameShelf.sizeOf() << endl << endl;
			break;
		default:
			continue;
		}
	}
}