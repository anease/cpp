#include "pch.h"
#include "Games.h"
#include <iostream>
#include <string>


using namespace std;

Games::Games() {
	instructions = " ";
	results = "Not Yet";
}

Games::Games(string instructions_in, string results_in) {
	instructions = instructions_in;
	results = results_in;
}

void Games::setInstructions(string instructions_in) {
	instructions = instructions_in;
}

void Games::setResults(string results_in) {
	results = results_in;
}

string Games::getInstructions() {
	return instructions;
}

string Games::getResults() {
	return results;
}

void Games::Play() {
	cout << instructions << endl;
}

void Games::Winner() {
	cout << results << endl;
}