#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = atan(1.0)*4.0;

double d_to_r(double deg) {

    if (fmod(deg, 360) == 0.0) return 0;
    double reduced_deg = fmod(deg, 360);
    return double (reduced_deg * (pi/180));
}

int main()
{
    cout << fixed << setw(10) << "Degrees";
    cout << setw(10) << "Sine";
    cout << setw(10) << "Cosine";
    cout << setw(25) << "Tangent" << endl;

    for (int i = 0; i <= 360; i+=10 ){
        cout << setw(10) << setprecision(4) << i;
        cout << setw(10) << setprecision(4) << sin((d_to_r(i)));
        cout << setw(10) << setprecision(4) << cos((d_to_r(i)));
        cout << setw(25) << setprecision(4) << tan((d_to_r(i))) << endl;
  }
    return 0;
}
