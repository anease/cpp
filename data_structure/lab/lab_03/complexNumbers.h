#pragma once

class complexNumbers {

public:
	complexNumbers() {};
	complexNumbers(bool, float, float);

	float getRealOrRadius();
	float getImaginaryOrAngle();
	bool getCartOrPolar();
	void setCartOrPolar(bool);
	void setRealOrRadius(float);
	void setImaginaryOrAngle(float);
	void printValues();
	void operator + (complexNumbers rhs);
	void operator - (complexNumbers rhs);
	bool operator == (complexNumbers rhs);
	void operator / (complexNumbers rhs);
	void operator * (complexNumbers rhs);

private:
	bool cartOrPolar;
	float realOrRadius;
	float imaginaryOrAngle;
};