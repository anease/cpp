#include "pch.h"
#include <iostream>
#include "EntertainmentCollection.h"
#include "EntertainmentCollection.cpp"
//Added #include ^^^.cpp to fix linker error with template functions
#include "BoardGame.h"
#include "VideoGame.h"

using namespace std;

int main() {

	int response = 0;
	do {
		cout << "Which type of games do you want for your collection? (1 = Board Game, 2 = Video Game): ";
		cin >> response;
	} while (response != 1 && response != 2);

	EntertainmentCollection <BoardGame> gameShelf;
	EntertainmentCollection <VideoGame> gameShelf2;

	string response2;
	int response3 = 0;

	switch (response) {
	case 1:

		while (response3 != 4) {
			do {
				cout << endl << "Press 1 to add a board game to the shelf." << endl;
				cout << "Press 2 to remove a board game from the shelf." << endl;
				cout << "Press 3 to see how many board games are currently on the shelf." << endl;
				cout << "Press 4 to quit." << endl;
				cin >> response3;
			} while (response3 != 1 && response3 != 2 && response3 != 3 && response3 != 4);
			switch (response3) {
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
				}
				catch (exception& e) {
					cerr << e.what();
				}
				break;
			case 2:
				try {
					gameShelf.popBack().display();
				}
				catch (exception& e) {
					cerr << e.what();
				}
				break;
			case 3:
				cout << endl << gameShelf.sizeOf() << endl;
				break;
			default:
				continue;
			}
		}

		break;



	case 2:

		while (response3 != 4) {
			do {
				cout << endl << "Press 1 to add a video game to the shelf." << endl;
				cout << "Press 2 to remove a video game from the shelf." << endl;
				cout << "Press 3 to see how many video games are currently on the shelf." << endl;
				cout << "Press 4 to quit." << endl;
				cin >> response3;
			} while (response3 != 1 && response3 != 2 && response3 != 3 && response3 != 4);
			switch (response3) {
			case 1:
				try {
					VideoGame* newVideoGame;
					newVideoGame = new VideoGame;
					cout << endl << "Enter video game instructions: ";
					cin.ignore();
					getline(cin, response2);
					newVideoGame->setInstructions(response2);
					cout << "Enter video game results: ";
					getline(cin, response2);
					newVideoGame->setResults(response2);
					cout << "Enter video game score message: ";
					getline(cin, response2);
					newVideoGame->setScore(response2);
					gameShelf2.pushBack(*newVideoGame);
				}
				catch (exception& e) {
					cerr << e.what();
				}
				break;
			case 2:
				try {
					gameShelf2.popBack().display();
				}
				catch (exception& e) {
					cerr << e.what();
				}
				break;
			case 3:
				cout << endl << gameShelf2.sizeOf() << endl;
				break;
			default:
				continue;
			}
		}


		break;
	}
}