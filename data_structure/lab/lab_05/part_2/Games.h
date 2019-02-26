#pragma once
#include <string>
using namespace std;

class Games {
public:

	Games();
	void setInstructions(string);
	Games(string, string);

	string getInstructions();
	void setResults(string);
	string getResults();
	virtual void Play();
	void Winner();

protected:

	string instructions;
	string results;
};
