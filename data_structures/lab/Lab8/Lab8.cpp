#include "pch.h"
#include "List.h"
#include "Part.h"
#include <iostream>

using namespace std;

int main()
{
	int choice = 0;
	Part newPart;
	Part* temp;
	int myPart;
	int partNumber;
	string description;
	double price;
	string measureUnits;
	int quantity;
	List<Part> list;

	while (choice != 10) {
		cout << "What would you like to try? \n";
		cout << "Press 1 to add an item: \n";
		cout << "Press 2 to get an item: \n";
		cout << "Press 3 to see if an item is in the list: \n";
		cout << "Press 4 to see if the list is empty: \n";
		cout << "Press 5 to check the size of the list: \n";
		cout << "Press 6 to see the next item after a specific location: \n";
		cout << "Press 7 to see the item at a specific location: \n";
		cout << "Press 8 to reset the see next function: \n";
		cout << "Press 9 to see a list: \n";
		cout << "Press 10 to quit: \n";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			cout << "Enter part number \n";
			cin >> partNumber;
			cout << "Enter description \n";
			cin >> description;
			cout << "Enter price \n";
			cin >> price;
			cout << "Enter units of measurements \n";
			cin >> measureUnits;
			cout << "Enter quantity \n";
			cin >> quantity;
			list.addItem(new Part(partNumber, description, price, measureUnits, quantity));
			break;
		case 2:
			cout << "What would you like to look for? \n";
			cin >> myPart;
			newPart.setPartNumber(myPart);
			temp = list.getItem(&newPart);
			if (temp != nullptr)
				cout << temp->getPartInfo() << endl;
			else
				cout << "That item was not found" << endl;
			break;
		case 3:
			cout << "What would you like to check for? \n";
			cin >> myPart;
			newPart.setPartNumber(myPart);
			cout << list.isInTheList(&newPart) << endl;
			break;
		case 4:
			cout << list.isEmpty() << endl;
			break;
		case 5:
			cout << list.size() << endl;
			break;
		case 6:
			try {
				temp = list.seeNext();
				if (temp != nullptr)
					cout << temp->getPartInfo() << endl;
				else
					cout << "You have reached the end of the list" << endl;
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			break;
		case 7:
			cout << "What location would you like to see? \n";
			cin >> myPart;
			try {
				cout << (list.seeAt(myPart))->getPartInfo() << endl;
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			break;
		case 8:
			list.reset();
			break;
		case 9:
			try {
				displayList(list);
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			break;
		case 10:
			break;
		default:
			cout << "Invalid number \n";
			break;
		}
	}
}
