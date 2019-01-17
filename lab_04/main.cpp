#include <iostream>
#include <cmath>

using namespace std;

const double pi = atan(1.0)*4.0;

double d_to_r(double deg) {

    if (fmod(deg, 360) == 0.0) return 0;
    double reduced_deg = fmod(deg, 360);
    return double (reduced_deg * (pi/180));
}

int main()
{
    double deg = 0;
    cout << "Degrees: ";
    cin >> deg;
    cout << "Radians: " << d_to_r(deg) << endl;

    return 0;
}
