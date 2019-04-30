#pragma once
#include <string>

using namespace std;

class Word {
public:
	Word() {
		word = "";
	}

	Word(string in) {
		word = in;
	}

	string word;

	bool operator<(const Word&);
	bool operator>(const Word&);
	bool operator==(const Word&);
	bool operator!=(const Word&);

};

bool Word::operator<(const Word& rhs) {

	string smallerWord;

	if (word.length() > rhs.word.length()) smallerWord = rhs.word;
	else smallerWord = word;

	for (int i = 0; i < smallerWord.size(); i++) {
		if (tolower(word[i]) < tolower(rhs.word[i]))
			return true;
		else if (tolower(word[i]) > tolower(rhs.word[i]))
			return false;
	}

	return false;
}

bool Word::operator>(const Word& rhs) {

	string smallerWord;

	if (word.length() > rhs.word.length()) smallerWord = rhs.word;
	else smallerWord = word;

	for (int i = 0; i < smallerWord.size(); i++) {
		if (tolower(word[i]) > tolower(rhs.word[i]))
			return true;
		else if (tolower(word[i]) < tolower(rhs.word[i]))
			return false;
	}

	return false;
}

bool Word::operator==(const Word& rhs) {

	if (word.length() != rhs.word.length()) return false;

	for (int i = 0; i < word.length(); i++) {
		if (tolower(word[i]) < tolower(rhs.word[i]) || tolower(word[i]) > tolower(rhs.word[i]))
			return false;
	}

	return true;
}

bool Word::operator!=(const Word& rhs) {

	if (word.length() != rhs.word.length()) return true;

	for (int i = 0; i < word.length(); i++) {
		if (tolower(word[i]) != tolower(rhs.word[i]))
			return true;
	}

	return false;
}
