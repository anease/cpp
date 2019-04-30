#pragma once
#include <string>
#include <iostream>

using namespace std;

class Part {
private:
	int partNumber;
	string description;
	double price;
	string measureUnits;
	int quantity;
	int leadTime;
	int currentDate;
public:
	Part(int, string, double, string, int, int, int);
	string getPartInfo();
	double getPrice();
	bool inStock();
	bool available(int);
	void setPartNumber(int);
	void setDescription(string);
	void setPrice(double);
	void setMeasureUnits(string);
	void setQuantity(int);
	void setLeadTime(int);
	void setCurrentDate(int);
	//operator overloads
	bool operator<(const Part&);
	bool operator>(const Part&);
	bool operator==(const Part&);
	bool operator!=(const Part&);
	void seeInfo();
	~Part() {}
};

Part::Part(int in_partNumber = 0, string in_description = "None", double in_price = 0, string in_measureUnits = "None", int in_quantity = 0, int in_leadTime = 0, int in_currentDate = 0) {
	partNumber = in_partNumber;
	description = in_description;
	price = in_price;
	measureUnits = in_measureUnits;
	quantity = in_quantity;
	leadTime = in_leadTime;
	currentDate = in_currentDate;
}

string Part::getPartInfo() {
	return to_string(partNumber) + " " + description;
}

double Part::getPrice() {
	return price;
}

bool Part::inStock() {
	if (quantity > 0)
		return true;
	else
		return false;
}

bool Part::available(int in) {
	if (quantity > 0)
		return true;
	else
		return in > currentDate + leadTime;
}

void Part::setPartNumber(int in_partNumber) {
	partNumber = in_partNumber;
}

void Part::setDescription(string in_description) {
	description = in_description;
}

void Part::setPrice(double in_price) {
	price = in_price;
}

void Part::setMeasureUnits(string in_measureUnits) {
	measureUnits = in_measureUnits;
}

void Part::setQuantity(int in_quantity) {
	quantity = in_quantity;
}

void Part::setLeadTime(int in_leadTime) {
	leadTime = in_leadTime;
}

void Part::setCurrentDate(int in_currentDate) {
	currentDate = in_currentDate;
}

bool Part::operator<(const Part& in) {
	return partNumber < in.partNumber;
}

bool Part::operator>(const Part& in) {
	return partNumber > in.partNumber;
}

bool Part::operator==(const Part& in) {
	return partNumber == in.partNumber;
}

bool Part::operator!=(const Part& in) {
	return partNumber != in.partNumber;
}

void Part::seeInfo() {
	cout << "Part Number:" << partNumber << endl;
	cout << "Part Price: " << price << endl;
	cout << "Part Quantity: " << quantity << endl;
	cout << "Part Description: " << description << endl;
	cout << "Part Units of Measurement: " << measureUnits << endl << endl;
}
