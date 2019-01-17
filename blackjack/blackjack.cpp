// FINAL PROJECT: ANDREW NEASE & LANDEN DAVIS
// BLACKJACK PROGRAM

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Blackjack{
   public:
    void playGame();

   private:
    void addDealerCard();
    void addP1Card();
    void addP2Card();
    void addP3Card();
    void addP4Card();
    void displayAccounts();
    void initializeAccounts();
    void placeWagers();
    void Deal1();
    void Deal2();
    void Deal3();
    void Deal4();
    void display1();
    void display2();
    void display3();
    void display4();
    int sum1();
    int sum2();
    int sum3();
    int sum4();
    int sumDealer();

    void dealerHit();
    void playAgain();

    void P1WinLose();
    void P2WinLose();
    void P3WinLose();
    void P4WinLose();

    void shuffleDeck();
    void checkDeck();

    int aceChoice;
    char player1Choice;
    char player2Choice;
    char player3Choice;
    char player4Choice;
    unsigned int numPlayers;
    char playAgainChoice;
    vector <int> deck;

    vector <int> dealerHand;
    vector <int> P1Hand;
    vector <int> P2Hand;
    vector <int> P3Hand;
    vector <int> P4Hand;

    vector <int> accounts;
    vector <int> bets;
};

void Blackjack::shuffleDeck(){
    deck.clear();

    for(int x = 1; x < 14; x++){
        for(int i = 0; i < 4; i++){
            deck.push_back(x);
        }
    }
}

void Blackjack::playAgain(){
    int min_account = accounts.at(0);

    for (unsigned int i = 0; i < (numPlayers); i++){
        if (accounts.at(i) < min_account) min_account = accounts.at(i);
    }

    if (min_account > 0) {
        cout << "Would you like to play another hand?" << endl << "Please enter 'y' for yes or 'n' for no: ";
        cin >> playAgainChoice;

        while ((playAgainChoice != 'y') && (playAgainChoice != 'y')) {
            cout << "Enter valid value: ";
            cin >> playAgainChoice;
        }

        cout << endl;
        P1Hand.clear();
        P2Hand.clear();
        P3Hand.clear();
        P4Hand.clear();
        dealerHand.clear();
        bets.clear();
    }

    else {
        cout << "A player's account has reached zero." << endl << "Game over." << endl;
        playAgainChoice = 'n';
    }
}

