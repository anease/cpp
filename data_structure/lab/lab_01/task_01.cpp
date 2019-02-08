// This program produces a sales report for DLC, Inc.
#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;


struct Products {
	int id;
	int units;
	double prices;
	double sales;
};

// Function prototypes
void calcSales(Products[]);
void showOrder(Products[]);
void dualSort(Products[]);
void showTotals(Products[]);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main()
{
	Products products[NUM_PRODS];
	
	// Array with product ID numbers
	int id[NUM_PRODS] = { 914, 915, 916, 917, 918, 919, 920,
						 921, 922 };

	// Array with number of units sold for each product
	int units[NUM_PRODS] = { 842, 416, 127, 514, 437, 269, 97,
							492, 212 };

	// Array with product prices
	double prices[NUM_PRODS] = { 12.95, 14.95, 18.95, 16.95, 21.95,
								31.95, 14.95, 14.95, 16.95 };

	// Array to hold the computed sales amounts
	double sales[NUM_PRODS];

	for (int i = 0; i < NUM_PRODS; i++) {
		products[i].id = id[i];
		products[i].units = units[i];
		products[i].prices = prices[i];
		products[i].sales = sales[i];
	}

	// Calculate each product's sales.
	calcSales(products);

	// Sort the elements in the sales array in descending
	// order and shuffle the ID numbers in the id array to
	// keep them in parallel.
	dualSort(products);

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	showOrder(products);

	// Display total units sold and total sales.
	showTotals(products);

	return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(Products products[])
{
	for (int i = 0; i < NUM_PRODS; i++)
		products[i].sales = products[i].units * products[i].prices;
}


//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(Products products[])
{
	int startScan, maxIndex, tempid;
	double maxValue;

	for (startScan = 0; startScan < (NUM_PRODS - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = products[startScan].sales;
		tempid = products[startScan].id;
		for (int index = startScan + 1; index < NUM_PRODS; index++)
		{
			if (products[index].sales > maxValue)
			{
				maxValue = products[index].sales;
				tempid = products[index].id;
				maxIndex = index;
			}
		}
		products[maxIndex].sales = products[startScan].sales;
		products[maxIndex].id = products[startScan].id;
		products[startScan].sales = maxValue;
		products[startScan].id = tempid;
	}
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(Products products[])
{
	cout << "Product Number\tSales\n";
	cout << "----------------------------------\n";
	for (int index = 0; index < NUM_PRODS; index++)
	{
		cout << products[index].id << "\t\t$";
		cout << setw(8) << products[index].sales << endl;
	}
	cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(Products products[])
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < NUM_PRODS; index++)
	{
		totalUnits += products[index].units;
		totalSales += products[index].sales;
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;
}
