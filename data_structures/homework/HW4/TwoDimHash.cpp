#include "pch.h"
#include "TwoDimHash.h"

// Default constructor
TwoDimHash::TwoDimHash() {
	MAX_ITEMS = 500;
	MAX_ROW = MAX_ITEMS / 5;

	items = new int**[MAX_ROW]();
	for (int i = 0; i < MAX_ROW; i++) {
		items[i] = new int*[5]();
	}

	length = 0;
}


// accepts a value (integer), runs a hash function on the integer, and places it
// in the hash table.  Returns the number of spots it checks before inserting the 
// item in the hash table
int TwoDimHash::insert(int in) {
	int* inputPtr = new int(in);
	int spotsChecked = 0;

	if (length == MAX_ITEMS)
		throw ListError("Full hash table");

	else {
		int row_index = hash(in);
		int col_index = 0;
		spotsChecked++;

		while (items[row_index][col_index] != nullptr) {
			if (col_index == 4) {
				col_index = 0;
				if (row_index == (MAX_ROW - 1))
					row_index = 0;
				else
					row_index++;
			}
			else
				col_index++;

			spotsChecked++;
		}

		items[row_index][col_index] = inputPtr;
		length++;
		return spotsChecked;
	}
}

// accepts a value (integer), locates the value in the hash table and
// removes it from the hash table. Returns the number of spots it checked 
// to find the item or determine it is not in the hash table
int TwoDimHash::remove(int in) {
	int spotsChecked = 0;
	int row_index = hash(in);
	int col_index = 0;
	spotsChecked++;

	while ((items[row_index][col_index] == nullptr && spotsChecked < MAX_ITEMS )|| (spotsChecked < MAX_ITEMS && *items[row_index][col_index] != in)) {
		if (col_index == 4) {
			col_index = 0;
			if (row_index == (MAX_ROW - 1))
				row_index = 0;
			else
				row_index++;
		}
		else
			col_index++;

		spotsChecked++;
	}

	if (items[row_index][col_index] != nullptr && *items[row_index][col_index] == in) {
		delete items[row_index][col_index];
		items[row_index][col_index] = nullptr;
		length--;
		return spotsChecked;
	}

	else return 0; // meaning item not found
}

// accepts a value (integer), locates the value in the hash table and returns the
// number of spots it checked to find the item or determine it is not in the hash table
int TwoDimHash::find(int in) {
	int spotsChecked = 0;
	int row_index = hash(in);
	int col_index = 0;
	spotsChecked++;

	while (*items[row_index][col_index] != in && spotsChecked < MAX_ITEMS) {
		if (col_index == 4) {
			col_index = 0;
			if (row_index == (MAX_ROW - 1))
				row_index = 0;
			else
				row_index++;
		}
		else
			col_index++;

		spotsChecked++;
	}

	if (*items[row_index][col_index] == in) {
		return spotsChecked;
	}

	else throw ListError("Item not found");
}

// prints all items in the hash table including an indication of which spots are
// not occupied
void TwoDimHash::print() {
	for (int r = 0; r < MAX_ROW; r++) {

		cout << endl;

		for (int c = 0; c < 5; c++) {

			if (items[r][c] != nullptr) {
				cout << "[" << *items[r][c] << "] ";
			}
			else {
				cout << "[ ] ";
			}
		}
	}
}

// accepts a value(integer), and returns a calculated hash value
int TwoDimHash::hash(int in) {

	return (in * 372) % MAX_ROW;
}