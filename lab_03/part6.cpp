#include <iostream>
#include <cmath>

using namespace std;

double E_to_X(double X) {

    double q = 1;
    int z;
    double e = 1;
    double diff = 1;

        for (z = 1; z <= 100; ++z) {

            q = q * z;

            e = e + (pow(X,z) / q);

        //if (z>1) {
        //    diff = fabs( e - ((pow (X,(z-1))) / (q/(z)))); }

        }
    
    return e;
}


int main()
{
    double X;
    cin >> X;
    cout << fixed << E_to_X(X) << endl;

    return 0;
}
