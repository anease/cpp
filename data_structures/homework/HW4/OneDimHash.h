#pragma once
#include "ListError.h"
#include <string>
#include <iostream>

using namespace std;

class OneDimHash {
public:
	OneDimHash();
	int insert(int);
	int remove(int);
	int find(int);
	void print();
	int getLength() { return length; }
	~OneDimHash() { delete items; }

protected:
	int hash(int);
	int MAX_ITEMS;
	int length;
	int** items;
};