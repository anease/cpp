#include "pch.h"
#include "OneDimHash.h"

// Default constructor
OneDimHash::OneDimHash() {
	MAX_ITEMS = 500;
	items = new int*[MAX_ITEMS]();
	length = 0;
}

// accepts a value (integer), runs a hash function on the integer, and places it
// in the hash table.  Returns the number of spots it checks before inserting the 
// item in the hash table
int OneDimHash::insert(int in) {
	int* inputPtr = new int(in);
	int spotsChecked = 0;

	if (length == MAX_ITEMS)
		throw ListError("Full hash table");

	else {
		int index = hash(in);
		spotsChecked++;

		while (items[index] != nullptr) {
			if (index == (MAX_ITEMS - 1))
				index = 0;
			else
				index++;

			spotsChecked++;
		}

		items[index] = inputPtr;
		length++;
		return spotsChecked;
	}
}

// accepts a value (integer), locates the value in the hash table and
// removes it from the hash table. Returns the number of spots it checked 
// to find the item or determine it is not in the hash table
int OneDimHash::remove(int in) {
	int spotsChecked = 0;
	int index = hash(in);
	spotsChecked++;
	while ((items[index] == nullptr && spotsChecked < MAX_ITEMS) || (spotsChecked < MAX_ITEMS && *items[index] != in)) {
		if (index == MAX_ITEMS - 1)
			index = 0;
		else
			index = index + 1;
		spotsChecked++;
	}

	if (items[index] != nullptr && *items[index] == in) {
		delete items[index];
		items[index] = nullptr;
		length--;
		return spotsChecked;
	}

	else return 0; //meaning item not found
}

// accepts a value (integer), locates the value in the hash table and returns the
// number of spots it checked to find the item or determine it is not in the hash table
int OneDimHash::find(int in) {
	int spotsChecked = 0;
	int index = hash(in);
	spotsChecked++;

	while (*items[index] != in && spotsChecked < MAX_ITEMS) {
		if (index == MAX_ITEMS - 1)
			index = 0;
		else
			index = index + 1;
		spotsChecked++;
	}

	if (*items[index] == in) return spotsChecked;

	else throw ListError("Item not found");
}

// accepts a value(integer), and returns a calculated hash value
int OneDimHash::hash(int in) {

	return (in * 372) % MAX_ITEMS;
}

// prints all items in the hash table including an indication of which spots are
// not occupied
void OneDimHash::print() {

	for (int i = 0; i < MAX_ITEMS; i++) {

		if (items[i] != nullptr) {
			cout << "[" << *items[i] << "] ";
		}

		else {
			cout << "[ ] ";
		}
	}
}