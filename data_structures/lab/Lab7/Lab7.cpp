#include "pch.h"
#include "EndList.h"
#include "BlankSpotList.h"
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	List<int> aList;
	EndList<int> endList;
	BlankSpotList<int> bsList;
	int decision;
	int count = 0;

	while (count < 100) {
		int addNum = 0;
		int subNum = 0;

		aList.makeEmpty();
		endList.makeEmpty();
		bsList.makeEmpty();

		while (addNum < 30 || subNum < 25) {
			decision = rand() % 2;

			if (decision == 0 && addNum < 30) {
				try {
					aList.addItem(new int(rand() % 39 + 25));
				}
				catch (ListError e) {
				}
				try {
					endList.addItem(new int(rand() % 39 + 25));
				}
				catch (ListError e) {
				}
				try {
					bsList.addItem(new int(rand() % 39 + 25));
				}
				catch (ListError e) {
				}
				addNum++;
			}
			if (decision == 1 && subNum < 25) {

				try {
					aList.removeItem(rand() % MAX_ITEMS);
				}
				catch (ListError e) {
				}
				try {
					endList.removeItem(rand() % MAX_ITEMS);
				}
				catch (ListError e) {
				}
				try {
					bsList.removeItem(rand() % MAX_ITEMS);
				}
				catch (ListError e) {
				}
				subNum++;
			}
		}
		count = count + 1;
	}

	cout << "\tCounts after 100 runs: (Array size " << MAX_ITEMS << ")\n\n";
	cout << "Base Class:\n";
	cout << "Operations Performed by Add method: " << aList.getAddCount() << endl;
	cout << "Operations Performed by Remove method: " << aList.getSubCount() << endl;
	cout << "Total Operations Performed: " << aList.getAddCount() + aList.getSubCount() << endl << endl;
	cout << "Derived Class1:\n";
	cout << "Operations Performed by Add method: " << endList.getAddCount() << endl;
	cout << "Operations Performed by Remove method: " << endList.getSubCount() << endl;
	cout << "Total Operations Performed: " << endList.getAddCount() + endList.getSubCount() << endl << endl;
	cout << "Derived Class2:\n";
	cout << "Operations Performed by Add method: " << bsList.getAddCount() << endl;
	cout << "Operations Performed by Remove method: " << bsList.getSubCount() << endl;
	cout << "Total Operations Performed: " << bsList.getAddCount() + bsList.getSubCount() << endl;

	/*int ctr = 1;
	int response = 0;
	int response2;
	while (response != 8) {

		cout << "1 to add item\n";
		cout << "2 to remove item\n";
		cout << "3 to make empty\n";
		cout << "4 to display\n";
		cout << "5 isEmpty\n";
		cout << "6 isFull\n";
		cout << "7 printList\n";
		cout << "8 quit\n\n";
		cout << "Choice: ";
		cin >> response;
		system("cls");

		switch (response) {
		case 1:
			try {
				bsList.addItem(new int(ctr));
				ctr++;
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			printList(bsList);
			break;
		case 2:
			do {
				cout << "Index(0-19): ";
				cin >> response2;
			} while (response2 < 0 || response2 > 19);
			try {
				bsList.removeItem(response2);
			}
			catch (ListError e) {
				cout << e.what() << endl;
			}
			printList(bsList);
			break;
		case 3:
			bsList.makeEmpty();
			printList(bsList);
			break;
		case 4:
			bsList.printResults();
			break;
		case 5:
			cout << bsList.isEmpty() << endl;
			break;
		case 6:
			cout << bsList.isFull() << endl;
			break;
		case 7:
			printList(bsList);
			break;
		case 8:
			break;
		default:
			cout << "INVALID INPUT" << endl;
			break;
		}
	}*/
}