void Blackjack::P1WinLose(){
    if (sum1() > 21){
        accounts.at(0) -= bets.at(0);
    }
    else if ((sum1() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(0) += bets.at(0);
        cout << "Player 1 Wins!" << endl;
    }
    else {
        accounts.at(0) -= bets.at(0);
        cout << "Dealer Wins." << endl;
    }
    displayAccounts();
}

void Blackjack::P2WinLose(){

    if (sum1() > 21){
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }
    else if ((sum1() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(0) += bets.at(0);
        cout << "Player 1 Wins Hand!" << endl;
    }

    else {
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }


    if (sum2() > 21){
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    else if ((sum2() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(1) += bets.at(1);
        cout << "Player 2 Wins Hand!" << endl;
    }

    else {
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    displayAccounts();

}

void Blackjack::P3WinLose(){

    if (sum1() > 21){
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }
    else if ((sum1() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(0) += bets.at(0);
        cout << "Player 1 Wins Hand!" << endl;
    }

    else {
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }


    if (sum2() > 21){
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    else if ((sum2() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(1) += bets.at(1);
        cout << "Player 2 Wins Hand!" << endl;
    }

    else {
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    if (sum3() > 21){
        accounts.at(2) -= bets.at(2);
        cout << "Player 3 Loses Hand." << endl;
    }

    else if ((sum3() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(2) += bets.at(2);
        cout << "Player 3 Wins Hand!" << endl;
    }

    else {
        accounts.at(2) -= bets.at(2);
        cout << "Player 3 Loses Hand." << endl;
    }

    displayAccounts();

}

void Blackjack::P4WinLose(){

    if (sum1() > 21){
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }
    else if ((sum1() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(0) += bets.at(0);
        cout << "Player 1 Wins Hand!" << endl;
    }

    else {
        accounts.at(0) -= bets.at(0);
        cout << "Player 1 Loses Hand." << endl;
    }


    if (sum2() > 21){
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    else if ((sum2() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(1) += bets.at(1);
        cout << "Player 2 Wins Hand!" << endl;
    }

    else {
        accounts.at(1) -= bets.at(1);
        cout << "Player 2 Loses Hand." << endl;
    }

    if (sum3() > 21){
        accounts.at(2) -= bets.at(2);
        cout << "Player 3 Loses Hand." << endl;
    }

    else if ((sum3() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(2) += bets.at(2);
        cout << "Player 3 Wins Hand!" << endl;
    }

    else {
        accounts.at(2) -= bets.at(2);
        cout << "Player 3 Loses Hand." << endl;
    }

    if (sum4() > 21){
        accounts.at(3) -= bets.at(3);
        cout << "Player 4 Loses Hand." << endl;
    }

    else if ((sum4() > sumDealer()) || (sumDealer() > 21)) {
        accounts.at(3) += bets.at(3);
        cout << "Player 4 Wins Hand!" << endl;
    }

    else {
        accounts.at(3) -= bets.at(3);
        cout << "Player 4 Loses Hand." << endl;
    }

    displayAccounts();

}

void Blackjack::dealerHit(){
    addDealerCard();

    while (sumDealer() < 17){
        addDealerCard();
    }

    cout << "Dealer cards: ";

    for(int i=0; i < dealerHand.size(); i++){
        if(i != dealerHand.size() -1) cout << dealerHand.at(i) << " - " ;
        else cout << dealerHand.at(i)<<endl;
    }

        cout << "Dealer total is " << sumDealer() << "." << endl;

        if(sumDealer()>21){
            cout<<"Dealer busts: All remaining players win!"<<endl;
        }

        cout << endl;
}

int Blackjack::sumDealer(){
    int sum =0;
    for (int i=0; i<dealerHand.size(); i++){
         sum = sum + dealerHand.at(i);
    }
    return sum;
}

void Blackjack::checkDeck(){
    if (deck.size() < 26){
        shuffleDeck();
    }

    cout << "Shuffling deck..." << endl;
}

void Blackjack::addDealerCard(){
    unsigned int card;
    card = rand() % deck.size();

    int temp = deck.at(card);

    if(temp==1){
        if((sumDealer() > 5) && (sumDealer() <= 10)){
            temp =11;}

        else temp =1;
        }

    if (temp > 10) temp = 10;

    deck.erase(deck.begin()+(card-1));

    if (dealerHand.size() < 5){
        dealerHand.push_back(temp);
    }
    else cout << "Maximum number of cards (5) reached." << endl;
}

void Blackjack::addP1Card(){
    unsigned int card;
    card = rand() % deck.size();

    int temp = deck.at(card);

    if (temp > 10) temp = 10;

    if (temp == 1){

        cout << "Player 1 was dealt an ace, would you like to play ace as 11 or 1?" << endl << "Enter desired value: ";
        cin >> aceChoice;
        cout << endl;
        while (!((aceChoice == 1) || (aceChoice == 11))) {
            cout << "Enter valid value: ";
            cin >> aceChoice;
            cout << endl;
        }
        temp = aceChoice;
    }

    deck.erase(deck.begin()+(card-1));

    if (P1Hand.size() < 5){
        P1Hand.push_back(temp);
    }
    else cout << "Maximum number of cards (5) reached." << endl;
}

void Blackjack::addP2Card(){
    unsigned int card;
    card = rand() % deck.size();

    int temp = deck.at(card);

    if (temp > 10) temp = 10;

    if (temp == 1){

        cout << "Player 2 was dealt an ace, would you like to play ace as 11 or 1?" << endl << "Enter desired value: ";
        cin >> aceChoice;
        cout << endl;
        while (!((aceChoice == 1) || (aceChoice == 11))) {
            cout << "Enter valid value: ";
            cin >> aceChoice;
            cout << endl;
        }
        temp = aceChoice;
    }

    deck.erase(deck.begin()+(card-1));

    if (P2Hand.size() < 5){
        P2Hand.push_back(temp);
    }

    else cout << "Maximum number of cards (5) reached." << endl;
}

void Blackjack::addP3Card(){
    unsigned int card;
    card = rand() % deck.size();

    int temp = deck.at(card);

    if (temp > 10) temp = 10;

    if (temp == 1){

        cout << "Player 3 was dealt an ace, would you like to play ace as 11 or 1?" << endl << "Enter desired value: ";
        cin >> aceChoice;
        cout << endl;
        while (!((aceChoice == 1) || (aceChoice == 11))) {
            cout << "Enter valid value: ";
            cin >> aceChoice;
            cout << endl;
        }
        temp = aceChoice;
    }

    deck.erase(deck.begin()+(card-1));

    if (P3Hand.size() < 5){
        P3Hand.push_back(temp);
    }

    else cout << "Maximum number of cards (5) reached." << endl;
}

void Blackjack::addP4Card(){
    unsigned int card;
    card = rand() % deck.size();

    int temp = deck.at(card);

    if (temp > 10) temp = 10;

    if (temp == 1){

        cout << "Player 4 was dealt an ace, would you like to play ace as 11 or 1?" << endl << "Enter desired value: ";
        cin >> aceChoice;
        cout << endl;
        while (!((aceChoice == 1) || (aceChoice == 11))) {
            cout << "Enter valid value: ";
            cin >> aceChoice;
            cout << endl;
        }
        temp = aceChoice;
    }

    deck.erase(deck.begin()+(card-1));

    if (P4Hand.size() < 5){
        P4Hand.push_back(temp);
    }

    else cout << "Maximum number of cards (5) reached." << endl;
}

void Blackjack::displayAccounts(){
    for (unsigned int i = 0; i < numPlayers; i++){
        cout << "Player " << (i+1) << " account balance: $" << accounts.at(i) << endl;
    }
    cout << endl;
}

void Blackjack::initializeAccounts(){
    for (unsigned int i = 0; i < numPlayers; i++){
        accounts.push_back(100);
    }
}

void Blackjack::placeWagers(){
    int temp_wager;
    for (unsigned int i = 0; i < numPlayers; i++){
        cout << "Player " << (i+1) << " place a wager: ";
        cin >> temp_wager;

        while(temp_wager > accounts.at(i) || temp_wager < 0){
            cout << "Please place a valid wager: ";
            cin >> temp_wager;
        }
        bets.push_back(temp_wager);
    }
    cout << endl;
}

int Blackjack::sum1(){
    int sum =0;
    for (int i=0; i<P1Hand.size(); i++){
         sum = sum + P1Hand.at(i);
    }
    return sum;
}

int Blackjack::sum2(){
    int sum = 0;
    for (int i=0; i<P2Hand.size(); i++){
         sum = sum + P2Hand.at(i);
    }
    return sum;
}

int Blackjack::sum3(){
    int sum =0;
    for (int i=0; i<P3Hand.size(); i++){
        sum = sum + P3Hand.at(i);
    }
    return sum;
}

int Blackjack::sum4(){
    int sum =0;
    for (int i=0; i<P4Hand.size(); i++){
         sum = sum + P4Hand.at(i);
    }
    return sum;
}

void Blackjack::display1(){
    player1Choice = 'x';

    cout << endl << "Would you like to Hit(h) or Stand(s)? " << endl;
    cin >> player1Choice;

    while ((player1Choice != 'h') && (player1Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player1Choice;
    }

    cout << endl;

    while(player1Choice == 'h' ){
        addP1Card();
        cout << "Player Cards: ";

        for(int i = 0; i < P1Hand.size(); i++) {
            if(i != P1Hand.size() -1) cout<< P1Hand.at(i) << " - " ;
            else cout << P1Hand.at(i) << endl;
        }

        cout<< "Your hand total is "<< sum1()<<"." << endl << endl;

        if(sum1() == 21){cout << "Congratulations, you hit Blackjack!" << endl << endl; break; }
        if(sum1()>21){ cout << "Sorry, you busted." << endl << endl; break;}

        cout << "Would you like to Hit(h) or Stand(s)?" << endl;
        cin >> player1Choice;

        while ((player1Choice != 'h') && (player1Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player1Choice;
        }

        cout << endl;
    }
}

void Blackjack::display2(){

    player1Choice = 'x';

    cout << endl << "Would Player 1 like to Hit(h) or Stand(s)? " << endl;
    cin >> player1Choice;

    while ((player1Choice != 'h') && (player1Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player1Choice;
    }

    cout << endl;

    while(player1Choice == 'h' ){
        addP1Card();
        cout << "Player 1 Cards: ";

        for(int i = 0; i < P1Hand.size(); i++) {
            if(i != P1Hand.size() -1) cout<< P1Hand.at(i) << " - " ;
            else cout << P1Hand.at(i) << endl;
        }

        cout<< "Player 1 hand total is "<< sum1() << "." << endl << endl;

        if(sum1() == 21){cout << "Congratulations, Player 1 hit Blackjack!" << endl << endl; break; }
        if(sum1()>21){ cout << "Sorry, Player 1 busted." << endl << endl; break;}

        cout << "Would Player 1 like to Hit(h) or Stand(s)?" << endl;
        cin >> player1Choice;

        while ((player1Choice != 'h') && (player1Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player1Choice;
        }

        cout << endl;

        if(player1Choice == 's' ) break;
    }


    player2Choice = 'x';

    cout << "Would Player 2 like to Hit(h) or Stand(s)? " << endl;
    cin >> player2Choice;

    while ((player2Choice != 'h') && (player2Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player2Choice;
    }

    cout << endl;

    while(player2Choice == 'h' ){
        addP2Card();
        cout << "Player 2 Cards: ";

        for(int i = 0; i < P2Hand.size(); i++) {
            if(i != P2Hand.size() -1) cout<< P2Hand.at(i) << " - " ;
            else cout << P2Hand.at(i) << endl;
        }

        cout<< "Player 2 hand total is "<< sum2() << "." << endl << endl;

        if(sum2() == 21){cout << "Congratulations, Player 2 hit Blackjack!" << endl << endl; break; }
        if(sum2()>21){ cout << "Sorry, Player 2 busted." << endl << endl; break;}

        cout << "Would Player 2 like to Hit(h) or Stand(s)?" << endl;
        cin >> player2Choice;

        while ((player2Choice != 'h') && (player2Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player2Choice;
        }

        cout << endl;

        if(player2Choice == 's') break;
    }
}

void Blackjack::display3(){

    player1Choice = 'x';

    cout << endl << "Would Player 1 like to Hit(h) or Stand(s)? " << endl;
    cin >> player1Choice;

    while ((player1Choice != 'h') && (player1Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player1Choice;
    }

    cout << endl;

    while(player1Choice == 'h' ){
        addP1Card();
        cout << "Player 1 Cards: ";

        for(int i = 0; i < P1Hand.size(); i++) {
            if(i != P1Hand.size() -1) cout<< P1Hand.at(i) << " - " ;
            else cout << P1Hand.at(i) << endl;
        }

        cout<< "Player 1 hand total is "<< sum1() << "." << endl << endl;

        if(sum1() == 21){cout << "Congratulations, Player 1 hit Blackjack!" << endl << endl; break; }
        if(sum1()>21){ cout << "Sorry, Player 1 busted." << endl << endl; break;}

        cout << "Would Player 1 like to Hit(h) or Stand(s)?" << endl;
        cin >> player1Choice;

        while ((player1Choice != 'h') && (player1Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player1Choice;
        }

        cout << endl;

        if(player1Choice == 's' ) break;
    }


    player2Choice = 'x';

    cout << "Would Player 2 like to Hit(h) or Stand(s)? " << endl;
    cin >> player2Choice;

    while ((player2Choice != 'h') && (player2Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player2Choice;
    }

    cout << endl;

    while(player2Choice == 'h' ){
        addP2Card();
        cout << "Player 2 Cards: ";

        for(int i = 0; i < P2Hand.size(); i++) {
            if(i != P2Hand.size() -1) cout<< P2Hand.at(i) << " - " ;
            else cout << P2Hand.at(i) << endl;
        }

        cout<< "Player 2 hand total is "<< sum2() << "." << endl << endl;

        if(sum2() == 21){cout << "Congratulations, Player 2 hit Blackjack!" << endl << endl; break; }
        if(sum2()>21){ cout << "Sorry, Player 2 busted." << endl << endl; break;}

        cout << "Would Player 2 like to Hit(h) or Stand(s)?" << endl;
        cin >> player2Choice;

        while ((player2Choice != 'h') && (player2Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player2Choice;
        }

        cout << endl;

        if(player2Choice == 's') break;
    }

    player3Choice = 'x';

    cout << "Would Player 3 like to Hit(h) or Stand(s)? " << endl;
    cin >> player3Choice;

    while ((player3Choice != 'h') && (player3Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player3Choice;
    }

    cout << endl;

    while(player3Choice == 'h' ){
        addP3Card();
        cout << "Player 3 Cards: ";

        for(int i = 0; i < P3Hand.size(); i++) {
            if(i != P3Hand.size() -1) cout<< P3Hand.at(i) << " - " ;
            else cout << P3Hand.at(i) << endl;
        }

        cout<< "Player 3 hand total is "<< sum3() << "." << endl << endl;

        if(sum3() == 21){cout << "Congratulations, Player 3 hit Blackjack!" << endl << endl; break; }
        if(sum3()>21){ cout << "Sorry, Player 3 busted." << endl << endl; break;}

        cout << "Would Player 3 like to Hit(h) or Stand(s)?" << endl;
        cin >> player3Choice;

        while ((player3Choice != 'h') && (player3Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player3Choice;
        }

        cout << endl;

        if(player3Choice == 's') break;
    }
}

void Blackjack::display4(){
    player1Choice = 'x';

    cout << endl << "Would Player 1 like to Hit(h) or Stand(s)? " << endl;
    cin >> player1Choice;

    while ((player1Choice != 'h') && (player1Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player1Choice;
    }

    cout << endl;

    while(player1Choice == 'h' ){
        addP1Card();
        cout << "Player 1 Cards: ";

        for(int i = 0; i < P1Hand.size(); i++) {
            if(i != P1Hand.size() -1) cout<< P1Hand.at(i) << " - " ;
            else cout << P1Hand.at(i) << endl;
        }

        cout<< "Player 1 hand total is "<< sum1() << "." << endl << endl;

        if(sum1() == 21){cout << "Congratulations, Player 1 hit Blackjack!" << endl << endl; break; }
        if(sum1()>21){ cout << "Sorry, Player 1 busted." << endl << endl; break;}

        cout << "Would Player 1 like to Hit(h) or Stand(s)?" << endl;
        cin >> player1Choice;

        while ((player1Choice != 'h') && (player1Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player1Choice;
        }

        cout << endl;

        if(player1Choice == 's' ) break;
    }


    player2Choice = 'x';

    cout << "Would Player 2 like to Hit(h) or Stand(s)? " << endl;
    cin >> player2Choice;

    while ((player2Choice != 'h') && (player2Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player2Choice;
    }

    cout << endl;

    while(player2Choice == 'h' ){
        addP2Card();
        cout << "Player 2 Cards: ";

        for(int i = 0; i < P2Hand.size(); i++) {
            if(i != P2Hand.size() -1) cout<< P2Hand.at(i) << " - " ;
            else cout << P2Hand.at(i) << endl;
        }

        cout<< "Player 2 hand total is "<< sum2() << "." << endl << endl;

        if(sum2() == 21){cout << "Congratulations, Player 2 hit Blackjack!" << endl << endl; break; }
        if(sum2()>21){ cout << "Sorry, Player 2 busted." << endl << endl; break;}

        cout << "Would Player 2 like to Hit(h) or Stand(s)?" << endl;
        cin >> player2Choice;

        while ((player2Choice != 'h') && (player2Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player2Choice;
        }

        cout << endl;

        if(player2Choice == 's') break;
    }

    player3Choice = 'x';

    cout << "Would Player 3 like to Hit(h) or Stand(s)? " << endl;
    cin >> player3Choice;

    while ((player3Choice != 'h') && (player3Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player3Choice;
    }

    cout << endl;

    while(player3Choice == 'h' ){
        addP3Card();
        cout << "Player 3 Cards: ";

        for(int i = 0; i < P3Hand.size(); i++) {
            if(i != P3Hand.size() -1) cout<< P3Hand.at(i) << " - " ;
            else cout << P3Hand.at(i) << endl;
        }

        cout<< "Player 3 hand total is "<< sum3() << "." << endl << endl;

        if(sum3() == 21){cout << "Congratulations, Player 3 hit Blackjack!" << endl << endl; break; }
        if(sum3()>21){ cout << "Sorry, Player 3 busted." << endl << endl; break;}

        cout << "Would Player 3 like to Hit(h) or Stand(s)?" << endl;
        cin >> player3Choice;

        while ((player3Choice != 'h') && (player3Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player3Choice;
        }

        cout << endl;

        if(player3Choice == 's') break;
    }

    player4Choice = 'x';

    cout << "Would Player 4 like to Hit(h) or Stand(s)? " << endl;
    cin >> player4Choice;

    while ((player4Choice != 'h') && (player4Choice != 's')) {
        cout << "Enter valid value: ";
        cin >> player4Choice;
    }

    cout << endl;

    while(player4Choice == 'h' ){
        addP4Card();
        cout << "Player 4 Cards: ";

        for(int i = 0; i < P4Hand.size(); i++) {
            if(i != P4Hand.size() -1) cout<< P4Hand.at(i) << " - " ;
            else cout << P4Hand.at(i) << endl;
        }

        cout<< "Player 4 hand total is "<< sum4() << "." << endl << endl;

        if(sum4() == 21){cout << "Congratulations, Player 4 hit Blackjack!" << endl << endl; break; }
        if(sum4()>21){ cout << "Sorry, Player 4 busted." << endl << endl; break;}

        cout << "Would Player 4 like to Hit(h) or Stand(s)?" << endl;
        cin >> player4Choice;

        while ((player4Choice != 'h') && (player4Choice != 's')) {
            cout << "Enter valid value: ";
            cin >> player4Choice;
        }

        cout << endl;

        if(player4Choice == 's') break;
    }
}

void Blackjack::Deal1(){
    addP1Card();
    addDealerCard();
    addP1Card();
    cout << "Player 1 Cards: " << P1Hand.at(0) << " - " << P1Hand.at(1) << endl;
    cout << "Your hand total is " << sum1() << "." << endl << endl;
    cout << "Dealer showing: " << dealerHand.at(0) << endl;
}

void Blackjack::Deal2(){
    addP1Card();
    addP2Card();
    addDealerCard();
    addP1Card();
    addP2Card();
    cout<<"Player 1 Cards: " << P1Hand.at(0) << " - " << P1Hand.at(1) << endl;
    cout<<"Player 2 Cards: " << P2Hand.at(0) << " - " << P2Hand.at(1) << endl;
    cout<<"Dealer showing: " << dealerHand.at(0) << endl;
}

void Blackjack::Deal3(){
    addP1Card();
    addP2Card();
    addP3Card();
    addDealerCard();
    addP1Card();
    addP2Card();
    addP3Card();
    cout << "Player 1 Cards: " << P1Hand.at(0) << " - " << P1Hand.at(1) << endl;
    cout << "Player 2 Cards: " << P2Hand.at(0) << " - " << P2Hand.at(1) << endl;
    cout << "Player 3 Cards: " << P3Hand.at(0) << " - " << P3Hand.at(1) << endl;
    cout << "Dealer showing: " << dealerHand.at(0) << endl;
}

void Blackjack::Deal4(){
    addP1Card();
    addP2Card();
    addP3Card();
    addP4Card();
    addDealerCard();
    addP1Card();
    addP2Card();
    addP3Card();
    addP4Card();
    cout<<"Player 1 Cards: " << P1Hand.at(0) << " - " << P1Hand.at(1) << endl;
    cout<<"Player 2 Cards: " << P2Hand.at(0) << " - " << P2Hand.at(1) << endl;
    cout<<"Player 3 Cards: " << P3Hand.at(0) << " - " << P3Hand.at(1) << endl;
    cout<<"Player 4 Cards: " << P4Hand.at(0) << " - " << P4Hand.at(1) << endl;
    cout<<"Dealer showing: " << dealerHand.at(0) << endl;
}

void Blackjack::playGame(){
    cout << "Welcome to Blackjack" << endl << "By: Landen Davis and Andrew Nease" << endl << endl;
    cout << "How many players? (1 - 4 players) " << endl << "Number of players: ";
    cin >> numPlayers;

    while(numPlayers > 4|| numPlayers <1){
        cout << "Please choose a valid number of players (1 - 4 players)" << endl;
        cout << "Number of players: ";
        cin >> numPlayers;
    }

    playAgainChoice = 'y';
    cout << endl;
    initializeAccounts();

    while(playAgainChoice == 'y' ){
        shuffleDeck();
        displayAccounts();
        placeWagers();

        switch (numPlayers){

        case 1:
            Deal1();
            display1();
            dealerHit();
            P1WinLose();
            playAgain();
            break;
        case 2:
            Deal2();
            display2();
            dealerHit();
            P2WinLose();
            playAgain();
            break;
        case 3:
            Deal3();
            display3();
            dealerHit();
            P3WinLose();
            playAgain();
            break;
        case 4:
            Deal4();
            display4();
            dealerHit();
            P4WinLose();
            playAgain();
            break;
        }
    }
}

int main() {
    srand((unsigned)time(0));

    Blackjack B1;

    B1.playGame();

    return 0;
}
