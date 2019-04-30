#include "pch.h"
#include "HardWheelHeader.h"
#include <ctime>
#include <iostream>
#include <vector>

void HardWheel::spin(int playerResult) {

	srand(unsigned(time(0)));
	ball = rand() % values.size() + 1;

	if (playerResult > ball) {
		winsInARow = 0;

		cout << endl << "Increasing range on house wheel..." << endl;

		values.push_back(values.size() + 1);

	}

	else {
		winsInARow += 1;

		if (winsInARow >= 2) {
			cout << endl << "Decreasing range on house wheel..." << endl;
			
			if (values.size() > orignialValueSize) {
				values.pop_back();

			}
		}
	}
}