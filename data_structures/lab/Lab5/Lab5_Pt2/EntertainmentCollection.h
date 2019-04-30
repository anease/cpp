#pragma once

template <class T>

class EntertainmentCollection {
public:

	EntertainmentCollection() { top = 0; };
	const static int MAX_SIZE = 10;
	void pushBack(T);
	T popBack();
	int sizeOf();


private:

	T gameShelf[MAX_SIZE];
	int top;

};
