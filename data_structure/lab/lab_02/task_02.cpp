// This program demonstrates a two-dimensional array.
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.

	cout << "This program will calculate the total sales of\n";
	cout << "all the company's divisions.\n";
	cout << "Enter the following sales information:\n\n";

	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			cout << "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
			totalSales += sales[div][qtr];
		}
		cout << endl; // Print blank line.
	}

	string fileName;
	ofstream writeSales;

	cout << "Enter a file name for data export: ";
	cin >> fileName;

	writeSales.open(fileName, ios::app);
	
	writeSales << fixed << showpoint << setprecision(2);
	writeSales << "The sales for the company is: $" << endl;
	writeSales << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


	// Nested loops to display the quarterly sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		writeSales << div + 1 << "\t";
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			writeSales << "$" << sales[div][qtr] << "\t";
		}
		writeSales << endl; // Print blank line.
	}

	writeSales << endl;
	writeSales << "The total sales for the company are: $";
	writeSales << totalSales << endl << endl;

	writeSales.close();

	return 0;
}
