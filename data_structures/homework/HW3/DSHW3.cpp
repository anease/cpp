#include "pch.h"
#include "Deck.h"

void deal(Deck &player, Deck &computer) {

	srand(time(NULL));

	int baseDeck[52];
	int random;

	for (int i = 0; i < 13; i++) {
		baseDeck[4 * i] = i + 2;
		baseDeck[4 * i + 1] = i + 2;
		baseDeck[4 * i + 2] = i + 2;
		baseDeck[4 * i + 3] = i + 2;
	}

	for (int i = 0; i < 52; i++) {

		do {
			random = rand() % 52;
		} while (baseDeck[random] == 0);

		if (player.numCards() < 26) {
			int temp = baseDeck[random];
			player.addCard(temp);
			baseDeck[random] = 0;
		}

		else {
			int temp = baseDeck[random];
			computer.addCard(temp);
			baseDeck[random] = 0;
		}
	}
}

string withA(int in) {
	if (in != 8 && in != 14)
		return " with a ";
	else
		return " with an ";
}

string toString(int val) {
	if (val < 11)
		return to_string(val);
	else {
		switch (val) {
		case 11:
			return "Jack";
		case 12:
			return "Queen";
		case 13:
			return "King";
		case 14:
			return "Ace";
		}
	}
}

int main()
{
	Deck user;
	Deck computer;
	SidePile userStack;
	int playerWins = 0;
	int compWins = 0;
	int round = 0;
	int roundMax = 0;
	int flag = 0;

	do {
		cout << "Would you like to play until cards run out or until a round limit is reached? 1(run out) 0(round limit): ";
		cin >> flag;
	} while (flag != 1 && flag != 0);

	if (flag == 0) {
		cout << "How many rounds would you like to play? ";
		cin >> roundMax;
	}

	system("cls");

	deal(user, computer);

	while ((user.numCards() + userStack.length() < 52 && user.numCards() + userStack.length() > 0) && ((flag == 0 && round < roundMax) || flag == 1)) {

		int choice;
		round++;

		cout << endl << "You have " << user.numCards();
		if(user.numCards() == 1)
			cout << " card in your deck and " << endl;
		else
			cout << " cards in your deck and " << endl;
		cout << userStack.length();
		if(userStack.length() == 1)
			cout << " card in your side pile." << endl << endl;
		else
			cout << " cards in your side pile." << endl << endl;
		if (user.numCards() > 0) {
			if (user.peek() != 8 && user.peek() != 14)
				cout << "Your next card is a ";
			else
				cout << "Your next card is an ";
			cout << toString(user.peek()) << endl << endl;
		}
		else
			cout << "Your deck is out of cards. You must use your side pile." << endl << endl;

		cout << "Choose a play option: " << endl;
		cout << "1) Play this card" << endl;
		cout << "2) Place this card in your side pile" << endl;
		cout << "3) Use card from side pile" << endl;
		cout << "4) See number of cards in computer's deck" << endl;
		cout << "Choice: ";
		cin >> choice;

		system("cls");

		switch (choice) {

		case 1:
			if (user.numCards() > 0) {
				if (user.peek() > computer.peek()) {

					cout << "\n\tYou beat the computer's " << toString(computer.peek());
					cout << withA(user.peek());
					cout << toString(user.peek()) << endl;
					user.addCard(computer.removeCard());
					user.addCard(user.removeCard());
					playerWins++;
				}
				else {

					cout << "\n\tThe Computer beat your " << toString(user.peek());
					cout << withA(computer.peek());
					cout << toString(computer.peek()) << endl;
					computer.addCard(user.removeCard());
					computer.addCard(computer.removeCard());
					compWins++;
				}
			}
			else {
				cout << "\n\tYour deck is out of cards. You must use your side pile." << endl;
				round--;
			}
			break;

		case 2:

			if (user.numCards() == 1 && userStack.length() < 5) {
				userStack.push(user.removeCard());
				round--;
			}
			else if (userStack.length() < 5) {
				userStack.push(user.removeCard());
				if (user.peek() > computer.peek()) {

					cout << "\n\tYou beat the computer's " << toString(computer.peek());
					cout << withA(user.peek());
					cout << toString(user.peek()) << endl;
					user.addCard(computer.removeCard());
					user.addCard(user.removeCard());
					playerWins++;
				}
				else {

					cout << "\n\tThe Computer beat your " << toString(user.peek());
					cout << withA(computer.peek());
					cout << toString(computer.peek()) << endl;
					computer.addCard(user.removeCard());
					computer.addCard(computer.removeCard());
					compWins++;
				}
			}
			else {
				cout << "\n\tYour side pile is full." << endl;
				round--;
			}
			break;

		case 3:

			int temp;
			if (userStack.length() == 0) {
				cout << "\n\tYour side pile is empty." << endl;
				round--;
			}
			else if (user.numCards() > 0) {
				temp = userStack.pop();
				if (user.peek() + temp > computer.peek()) {

					cout << "\n\tYou beat the computer's " << toString(computer.peek());
					cout << withA(user.peek());
					cout << toString(user.peek());
					if (temp != 8 && temp != 14)
						cout << " and a ";
					else
						cout << " and an ";
					cout << toString(temp) << endl;
					user.addCard(computer.removeCard());
					user.addCard(temp);
					user.addCard(user.removeCard());
					playerWins++;
				}
				else {

					cout << "\n\tThe Computer beat your " << toString(user.peek()) << " and " << toString(temp);
					cout << withA(computer.peek());
					cout << toString(computer.peek()) << endl;
					computer.addCard(temp);
					computer.addCard(user.removeCard());
					computer.addCard(computer.removeCard());
					compWins++;
				}
			}
			else {
				temp = userStack.pop();
				if (temp > computer.peek()) {

					cout << "\n\tYou beat the computer's " << toString(computer.peek());
					cout << withA(temp);
					cout << toString(temp) << endl;
					user.addCard(computer.removeCard());
					user.addCard(temp);
					playerWins++;
				}
				else {

					cout << "\n\tThe Computer beat your " << toString(temp);
					cout << withA(computer.peek());
					cout << toString(computer.peek()) << endl;
					computer.addCard(temp);
					computer.addCard(computer.removeCard());
					compWins++;
				}
			}

			break;

		case 4:

			cout << "\n\tThe Computer has " << computer.numCards() << " cards" << endl;
			break;

		default:

			cout << "\n\tERROR: Invalid Input" << endl;
			round--;
			break;
		}
	}

	if (flag == 0 && round == roundMax) {
		if (playerWins > compWins)
			cout << "\n\tCongratulations! You won " << playerWins << " of the " << roundMax << " rounds, making you the overall winner." << endl;
		else if (playerWins < compWins)
			cout << "\n\tUnfortunately, you only won " << playerWins << " of the " << roundMax << " rounds, meaning you lost to the computer." << endl;
		else
			cout << "\n\tYou won " << playerWins << " of the " << roundMax << " rounds, meaning you and the computer have tied!" << endl;
	}
	else if (user.numCards() > 0)
		cout << "\n\tCongratulations! You won by taking all of the computers' cards." << endl;
	else
		cout << "\n\tYou lose! The computer has taken all of the cards." << endl;

	return 0;
}
