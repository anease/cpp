#pragma once
#include "ListError.h"
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
	int idNumber;
	string firstName;
	string lastName;

public:
	Student(int, string, string);
	string getStudentInfo();
	int getID();
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	void setIDNumber(int);
	void setFirstName(string);
	void setLastName(string);

	//operator overloads
	void operator=(const Student*);
	bool operator<(const Student&);
	bool operator>(const Student&);
	bool operator==(const Student&);
	bool operator!=(const Student&);
	operator string();
	void seeInfo();
	~Student() {}
};

Student::operator string() {
	string number = to_string(idNumber);
	while (number.length() < 8) {
		number = "0" + number;
	}
	string temp = "M" + number;
	return temp;
}

Student::Student(int in_idNumber = 0, string in_firstName = "None", string in_lastName = "None") {
	idNumber = in_idNumber;
	firstName = in_firstName;
	lastName = in_lastName;
}

string Student::getStudentInfo() {
	string number = to_string(idNumber);
	while (number.length() < 8) {
		number = "0" + number;
	}
	string mNum = "M" + number;

	return mNum + " " + firstName + " " + lastName;
}

int Student::getID() {
	return idNumber;
}

void Student::setIDNumber(int in_idNumber) {
	idNumber = in_idNumber;
}

void Student::setFirstName(string in_firstName) {
	firstName = in_firstName;
}

void Student::setLastName(string in_lastName) {
	lastName = in_lastName;
}

void Student::operator=(const Student* in) {
	this->idNumber = in->idNumber;
	this->firstName = in->firstName;
	this->lastName = in->lastName;
}

bool Student::operator<(const Student& in) {
	return idNumber < in.idNumber;
}

bool Student::operator>(const Student& in) {
	return idNumber > in.idNumber;
}

bool Student::operator==(const Student& in) {
	return idNumber == in.idNumber;
}

bool Student::operator!=(const Student& in) {
	return idNumber != in.idNumber;
}

void Student::seeInfo() {
	cout << "IDNumber:" << idNumber << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl << endl;
}