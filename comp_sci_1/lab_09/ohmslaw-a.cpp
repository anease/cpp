// GROUP: ANDREW NEASE & LANDEN DAVIS

#include <iostream>
#include <vector>

using namespace std;

struct node {
    double resistance;
    double voltage;
    double power;
    double current;
};

double calcCurrent(double voltage, double resistance){
    double current = voltage / resistance;
    return current;
}

double calcPower(double voltage, double current){
    double power = voltage * current;
    return power;
}

void displayParameters(double voltage, double resistance, double current, double power){
    cout << "Circuit Parameters:" << endl;

    cout << "\tResistance: " << resistance << " ohms" << endl;
    cout << "\tVoltage: " << voltage << " volts" << endl;
    cout << "\tCurrent: " << current << " Amps" << endl;
    cout << "\tPower: " << power << " Watts" << endl;
}

int main() {
    node N1;

    cout << "Enter Voltage: ";
    cin >> N1.voltage;

    cout << "Resistor: ";
    cin >> N1.resistance;

    N1.current = calcCurrent(N1.voltage, N1.resistance);
    N1.power = calcPower(N1.voltage, N1.current);

    displayParameters(N1.voltage, N1.resistance, N1.current, N1.power);

    return 0;
}
