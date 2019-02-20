#pragma once

#include "pch.h"
#include "WheelHeader.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Player {
public:
	Player() { money = 200; bet = 10; }
	int getMoney() { return money; }
	void setMoney(int moneyIn) { money = moneyIn; }
	void displayMoney() { cout << "Account Balance: $" << money << endl; }
	int getBet() { return bet; }
	void setBet(int betIn) { bet = betIn; }
	Wheel wheel;

protected:
	int money;
	int bet;
};