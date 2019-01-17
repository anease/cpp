#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

double const pi = 3.14159265359;

class Sphere {

    public:

    Sphere() { setR(0); }
    Sphere(double in_R) {
        setR(in_R); }

    void display();

    void setR(double in_R) {
        r = in_R;
        setSA();
        setVol(); }



    double getR() { return r; }


    private:

    void setSA() {
        sa = 4 * pi * getR() * getR() ; }

    void setVol() {
        vol = (4.0/3.0) * pi * (getR() * getR() * getR()); }

    double r;

    double sa;
    double vol;
};

void Sphere::display() {

    cout << "Radius: " << getR() << endl;

    cout << "Surface Area: " << sa << endl;
    cout << "Volume: " << vol << endl;
}


int main() {
   Sphere S0;
   Sphere S1;
   Sphere S2(9);

   S0.setR(5);

   S0.display();
   cout << endl;
   S1.display();
   cout << endl;
   S2.display();
   cout << endl;

   return 0;
}
