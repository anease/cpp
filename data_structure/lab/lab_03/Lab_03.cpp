// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include "math.h"
#include <cmath>
#include "complexNumbers.h"

using namespace std;

int main()
{
	float response, realPart, imaginaryPart;
	string operation;
	complexNumbers CN1, CN2;
	
	do {
		do {
			cout << "Enter Form: (1 for Cartesian, 2 for polar): ";
			cin >> response;
		} while (response != 1 && response != 2);

		if (response == 1) {
			CN1.setCartOrPolar(1);
			CN2.setCartOrPolar(1);
			
			cout << "Enter Real Part: ";
			cin >> realPart;
			
			CN1.setRealOrRadius(realPart);
			
			cout << "Enter Imaginary Part: ";
			cin >> imaginaryPart;
			CN1.setImaginaryOrAngle(imaginaryPart);
			
			do {
				cout << "Enter Operation(+,-,/,*,==): ";
				cin >> operation;
			} while (operation != "+" && operation != "-" && operation != "/" && operation != "*" && operation != "==");
			
			cout << "Enter Real Part: ";
			cin >> realPart;
			
			CN2.setRealOrRadius(realPart);
			
			cout << "Enter Imaginary Part: ";
			cin >> imaginaryPart;
			
			CN2.setImaginaryOrAngle(imaginaryPart);
		}
		
		else if (response == 2) {
			CN1.setCartOrPolar(0);
			CN2.setCartOrPolar(0);
			
			cout << "Enter Radius: ";
			cin >> realPart;
			
			CN1.setRealOrRadius(realPart);
			
			cout << "Enter Angle: ";
			cin >> imaginaryPart;
			
			CN1.setImaginaryOrAngle(imaginaryPart);
			
			do {
				cout << "Enter Operation(+,-,/,*,==): ";
				cin >> operation;
			} while (operation != "+" && operation != "-" && operation != "/" && operation != "*" && operation != "==");
			
			cout << "Enter Radius: ";
			cin >> realPart;
			
			CN2.setRealOrRadius(realPart);
			
			cout << "Enter Angle: ";
			cin >> imaginaryPart;
			
			CN2.setImaginaryOrAngle(imaginaryPart);
		}

		if (operation == "+") {
			CN1 + CN2;
			CN1.printValues();
		}
		else if (operation == "-") {
			CN1 - CN2;
			CN1.printValues();
		}
		else if (operation == "*") {
			CN1 * CN2;
			CN1.printValues();
		}
		else if (operation == "/") {
			CN1 / CN2;
			CN1.printValues();
		}
		else if (operation == "==") {
			if (CN1 == CN2)
				cout << "These coordinates are equal." << endl;
			else
				cout << "These coordinates are not equal." << endl;
		}

		cout << "Do you want to continue? (1=yes,0=no): ";
		cin >> response;
		cout << endl << endl;
	} while (response != 0);

	return 0;
}