#include "pch.h"
#include "WheelHeader.h"
#include "Player.h"
#include "HardWheelHeader.h"
#include "HardPlayer.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void easyMode() {

	Player player;
	Player house;
	int bet;
	bool flag = true;
	int range;
	
	do {
		cout << "Enter the number of values on the roulette wheel (minimum 6, maximum 20): ";
		cin >> range;
	} while (range < 6 || range > 20);
	cout << endl;

	player.wheel.setValues(range);
	house.wheel.setValues(range);

	while (player.getMoney() >= 10 && flag == true) {

		player.displayMoney();

		do {
			cout << "Place a wager (minimum of $10): ";
			cin >> bet;
		} while (bet < 10 || bet > player.getMoney());

		player.setBet(bet);
		player.wheel.spin();

		cout << endl << "Your ball landed on " << player.wheel.getBall() << endl << endl;

		if (player.getMoney() > 0) {

			do {
				cout << "Would you like to increase your wager? (minimum $0, maximum $";
				if (player.getMoney() - player.getBet() < player.getBet() * 2)
					cout << player.getMoney() - player.getBet() << "): ";
				else
					cout << player.getBet() * 2  << "): ";
				cin >> bet;
			} while (bet < 0 || bet > (player.getBet() * 2) || bet > (player.getMoney() - player.getBet()));

			player.setBet(player.getBet() + bet);
		}

		house.wheel.spin();

		cout << endl << "The house ball landed on " << house.wheel.getBall() << endl;

		if (player.wheel.getBall() > house.wheel.getBall()) {
			cout << endl << "You beat the house, and won $" << player.getBet() << endl;
			player.setMoney(player.getMoney() + player.getBet());
		}
		else {
			cout << endl << "You lost $" << player.getBet() << " to the house." << endl;
			player.setMoney(player.getMoney() - player.getBet());
		}

		player.displayMoney();

		do {
			cout << endl << "Do you wish to continue? (Enter 1 for yes, 0 for no): ";
			cin >> flag;
			cout << endl;
		} while (flag != 1 && flag != 0);

	}

}


void hardMode() {

	Player player;
	HardPlayer house;
	int bet;
	bool flag = true;
	int range;

	do {
		cout << "Enter the number of values on the roulette wheel (minimum 6, maximum 20): ";
		cin >> range;
	} while (range < 6 || range > 20);

	house.wheel.setOriginalValueSize(range);

	cout << endl;

	player.wheel.setValues(range);
	house.wheel.setValues(range);

	while (player.getMoney() >= 10 && flag == true) {

		player.displayMoney();

		do {
			cout << "Place a wager (minimum of $10): ";
			cin >> bet;
		} while (bet < 10 || bet > player.getMoney());

		player.setBet(bet);
		player.wheel.spin();

		cout << endl << "Your ball landed on " << player.wheel.getBall() << endl << endl;

		if (player.getMoney() > 0) {

			do {
				cout << "Would you like to increase your wager? (minimum $0, maximum $";
				if (player.getMoney() - player.getBet() < player.getBet() * 2)
					cout << player.getMoney() - player.getBet() << "): ";
				else
					cout << player.getBet() * 2  << "): ";
				cin >> bet;
			} while (bet < 0 || bet >(player.getBet() * 2) || bet > (player.getMoney() - player.getBet()));

			player.setBet(player.getBet() + bet);
		}

		house.wheel.spin(player.wheel.getBall());

		cout << endl << "The house ball landed on " << house.wheel.getBall() << endl;

		if (player.wheel.getBall() > house.wheel.getBall()) {
			cout << endl << "You beat the house, and won $" << player.getBet() << endl;
			player.setMoney(player.getMoney() + player.getBet());
		}
		else {
			cout << endl << "You lost $" << player.getBet() << " to the house." << endl;
			player.setMoney(player.getMoney() - player.getBet());
		}

		player.displayMoney();

		do {
			cout << endl << "Do you wish to continue? (Enter 1 for yes, 0 for no): ";
			cin >> flag;
			cout << endl;
		} while (flag != 1 && flag != 0);

	}

}


int main() {

	int easyOrHard;

	do {
		cout << "Welcome to Roulette!" << endl << "Would you like to play on Easy or Hard difficulty? (Enter 0 for easy, 1 for hard): ";
		cin >> easyOrHard;
		cout << endl;
	} while (easyOrHard != 0 && easyOrHard != 1);
	
	if (easyOrHard == 0) easyMode();
	else hardMode();
	
	return 0;
}
