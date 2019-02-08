#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>

using namespace std;

bool yesOrNo(string prompt){
    char answer = 'Y';

    cout << prompt;
    cin >> answer;

    if(answer == 'N' || answer == 'n')
        return false;

    return true;
}

class latteGame {

public:

    latteGame() {
        games_won = 0;
        games_lost = 0;
    }

private:

    void printMaze(int playerX, int playerY) {
        system("cls");
        char maze[20][20];

        for(int i = 0; i < 20; i++) {

            for(int j = 0; j < 20; j++) {
            maze[i][j] = '?'; }
        }

        maze[playerX][playerY] = 'P';

        for(int i = 0; i < 20; i++) {

            for(int j = 0; j < 20; j++) {
            cout << maze[i][j] << ' '; }

        cout << endl;
        }
    }


    void randomPosition(int& x, int& y) {
        x = rand() % 21;
        y = rand() % 21;
    }


    void checkDups(int& pX, int& pY, int& lX, int& lY, int& mX, int& mY, int& cX, int& cY) {

        while(pX == lX && pY == lY) randomPosition(lX, lY);
        while(pX == mX && pY == mY) randomPosition(mX, mY);
        while(pX == cX && pY == cY) randomPosition(cX, cY);

        while(lX == pX && lY == pY) randomPosition(pX, pY);
        while(lX == mX && lY == mY) randomPosition(mX, mY);
        while(lX == cX && lY == cY) randomPosition(cX, cY);

        while(mX == lX && mY == lY) randomPosition(lX, lY);
        while(mX == pX && mY == pY) randomPosition(pX, pY);
        while(mX == cX && mY == cY) randomPosition(cX, cY);

        while(cX == lX && cY == lY) randomPosition(lX, lY);
        while(cX == mX && cY == mY) randomPosition(mX, mY);
        while(cX == pX && cY == pY) randomPosition(pX, pY);
    }


    bool playOneGame(int& numSteps) {

        int playerX = 0;
        int playerY = 0;
        int latteX = 0;
        int latteY = 0;
        int monsterX = 0;
        int monsterY = 0;
        int coffeeX = 0;
        int coffeeY = 0;
        int coffeeX2 = 0;
        int coffeeY2 = 0;
        int coffeeX3 = 0;
        int coffeeY3 = 0;
        int coffeeX4 = 0;
        int coffeeY4 = 0;
        int coffeeX5 = 0;
        int coffeeY5 = 0;
        int coffeeX6 = 0;
        int coffeeY6 = 0;

        randomPosition(playerX, playerY);
        randomPosition(latteX, latteY);
        randomPosition(monsterX, monsterY);
        randomPosition(coffeeX, coffeeY);
        randomPosition(coffeeX2, coffeeY2);
        randomPosition(coffeeX3, coffeeY3);
        randomPosition(coffeeX4, coffeeY4);
        randomPosition(coffeeX5, coffeeY5);
        randomPosition(coffeeX6, coffeeY6);

        checkDups(playerX, playerY, latteX, latteY, monsterX, monsterY, coffeeX, coffeeY);
        checkDups(playerX, playerY, coffeeX2, coffeeY2, coffeeX3, coffeeY3, coffeeX4, coffeeY4);
        checkDups(playerX, playerY, coffeeX5, coffeeY5, coffeeX6, coffeeY6, coffeeX, coffeeY);

        int play = 1;
        printMaze(playerX, playerY);

        while(play == 1) {

            char choice = getch();

            if (choice == 'w') {
                if (playerY > 0)  playerY--; numSteps++; }

            else if (choice == 'e') {
                if (playerY < 19) playerY++; numSteps++; }

            else if (choice == 'n') {
                if (playerX > 0)  playerX--; numSteps++; }

            else if(choice == 's') {
                if(playerX < 19)  playerX++; numSteps++; }

            printMaze(playerX, playerY);

            if (playerX == monsterX && playerY == monsterY) {

                cout << "You found coffee monster!!!" << endl;
                randomPosition(playerX, playerY);
                printMaze(playerX, playerY);
            }

            else if (playerX == coffeeX && playerY == coffeeY) {

                cout << "You found Speedway coffee." << endl;
                return false;
            }

            else if (playerX == latteX && playerY == latteY) {

                cout << "You found the Pumpkin Spice Latte!!!" << endl;
                return true;
            }


            if(playerX > latteX){
                cout << "Go North" << endl; }

            else if(playerX < latteX){
                cout << "Go South" << endl; }

        }
    }

    void displayStats() {
            cout << "Games Won: " << games_won << endl;
            cout << "Games Lost: " << games_lost << endl;
         }

    int games_won;
    int games_lost;

    public:

        void playGame() {

            while(yesOrNo("Do you want to find a Pumpkin Spice Latte? (y or n) ")) {
                int numSteps = 0;

                bool outcome = playOneGame(numSteps);

                cout << "Steps taken: " << numSteps << endl;

                if(outcome) games_won++;
                else games_lost++;
            }
            displayStats();
        }
};


int main() {

    srand(time(NULL));

    latteGame game;

    game.playGame();

return 0;
}
