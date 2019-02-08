
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	string fileName;
	cout << "File Name: " << endl;
	cin >> fileName;
	file.open(fileName, ios::in);

	while (!file.is_open()) {
		cout << "ERROR: File not found. Please enter file name: " << endl;
		cin >> fileName;
		file.open(fileName);
	}

	int lineCount = 0;
	string line;

	while (lineCount < 10 && !file.eof()) {
		getline(file, line);
		cout << line << endl;
		lineCount++;
	}
	file.close();
}

