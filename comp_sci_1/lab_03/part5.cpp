#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

    double tolerance = 0.0;
    double width = 0.0;
    double x = 0.0;
    int t = 60;

    cout << "Width: ";
    cin >> width;
    cout << endl << "Tolerance: ";
    cin >> tolerance;
    cout << endl;

    cout << "Temperature        Width       Within Tolerance" << endl;


    for  (t = 60; t >= 60 && t <= 85; ++t) {

        x = width + (t - 70.0000)*(0.0001);
        cout <<  t << "	" << fixed << setw(10) << setprecision(7) <<  x <<  " " ;

        if (fabs(x - width) < tolerance) {
            cout << fixed << setw(10) << setprecision(6) << "*";
        }

        cout << endl;
    }
    
    return 0;
}
