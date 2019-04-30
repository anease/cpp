#include "pch.h"
#include "WheelHeader.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Wheel::setValues(int bound) {
	values.clear();
	for (int i = 0; i < bound; i++) {
		values.push_back(i + 1);
	}
}

void Wheel::spin() {
	srand(time(0));
	ball = rand() % values.size() + 1;
}
