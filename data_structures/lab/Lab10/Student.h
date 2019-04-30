#pragma once
#include "ListError.h"
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
	int idNumber;
	string firstName;
	double gpa;
	string lastName;
	int graduationYear;
	int yearsToGraduate;
	int currentYear;
public:
	Student(int, string, double, string, int, int, int);
	string getStudentInfo();
	double getGPA();
	int getID();
	bool isGraduating();
	bool graduated(int);
	void setIDNumber(int);
	void setFirstName(string);
	void setGPA(double);
	void setLastName(string);
	void setGraduationYear(int);
	void setYearsToGraduate(int);
	void setCurrentYear(int);
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

Student::Student(int in_idNumber = 0, string in_firstName = "None", double in_gpa = 0, string in_lastName = "None", int in_graduationYear = 0, int in_yearsToGraduate = 0, int in_currentYear = 0) {

	idNumber = in_idNumber;
	firstName = in_firstName;
	gpa = in_gpa;
	lastName = in_lastName;
	graduationYear = in_graduationYear;
	yearsToGraduate = in_yearsToGraduate;
	currentYear = in_currentYear;
}

string Student::getStudentInfo() {
	return to_string(idNumber) + " " + firstName + " " + lastName;
}

double Student::getGPA() {
	return gpa;
}

int Student::getID() {
	return idNumber;
}

bool Student::isGraduating() {
	if (graduationYear > 2018)
		return true;
	else
		return false;
}

bool Student::graduated(int in) {
	if (graduationYear > 2017)
		return true;
	else
		return in > currentYear + yearsToGraduate;
}

void Student::setIDNumber(int in_idNumber) {
	idNumber = in_idNumber;
}

void Student::setFirstName(string in_firstName) {
	firstName = in_firstName;
}

void Student::setGPA(double in_gpa) {
	gpa = in_gpa;
}

void Student::setLastName(string in_lastName) {
	lastName = in_lastName;
}

void Student::setGraduationYear(int in_graduationYear) {
	graduationYear = in_graduationYear;
}

void Student::setYearsToGraduate(int in_yearsToGraduate) {
	yearsToGraduate = in_yearsToGraduate;
}

void Student::setCurrentYear(int in_currentYear) {
	currentYear = in_currentYear;
}

void Student::operator=(const Student* in) {
	this->idNumber = in->idNumber;
	this->firstName = in->firstName;
	this->gpa = in->gpa;
	this->lastName = in->lastName;
	this->graduationYear = in->graduationYear;
	this->yearsToGraduate = in->yearsToGraduate;
	this->currentYear = in->currentYear;
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
	cout << "GPA: " << gpa << endl;
	cout << "Graduation Year: " << graduationYear << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl << endl;
}