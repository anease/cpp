#include <iostream>
#include <cmath>

using namespace std;

bool compareDelta(double num1, double num2, double delta) {

    double diff = abs(num1 - num2);

    if (diff > delta) return false;

    else return true; }


int main()
{
    double num1, num2, delta;

    cout << "Number 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;
    cout << "Delta: ";
    cin >> delta;

    bool compare = compareDelta(num1,num2,delta);

    cout << "These numbers " << (compare ? "do" : "do not") << " lie within delta" << endl;

    return 0;
}
