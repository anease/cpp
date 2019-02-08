#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void fillVector(vector <float> &fill) {

    int highRange, lowRange;

    cout << "Enter lower bound: ";
    cin >> lowRange;
    cout << "Enter upper bound: ";
    cin >> highRange;

    for (unsigned int i = 0; i < fill.size(); ++i){
        fill.at(i) = lowRange + ( rand() % ( highRange - lowRange + 1 ) );
    }
}


void displayVector(vector <float> dispVector) {

    cout << "{";

    for (unsigned int i = 0; i < dispVector.size(); ++i){

        if (i == (dispVector.size() - 1)){
            cout << dispVector.at(i);
            break; }

        cout << dispVector.at(i) << ", "; }

    cout << "}" << endl;
}


double sumVector(vector <float> vector){

    double sum = 0.0;

    for (unsigned int i = 0; i < vector.size(); ++i){
        sum = vector.at(i) + sum;
    }
    return sum;
}


int main(){

    srand((unsigned)time(0));

    unsigned int vectorSize;
    cout << "Enter vector size: ";
    cin >> vectorSize;

    vector <float> testVector(vectorSize);

    fillVector(testVector);
    displayVector(testVector);
    double sum = sumVector(testVector);

    cout << "Sum of vector entries: " << sum << endl;

    return 0;
}
