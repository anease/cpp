// GROUP: ANDREW NEASE & LANDEN DAVIS

#include <iostream>
#include <vector>

using namespace std;

class Circuit{
   public:
    void enterParameters();
    void calculateNodes();

   private:
    void enterVoltage();
    void enterResistance();
    void totalResistance();
    void calcCurrent();
    void totalPower();
    void individualVoltage();
    void individualPower();
    void displayParameters();

    vector <double> resistance;
    vector <double> eachVoltage;
    vector <double> eachPower;
    double voltage;
    double power;
    double current;
    double totalR;
};

void Circuit::enterParameters(){
    enterVoltage();
    enterResistance();
}

void Circuit::enterResistance(){
    double input;

    do {
       cout << "Enter Resistance (0 to exit) : ";
       cin >> input;
       if (input <= 0) break;
       resistance.push_back(input);
      } while(input > 0);
}

void Circuit::enterVoltage(){
    cout << "Enter Voltage: ";
    cin >> voltage;
}

void Circuit::totalResistance() {
   for(unsigned int i = 0; i < resistance.size(); i++) {
        totalR += resistance.at(i);
    }
}

void Circuit::calcCurrent(){
    current = voltage / totalR;
}

void Circuit::totalPower(){
    power = voltage * current;
}

void Circuit::individualVoltage(){
    double temp;

    for(unsigned int i = 0; i < resistance.size(); i++) {
         temp = resistance.at(i) * current;
         eachVoltage.push_back(temp);
     }
}

void Circuit::individualPower(){
    double temp;

    for(unsigned int i = 0; i < resistance.size(); i++) {
         temp =  eachVoltage.at(i) * current;
         eachPower.push_back(temp);
     }
}

void Circuit::displayParameters(){
    cout << "Circuit Parameters: " << endl;
    cout << "\tResistance: " << totalR << " ohms" << endl;
    cout << "\tVoltage: " << voltage << " volts" << endl;
    cout << "\tCurrent: " << current << " Amps" << endl;
    cout << "\tPower: " << power << " Watts" << endl << endl;

    for(unsigned int i = 0; i < resistance.size(); i++) {
        cout << "\tNode " << i << " Parameters: " << endl;
        cout << "\tResistance: " << resistance.at(i) << " ohms" << endl;
        cout << "\tVoltage: " << eachVoltage.at(i) << " volts" << endl;
        cout << "\tPower: " << eachPower.at(i) << " Watts" << endl << endl;
    }
}

void Circuit::calculateNodes(){
    totalResistance();
    calcCurrent();
    totalPower();
    individualVoltage();
    individualPower();
    displayParameters();
}

int main() {
    Circuit C1;

    C1.enterParameters();
    C1.calculateNodes();

    return 0;
}

