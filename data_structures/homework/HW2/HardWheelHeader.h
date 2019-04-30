#pragma once

#include "pch.h"
#include "WheelHeader.h"

class HardWheel : public Wheel {
public:
	HardWheel() { values = { 1,2,3,4,5,6,7,8,9,10 }; ball = 1; winsInARow = 0; };
	void spin(int);
	void setOriginalValueSize(int bound) { orignialValueSize = bound; }

private:
	int winsInARow;
	int orignialValueSize;
};