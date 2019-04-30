#pragma once
#include "OneDimHash.h"

class TwoDimHash : public OneDimHash {
public:
	TwoDimHash();
	int insert(int);
	int remove(int);
	int find(int);
	void print();

protected:
	int*** items;
	int hash(int);
	int MAX_ROW;
};