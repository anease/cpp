#include "pch.h"
#include "complexNumbers.h"
#include <iostream>
#include <cmath>

using namespace std; 

complexNumbers::complexNumbers(bool cOrP_in = 0, float realOrRadius_in = 0, float imaginaryOrAngle_in = 0) {

	cartOrPolar = cOrP_in;
	realOrRadius = realOrRadius_in;
	imaginaryOrAngle = imaginaryOrAngle_in;
}

float complexNumbers::getRealOrRadius() {

	return realOrRadius;
}

float complexNumbers::getImaginaryOrAngle() {

	return imaginaryOrAngle;
}

bool complexNumbers::getCartOrPolar() {

	return cartOrPolar;
}

void complexNumbers::setCartOrPolar(bool cartOrPolar_in) {

	cartOrPolar = cartOrPolar_in;
}

void complexNumbers::setRealOrRadius(float realOrRadius_in) {

	realOrRadius = realOrRadius_in;
}

void complexNumbers::setImaginaryOrAngle(float imaginaryOrAngle_in) {

	imaginaryOrAngle = imaginaryOrAngle_in;
}

void complexNumbers::printValues() {

	if (cartOrPolar == true) {
		cout << endl << endl << "The result is: " << realOrRadius << "+" << imaginaryOrAngle << "i" << endl << endl;
	}

	else {
		cout << "Values are Polar" << endl;
		cout << "Length: " << realOrRadius << endl;
		cout << "Angle: " << imaginaryOrAngle << endl;
	}
}

void complexNumbers::operator+(complexNumbers rhs) {
	if (cartOrPolar == 1) {
		setRealOrRadius(realOrRadius + rhs.getRealOrRadius());
		setImaginaryOrAngle(imaginaryOrAngle + rhs.getImaginaryOrAngle());
	}
	else {
		float rhsTempReal = rhs.getRealOrRadius() * (cos(rhs.getImaginaryOrAngle() * 3.14156265 / 180));
		float rhsTempImaginary = rhs.getRealOrRadius() * (sin(rhs.getImaginaryOrAngle() * 3.14156265 / 180));
		float tempReal = realOrRadius * ((cos(imaginaryOrAngle * 3.14156265 / 180)));
		float tempImaginary = realOrRadius * ((sin(imaginaryOrAngle * 3.14156265 / 180)));

		float ansReal = tempReal + rhsTempReal;
		float ansImaginary = tempImaginary + rhsTempImaginary;

		setRealOrRadius(sqrt((ansReal * ansReal) + (ansImaginary * ansImaginary)));
		setImaginaryOrAngle(atan2(ansImaginary, ansReal) * 180 / 3.14156265);
	}
}

void complexNumbers::operator-(complexNumbers rhs) {
	if (cartOrPolar == 1) {
		setRealOrRadius(realOrRadius - rhs.getRealOrRadius());
		setImaginaryOrAngle(imaginaryOrAngle - rhs.getImaginaryOrAngle());
	}
	else {
		float rhsTempReal = rhs.getRealOrRadius() * (cos(rhs.getImaginaryOrAngle() * 3.14156265 / 180));
		float rhsTempImaginary = rhs.getRealOrRadius() * (sin(rhs.getImaginaryOrAngle() * 3.14156265 / 180));
		float tempReal = realOrRadius * ((cos(imaginaryOrAngle * 3.14156265 / 180)));
		float tempImaginary = realOrRadius * ((sin(imaginaryOrAngle * 3.14156265 / 180)));

		float ansReal = tempReal - rhsTempReal;
		float ansImaginary = tempImaginary - rhsTempImaginary;

		setRealOrRadius(sqrt((ansReal * ansReal) + (ansImaginary * ansImaginary)));
		setImaginaryOrAngle(atan2(ansImaginary, ansReal) * 180 / 3.14156265);
	}
}

void complexNumbers::operator*(complexNumbers rhs) {
	float temp = realOrRadius;
	if (cartOrPolar == 1) {
		setRealOrRadius(realOrRadius * rhs.getRealOrRadius() - imaginaryOrAngle * rhs.getImaginaryOrAngle());
		setImaginaryOrAngle(temp * rhs.getImaginaryOrAngle() + imaginaryOrAngle * rhs.getRealOrRadius());
	}
	else {
		setRealOrRadius(realOrRadius * rhs.getRealOrRadius());
		setImaginaryOrAngle(rhs.getImaginaryOrAngle() + imaginaryOrAngle);
	}
}

void complexNumbers::operator/(complexNumbers rhs) {
	float temp = realOrRadius;
	if (cartOrPolar == 1) {
		setRealOrRadius((realOrRadius * rhs.getRealOrRadius() - imaginaryOrAngle * -rhs.getImaginaryOrAngle()) / (rhs.getRealOrRadius() * rhs.getRealOrRadius() - rhs.getImaginaryOrAngle() * -rhs.getImaginaryOrAngle()));
		setImaginaryOrAngle((temp * -rhs.getImaginaryOrAngle() + imaginaryOrAngle * rhs.getRealOrRadius()) / (rhs.getRealOrRadius() * rhs.getRealOrRadius() - rhs.getImaginaryOrAngle() * -rhs.getImaginaryOrAngle()));
	}
	else {
		setRealOrRadius(realOrRadius / rhs.getRealOrRadius());
		setImaginaryOrAngle(imaginaryOrAngle - rhs.getImaginaryOrAngle());
	}
}

bool complexNumbers::operator==(complexNumbers rhs) {
	if (realOrRadius == rhs.getRealOrRadius() && imaginaryOrAngle == rhs.getImaginaryOrAngle())
		return true;
	else
		return false;
}