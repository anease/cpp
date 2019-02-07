#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

bool playOneGame(int point);
int placeWager();

int rollDie(){
    int random_integer;
    random_integer = 1 + rand() % (6 - 1 + 1);

    return random_integer;
}

int pickNumber(){
    int numGuess;
    cout << "Enter your point value (1 - 6): ";
    cin >> numGuess;

    if (numGuess < 1 || numGuess > 6) {
        cout << "Please pick a number between 1 and 6: ";
        cin >> numGuess;
    }

    return numGuess;
}

bool wagerCheck(int account, int& bet){

    if (bet == 0) return false;
    else if (bet <= account) return true;

    else {
        cout << "Invalid wager, please try again." << endl;
        bet = placeWager();
        wagerCheck(account, bet); }
}

int placeWager(){

    int bet;

    cout << "Enter wager (0 to exit): ";
    cin >> bet;
    return bet;
}

bool playOneGame(int point){

    for (int i = 1; i <= 3; i++ ){

        int roll = rollDie();
        cout << "Roll #" << i << " is " << roll << endl;

            if (point == roll){
                cout << "** You win! **" << endl;
                return true; }

            else {
                if (i == 3 ){
                    cout << "** You Lose **" << endl;
                    return false; }
              }
       }
}

void display(int balance){

    if (balance <= 0) {
        cout << "Game over, you are out of money!" << endl;
        return; }
    cout << "Account balance: $" << balance << endl;
}

void finalDisplay(int balance){

    cout << "Your final account balance is: $" << balance << endl;
}

void stats(int win, int loss){

    float total = win + loss;
    float percent = (win / total) * 100.0;

    if (total == 0.0) percent = 0;

    cout << "You won " << win << " times out of " << total << " for a winning percentage of " << setprecision(3) << percent << "%" << endl;
}

int main(){

    srand((unsigned)time(0));

    bool win;
    bool checkWager;
    int bet;
    int win_count = 0;
    int loss_count = 0;
    int account = 100;
    int point = 3; //Arbitray number to begin while loop

    display(account);

    while ((point >= 1) && (point <= 6)) {

        bet = placeWager();
        checkWager = wagerCheck(account, bet);

        if (checkWager == true) {
            point = pickNumber();

            win = playOneGame(point);
        }

        else break;

        if (win == true) {
            account += bet;
            win_count++; }
        else if (win == false){
            account -= bet;
            loss_count++; }

        display(account);

        if (account <= 0) break;

    }

    finalDisplay(account);
    stats(win_count, loss_count);

    return 0;
}
