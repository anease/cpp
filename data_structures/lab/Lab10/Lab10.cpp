#include "pch.h"
#include "Student.h"
#include "ChainedHashTable.h"
#include "HashTable.h"
#include "ListError.h"
#include <iostream>

using namespace std;

int main() {
	HashTable<Student> table;
	ChainedHashTable<Student> chainedTable;

	int firstChoice = 0;
	int choice = 0;
	Student tempStudent;
	string output;

	int idNumber;
	string firstName;
	string lastName;
	double gpa;
	int graduationYear;
	int yearsToGraduate;
	int currentYear;

	HashTable<Student> table50;
	ChainedHashTable<Student> chainTable50(50);
	HashTable<Student> table150;
	ChainedHashTable<Student> chainTable150(150);
	HashTable<Student> table200;
	ChainedHashTable<Student> chainTable200(200);
	HashTable<Student> table250;
	ChainedHashTable<Student> chainTable250(250);

	int tableSum50 = 0;
	int chainSum50 = 0;
	int tableSum150 = 0;
	int chainSum150 = 0;
	int tableSum200 = 0;
	int tableSum250 = 0;
	int chainSum200 = 0;
	int chainSum250 = 0;

	while (firstChoice != 4) {
		std::cout << "Which table would you like to test? \n";
		std::cout << "Press 1 to test linear probing table \n";
		std::cout << "Press 2 to test chained table \n";
		std::cout << "Press 3 to perform Task 5\n";
		std::cout << "Press 4 to quit\n";
		cin >> firstChoice;
		system("cls");
		switch (firstChoice) {

		case 1:
			choice = 0;
			while (choice != 4) {
				std::cout << "What operation would you like to test? \n";
				std::cout << "Press 1 to add a student: \n";
				//cout << "Press 2 to get a student: \n";
				std::cout << "Press 2 to remove a student: \n";
				std::cout << "Press 3 to see the size of the list: \n";
				std::cout << "Press 4 to quit: \n";
				cin >> choice;
				system("cls");
				switch (choice) {
				case 1:
					try {
						std::cout << "Enter ID number \n";
						cin >> idNumber;
						std::cout << "Enter first name \n";
						cin >> firstName;
						std::cout << "Enter last name \n";
						cin >> lastName;
						std::cout << "Enter GPA \n";
						cin >> gpa;
						std::cout << "Enter graduation year \n";
						cin >> graduationYear;
						std::cout << "Enter years until graduation \n";
						cin >> yearsToGraduate;
						std::cout << "Enter current year \n";
						cin >> currentYear;
						table.addItem(new Student(idNumber, firstName, gpa, lastName, graduationYear, yearsToGraduate, currentYear));
					}
					catch (ListError e) {
						std::cout << e.what() << endl;
					}
					break;

				/*case 2:
					cout << "Enter the ID Number for student you are looking for (do not include M): \n";
					cin >> idNumber;
					tempStudent.setIDNumber(idNumber);

					if (table.getItem(&tempStudent) != nullptr) {
						output = "Found " + table.getItem(&tempStudent)->getStudentInfo();
					}
					else
						output = "Student not found";

					cout << output << endl;
					break;*/

				case 2:
					std::cout << "Enter the ID Number for student you are removing (do not include M): \n";
					cin >> idNumber;
					tempStudent.setIDNumber(idNumber);

					if (table.getItem(&tempStudent) != 0) {

						output = "Removed " + (table.removeItem(&tempStudent)->getStudentInfo());
					}
					else
						output = "Student not found";

					std::cout << output << endl;
					break;

				case 3:
					std::cout << "Items in this table: " << table.getLength() << endl;
					break;

				case 4:
					break;

				default:
					std::cout << "Invalid number \n";
					break;
				}
			}
			break;

		case 2:
			choice = 0;
			while (choice != 4) {
				std::cout << "What operation would you like to test? \n";
				std::cout << "Press 1 to add a student: \n";
				//cout << "Press 2 to get a student: \n";
				std::cout << "Press 2 to remove a student: \n";
				std::cout << "Press 3 to see the size of the list: \n";
				std::cout << "Press 4 to quit: \n";
				cin >> choice;
				system("cls");
				switch (choice) {
				case 1:
					try {
						std::cout << "Enter ID number \n";
						cin >> idNumber;
						std::cout << "Enter first name \n";
						cin >> firstName;
						std::cout << "Enter last name \n";
						cin >> lastName;
						std::cout << "Enter GPA \n";
						cin >> gpa;
						std::cout << "Enter graduation year \n";
						cin >> graduationYear;
						std::cout << "Enter years until graduation \n";
						cin >> yearsToGraduate;
						std::cout << "Enter current year \n";
						cin >> currentYear;
						chainedTable.addItem(new Student(idNumber, firstName, gpa, lastName, graduationYear, yearsToGraduate, currentYear));
					}
					catch (ListError e) {
						std::cout << e.what() << endl;
					}
					break;

				/*case 2:
					cout << "Enter the ID Number for student you are looking for (do not include M): \n";
					cin >> idNumber;
					tempStudent.setIDNumber(idNumber);

					if (chainedTable.getItem(&tempStudent) != nullptr) {
						output = "Found " + chainedTable.getItem(&tempStudent)->getStudentInfo();
					}
					else
						output = "Student not found";

					cout << output << endl;
					break;*/

				case 2:
					std::cout << "Enter the ID Number for student you are removing (do not include M): \n";
					cin >> idNumber;
					tempStudent.setIDNumber(idNumber);

					if (chainedTable.getItem(&tempStudent) != 0) {
						output = "Removed " + (chainedTable.removeItem(&tempStudent)->getStudentInfo());
					}
					else
						output = "Student not found";

					std::cout << output << endl;
					break;

				case 3:
					std::cout << "Items in this table: " << chainedTable.getLength() << endl;
					break;

				case 4:
					break;

				default:
					std::cout << "Invalid number \n";
					break;
				}
			}
			break;

		case 3:
			srand(0);
			Student* students[50];

			tableSum50 = 0;
			chainSum50 = 0;

			for (int i = 0; i < 50; i++) {
				students[i] = new Student(rand() % 30000);
				table50.addItem(students[i]);
				chainTable50.addItem(students[i]);
			}

			for (int i = 0; i < 50; i++) {
				try {
					tableSum50 += table50.getItem(students[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
				try {
					chainSum50 += chainTable50.getItem(students[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
			}

			std::cout << "50 Students[HashTable]: " << tableSum50 << endl;
			std::cout << "50 Students[ChainTable]: " << chainSum50 << endl;

			Student* students150[150];

			tableSum150 = 0;
			chainSum150 = 0;

			for (int i = 0; i < 150; i++) {
				students150[i] = new Student(rand() % 30000);
				table150.addItem(students150[i]);
				chainTable150.addItem(students150[i]);
			}

			for (int i = 0; i < 150; i++) {
				try {
					tableSum150 += table150.getItem(students150[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
				try {
					chainSum150 += chainTable150.getItem(students150[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
			}

			std::cout << "150 Students[HashTable]: " << tableSum150 << endl;
			std::cout << "150 Students[ChainTable]: " << chainSum150 << endl;

			Student* students200[200];

			tableSum200 = 0;
			chainSum200 = 0;

			for (int i = 0; i < 200; i++) {
				students200[i] = new Student(rand() % 30000);
				table200.addItem(students200[i]);
				chainTable200.addItem(students200[i]);
			}

			for (int i = 0; i < 200; i++) {
				try {
					tableSum200 += table200.getItem(students200[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
				try {
					chainSum200 += chainTable200.getItem(students200[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
			}

			std::cout << "200 Students[HashTable]: " << tableSum200 << endl;
			std::cout << "200 Students[ChainTable]: " << chainSum200 << endl;

			Student* students250[250];

			tableSum250 = 0;
			chainSum250 = 0;

			for (int i = 0; i < 250; i++) {
				students250[i] = new Student(rand() % 30000);
				table250.addItem(students250[i]);
				chainTable250.addItem(students250[i]);
			}

			for (int i = 0; i < 250; i++) {
				try {
					tableSum250 += table250.getItem(students250[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
				try {
					chainSum250 += chainTable250.getItem(students250[i]);
				}
				catch (ListError e) { std::cout << e.what() << endl; }
			}

			std::cout << "250 Students[HashTable]: " << tableSum250 << endl;
			std::cout << "250 Students[ChainTable]: " << chainSum250 << endl;

			break;

		case 4:
			break;

		default:
			std::cout << "Invalid number \n";
			break;
		}
	}
}