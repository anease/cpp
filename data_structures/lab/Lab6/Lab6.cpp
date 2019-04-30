#include "pch.h"
#include "Stack.h"
#include "Queue.h"
#include "StackError.h"
#include <iostream>

using namespace std;

struct Move {
	char to;
	char from;
};

void towers(int num, char frompeg, char topeg, char auxpeg)
{
	if (num == 1)
	{
		cout << "Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
		return;
	}
	towers(num - 1, frompeg, auxpeg, topeg);
	cout << "Move disk " << num << " from peg " << frompeg << " to peg " << topeg << endl;
	towers(num - 1, auxpeg, topeg, frompeg);
}

void showTowers(Stack <int> A, Stack <int> B, Stack <int> C) {
	cout << "Tower A - ";
	print(A);
	cout << "Tower B - ";
	print(B);
	cout << "Tower C - ";
	print(C);
	cout << endl;
}

void moveDisk(Stack <int> &from, Stack <int> &to) {

	int* toTop = nullptr;
	if (to.length() > 0)
		toTop = to.top();
	int* fromTop = from.top();

	if (toTop == nullptr || *toTop > *fromTop) {
		to.push(from.pop());
	}

	else {
		cout << "INVALID MOVE" << endl << endl;
	}
}

int main()
{
	Queue<Move> moves;
	Move playerMove;

	int disks;
	int play = 1;

	cout << "TOWERS OF HANOI" << endl << endl;
	do {
		cout << "Would you like to play or see the solution? Play(1) Solution(0): ";
		cin >> play;
	} while (play != 1 && play != 0);

	cout << "How many disks do you want to use in the game? " << endl;
	cin >> disks;
	cout << endl;

	if (play == 0) {
		cout << "The sequence of moves involved in the Tower of Hanoi are :" << endl;
		towers(disks, 'A', 'B', 'C');
	}
	else{
		Stack <int> A(disks);
		Stack <int> B(disks);
		Stack <int> C(disks);

		//Starts games with all disks on Tower A

		for (int i = disks; i > 0; i--) {
			int* numberA = new int(i);
			A.push(numberA);
		}

		showTowers(A, B, C);

		while (play == 1) {

			char fromChoice = ' ';
			char toChoice = ' ';

			while (tolower(fromChoice) != 'a' && tolower(fromChoice) != 'b' && tolower(fromChoice) != 'c') {
				cout << "Which tower would you like to move a disk from?" << endl;
				cin >> fromChoice;
			}
			while ((tolower(fromChoice) == 'a' && A.length() == 0) || (tolower(fromChoice) == 'b' && B.length() == 0) || (tolower(fromChoice) == 'c' && C.length() == 0)) {
				cout << "There are no rings on that tower. Pick again: ";
				cin >> fromChoice;
				cout << endl;
			}

			while (tolower(toChoice) != 'a' && tolower(toChoice) != 'b' && tolower(toChoice) != 'c') {
				cout << "Which tower would you like to move the disk to?" << endl;
				cin >> toChoice;
			}

			system("cls");

			playerMove.from = toupper(fromChoice);
			playerMove.to = toupper(toChoice);
			moves.enqueue(playerMove);

			if (tolower(fromChoice) == 'a' &&  tolower(toChoice) == 'b') moveDisk(A, B);
			else if (tolower(fromChoice) == 'a' &&  tolower(toChoice) == 'c') moveDisk(A, C);
			else if (tolower(fromChoice) == 'b' &&  tolower(toChoice) == 'a') moveDisk(B, A);
			else if (tolower(fromChoice) == 'b' &&  tolower(toChoice) == 'c') moveDisk(B, C);
			else if (tolower(fromChoice) == 'c' &&  tolower(toChoice) == 'a') moveDisk(C, A);
			else if (tolower(fromChoice) == 'c' &&  tolower(toChoice) == 'b') moveDisk(C, B);

			showTowers(A, B, C);
			if (B.length() == disks) {
				cout << "CONGRATULATIONS! You Won by making the following moves: " << endl;
				while (!moves.isEmpty()) {
					cout << moves.peek().from << " to " << moves.peek().to << endl;
					moves.dequeue();
				}
				play = 0;
			}
			else {
				do {
					cout << "Would you like to keep playing? Yes (1) or No (0): ";
					cin >> play;
					cout << endl;
				} while (play != 1 && play != 0);
			}
		}
	}
}
