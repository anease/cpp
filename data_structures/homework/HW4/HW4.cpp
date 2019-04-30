#include "pch.h"
#include <iostream>
#include "OneDimHash.h"
#include "TwoDimHash.h"

/* Homework 4: Hashing and Unit Testing
* File: HW4.cpp
* Date: 14 April 2019
* By: Andrew Nease, James Wilfong
* neasaw, wilfonjv
* Section: 001
*
* ELECTRONIC SIGNATURE
* Andrew Nease, James V. Wilfong IV
*
* The electronic signatures above indicate the script
* submitted for evaluation is the combined effort of all
* team members and that each member of the team was an
* equal participant in its creation. In addition, each
* member of the team has a general understanding of all
* aspect of the script development and execution.
*
* A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
* Creates a hash table that uses a 1D array and linear probing to handle collisions
* Creates a hash table that uses a 2D array and linear probing to handle collisions
*/

int main() {

	srand(0);
	OneDimHash oneDimTable;
	TwoDimHash twoDimTable;
	int testArray[100];

	// running sum variables
	int oneDimInsertTest1 = 0;
	int twoDimInsertTest1 = 0;
	int oneDimInsertTest2 = 0;
	int twoDimInsertTest2 = 0;
	int oneDimRemoveTest1 = 0;
	int twoDimRemoveTest1 = 0;

	// array of 100 random, unique integers that will be used to test both hash tables
	for (int i = 0; i < 100; i++) {
		testArray[i] = rand() % 1000;
	}

	// insert first 50 values
	for (int i = 0; i < 50; i++) {
		try {
			oneDimInsertTest1 += oneDimTable.insert(testArray[i]);
		}
		catch (ListError e) { cout << e.what() << endl; }
		try {
			twoDimInsertTest1 += twoDimTable.insert(testArray[i]);
		}
		catch (ListError e) { cout << e.what() << endl; }
	}

	// Remove all the items from the hash tables where the index of the value in the
	// array % 7 == 0
	for (int i = 0; i < 100; i++) {
		if (i % 7 == 0) {
			try {
				oneDimRemoveTest1 += oneDimTable.remove(testArray[i]);
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			try {
				twoDimRemoveTest1 += twoDimTable.remove(testArray[i]);
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
		}
	}

	// insert the remaining 50 values
	for (int i = 50; i < 100; i++) {
		try {
			oneDimInsertTest2 += oneDimTable.insert(testArray[i]);
		}
		catch (ListError e) { cout << e.what() << endl; }
		try {
			twoDimInsertTest2 += twoDimTable.insert(testArray[i]);
		}
		catch (ListError e) { cout << e.what() << endl; }
	}

	// Attempt to find all the items in the hash table where the index value in the
	// array % 9 == 0 and the item wasn’t removed previously
	for (int i = 0; i < 100; i++) {
		if (i % 9 == 0 && i % 7 != 0) {
			try {
				cout << "1D Hash Find " << i << ": " << oneDimTable.find(testArray[i]) << endl;
			}
			catch (ListError e) { cout << e.what() << endl; }
			try {
				cout << "2D Hash Find " << i << ": " << twoDimTable.find(testArray[i]) << endl;
			}
			catch (ListError e) { cout << e.what() << endl; }
		}
	}

	// output running sum results
	cout << endl << "1D Insert Test One: " << oneDimInsertTest1 << endl;
	cout << "2D Insert Test One: " << twoDimInsertTest1 << endl;
	cout << "1D Remove Test One: " << oneDimRemoveTest1 << endl;
	cout << "2D Remove Test One: " << twoDimRemoveTest1 << endl;
	cout << "1D Insert Test Two: " << oneDimInsertTest2 << endl;
	cout << "2D Insert Test Two: " << twoDimInsertTest2 << endl;

	// print 1D Hash table
	cout << endl << "1D Hash Table" << endl << endl;
	oneDimTable.print();
	cout << endl;
	// print 2D Hash table
	cout << endl << "2D Hash Table" << endl;
	twoDimTable.print();

	return 0;

}
