#include "pch.h"
#include "Tree.h"
#include "Word.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void processBook() {

	cout << "Enter file name: " << endl;
	string fileName;
	cin >> fileName;

	ifstream bookFile;
	bookFile.open(fileName);

	while (!bookFile.is_open()) {
		cout << endl << "ERROR: File not found. Please enter file name: " << endl;
		cin >> fileName;
		bookFile.open(fileName);
	}

	if ((bookFile.is_open())) {

		Word wordObj;
		Tree<Word> tree;
		string line;
		string fileWord;

		while (bookFile >> fileWord) {
			wordObj.word = fileWord;
			try {
				tree.insert(wordObj);
			}
			catch (ListError e) { cout << e.what() << endl; }
		}

		int choice = 0;
		Node<Word>* foundWord;
		string input;
		Node<Word>** nodes;

		while (choice != 4) {
			cout << endl;
			cout << "Enter 1 to search for a word" << endl;
			cout << "Enter 2 to see list of words (alphabetical ascending)" << endl;
			cout << "Enter 3 to see list of words (alphabetical descending)" << endl;
			cout << "Enter 4 to quit" << endl;
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1:
				cout << "Which word would you like to find?" << endl;
				cin >> input;
				wordObj.word = input;
				foundWord = tree.find(wordObj);

				if (foundWord == nullptr)
					cout << "Word not found" << endl;

				else {
					cout << endl << foundWord->data.word << "--" << foundWord->count << endl;
				}

				break;
			case 2:
				try {
					nodes = tree.getAllAscending();
					for (int i = 0; i < tree.size(); i++) {
						cout << nodes[i]->data.word << "--" << nodes[i]->count << endl;
					}
				}
				catch (ListError e) { cout << e.what() << endl; }
				break;
			case 3:
				try {
					nodes = tree.getAllDescending();
					for (int i = 0; i < tree.size(); i++) {
						cout << nodes[i]->data.word << "--" << nodes[i]->count << endl;
					}
				}
				catch (ListError e) { cout << e.what() << endl; }
				break;
			case 4:
				break;
			default:
				cout << "INVALID INPUT" << endl;

			}
		}
	}
}


int main() {

	Word tempWord;
	Tree<Word> tree;
	string input;
	Node<Word>** nodes;
	int choice = 0;
	int firstChoice = 0;

	cout << "LAB 9 --- BINARY SEARCH TREES" << endl << endl;
	cout << "Enter 1 to load a text file into a tree" << endl;
	cout << "Enter 2 to test tree functionality" << endl;
	cout << "Enter 3 to quit" << endl;
	cin >> firstChoice;
	cout << endl;
	switch (firstChoice) {
	case 1:
		processBook();
		break;
	case 2:
		while (choice != 7) {
			cout << "Enter 1 to insert" << endl;
			cout << "Enter 2 to empty tree" << endl;
			cout << "Enter 3 to remove an item" << endl;
			cout << "Enter 4 to show array values in ascending order" << endl;
			cout << "Enter 5 to show array values in descending order" << endl;
			cout << "Enter 6 to balance tree" << endl;
			cout << "Enter 7 to quit" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Enter word to insert: ";
				cin >> input;
				cout << endl;
				tempWord.word = input;
				try {
					tree.insert(tempWord);
				}
				catch (ListError e) { cout << e.what() << endl; }
				tree.display();
				break;
			case 2:
				tree.emptyTree();
				tree.display();
				break;
			case 3:
				cout << "Enter word to remove: ";
				cin >> input;
				cout << endl;
				tempWord.word = input;
				try {
					tree.remove(tempWord);
				}
				catch (ListError e) { cout << e.what() << endl; }
				tree.display();
				break;
			case 4:
				try {
					nodes = tree.getAllAscending();
					for (int i = 0; i < tree.size(); i++) {
						cout << nodes[i]->data.word << endl;
					}
				}
				catch (ListError e) { cout << e.what() << endl; }
				break;
			case 5:
				try {
					nodes = tree.getAllDescending();
					for (int i = 0; i < tree.size(); i++) {
						cout << nodes[i]->data.word << endl;
					}
				}
				catch (ListError e) { cout << e.what() << endl; }
				break;
			case 6:
				try {
					tree.balanceTree();
				}
				catch (ListError e) { cout << e.what() << endl; }
				tree.display();
				break;
			case 7:
				break;
			default:
				cout << "INVALID INPUT" << endl;
			}
		}
		break;
	case 3:
		break;
	default:
		cout << "INVALID INPUT" << endl;
	}
	return 0;
}
