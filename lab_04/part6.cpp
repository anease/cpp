#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random_num(){
    int random_integer;
    random_integer = 1 + rand() % (6 - 1 + 1);

    return random_integer;
}


void roll_di_1(int &di_1){
    di_1 = random_num();
}


void roll_di_2(int &di_2){
    di_2 = random_num();
}


void winlose_messages(){

    int di_1 = 0, di_2 = 0;
    bool playing = true;

    while (playing == true) {

        roll_di_1(di_1);
        roll_di_2(di_2);
        int total = di_1 + di_2;

        cout << "You rolled a " << di_1 << " and a " << di_2 << " for a total of " << total << endl;

        switch (total) {

        case 2:
            cout << "Not a winner." << endl;
            playing = false;
            break;

        case 3:
            cout << "Not a winner." << endl;
            playing = false;
            break;

        case 4:
            cout << "Try again" << endl;
            playing = true;
            break;

        case 5:
            cout << "Not a winner." << endl;
            playing = false;
            break;

        case 6:
            cout << "Try again" << endl;
            playing = true;
            break;

        case 7:
            cout << "You are a winner!" << endl;
            playing = false;
            break;

        case 8:
            cout << "Try again" << endl;
            playing = true;
            break;

        case 9:
            cout << "You are a winner!" << endl;
            playing = false;
            break;

        case 10:
            cout << "Try again" << endl;
            playing = true;
            break;

        case 11:
            cout << "You are a winner!" << endl;
            playing = false;
            break;

        case 12:
            cout << "Try again" << endl;
            playing = true;
            break;
        }
    }
}


int main(){

   srand((unsigned)time(0));

   winlose_messages();

   return 0;
}
