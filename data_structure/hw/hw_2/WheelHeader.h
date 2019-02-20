#pragma once

#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Wheel {
public:
	Wheel() { values = { 1,2,3,4,5,6,7,8,9,10 }; ball = 1; };
	void setValues(int);
	void spin();
	int getBall() { return ball; }

protected:
	vector <int> values;
	int ball;
};