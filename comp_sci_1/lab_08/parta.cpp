#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>


using namespace std;


int randNum(int highRange, int lowRange) {

    int random;
    random = lowRange + ( rand() % ( highRange - lowRange + 1 ) );

    return random;
}


void frequency(vector <int> &numFreq, int random, int lowRange) {

    numFreq.at(random - lowRange)+= 1;
}


float mean(const vector <int> values) {
    if (values.size() == 0 ) return 0;

    float sum = 0;

    for (unsigned int i = 0; i < values.size(); i++) {
        sum = sum +  values.at(i);
    }

    float mean = (sum / values.size());
    return mean;
}


float sum(const vector <int> values) {
    float sum = 0;

    for (unsigned int i = 0; i < values.size(); i++) {
        sum = sum +  values.at(i);
    }
    return sum;
}


int max(const vector <int> values) {
    int max = values.at(0);

    for (unsigned int i = 0; i < values.size(); i++) {

        if (values.at(i) > max) {
            max = values.at(i);
        }
    }
    return max;
}


int min(const vector <int> values) {
    int min = values.at(0);

    for (unsigned int i = 0; i < values.size(); i++) {

        if (values.at(i) < min) {
            min = values.at(i);
        }
    }
    return min;
}


float stdDev(const vector <int> values) {
    if (values.size() == 0 ) return 0;

    float m = mean(values);
    float sum = 0;
    float diff = 0;
    float m2;
    int size =  values.size();

    for (unsigned int i = 0; i < size; ++i) {
        diff  = values.at(i) - m;
        diff = diff*diff;
        sum = sum + diff;
    }

    m2 = sum / size;

    return sqrt(m2);
}


void displayStats(vector <int> numFreq) {

    cout << endl;
    cout << "Sum: " << sum(numFreq) << endl;
    cout << "Standard Deviation: " << stdDev(numFreq) << endl;
    cout << "Average: " << mean(numFreq) << endl;
    cout << "Maximum: " << max(numFreq) << endl;
    cout << "Minimum: " << min(numFreq) << endl;
}


void freqDisplay(vector <int> numFreq, int lowRange) {

    cout << endl;
    cout << setw(10) << left << "Value" ;
    cout << setw(5) << left << "|" ;
    cout << setw(8) << left << "Frequency";
    cout << setw(4) << right << "|" ;
    cout << setw(7) << right << "Bar";
    cout << endl;

    for (unsigned int i = 0; i < numFreq.size(); ++i) {
        cout << setw(10) << left << (i + lowRange);
        cout << setw(5) << left << "|" ;
        cout << setw(8) << left << numFreq.at(i);
        cout << setw(5) << right << "|" << "    ";

        if (max(numFreq) > 70) {
            for (int z = 0; z < (numFreq.at(i)/10); ++z) {
                cout << "*";
            }
        }

        else {
            for (int z = 0; z < numFreq.at(i); ++z) {
                cout << "*";
            }
        }
        cout << endl;
    }
}


int main() {

    srand((unsigned)time(0));

    int lowRange, highRange, amtNumbers, random;

    cout << "Enter number of random numbers to generate: ";
    cin >> amtNumbers;
    cout << "Enter lower bound: ";
    cin >> lowRange;
    cout << "Enter upper bound: ";
    cin >> highRange;

    vector <int> numFreq ((highRange - lowRange)+1);

    for (int i = 0; i < amtNumbers; ++i) {
        random = randNum(highRange,lowRange);
        frequency(numFreq, random, lowRange);
    }

    displayStats(numFreq);
    freqDisplay(numFreq, lowRange);

    return 0;
}
