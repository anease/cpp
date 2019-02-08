#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

double const pi = 3.14159265359;

class Cylinder {

    public:

    Cylinder() { setR(0); setH(0); }
    Cylinder(double in_R, double in_H) {
        setR(in_R); setH(in_H); }
    Cylinder(double in_R) {
        setR(in_R);
        setH(0); }

    void display();

    void setR(double in_R) {
        r = in_R;
        setSA();
        setVol(); }

    void setH(double in_H) {
        h = in_H;
        setSA();
        setVol(); }

    double getR() { return r; }
    double getH() { return h; }


    private:

    void setSA() {
        sa = 2 * pi * getR() * (getR() + getH()); }

    void setVol() {
        vol = pi * (getR() * getR()) * getH(); }

    double r;
    double h;

    double sa;
    double vol;
};

void Cylinder::display() {

    cout << "Radius: " << getR() << endl;
    cout << "Height: " << getH() << endl;

    cout << "Surface Area: " << sa << endl;
    cout << "Volume: " << vol << endl;
}


int main() {
   Cylinder C0;
   Cylinder C1;
   Cylinder C2(9,3);

   C0.setR(5);
   C0.setH(7);

   C0.display();
   cout << endl;
   C1.display();
   cout << endl;
   C2.display();
   cout << endl;

   return 0;
}
