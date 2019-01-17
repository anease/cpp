// GROUP: ANDREW NEASE & LANDEN DAVIS

#include <iostream>
#include <vector>

using namespace std;

class Circuit{
   public:
    void enterParameters();
    void calculateNodes();
    void Menu();

   private:
    void enterVoltage();
    void enterResistance();
    void totalResistance();
    void calcCurrent();
    void totalPower();
    void individualVoltage();
    void individualPower();
    void displayParameters();
    void MenuOutput();
    void addResistor();
    void deleteResistor();
    void editResistor();


    vector <double> resistance;
    vector <double> eachVoltage;
    vector <double> eachPower;
    double voltage;
    double power;
    double current;
    double totalR;
};

void Circuit::MenuOutput(){
    cout << "1: Add a single resistor" << endl;
    cout << "2: Change Input voltage" << endl;
    cout << "3: Delete resistor" << endl;
    cout << "4: Edit resistor values" << endl;
    cout << "5: Group add a series of resistors" << endl;
    cout << "6: Display network" << endl;
    cout << "7: Quit program" << endl;
    cout << "Enter choice: ";
}

void Circuit::Menu(){
        int input;

    do {
        MenuOutput();
        cin >> input;
        cout << endl;

        while(input>7 || input<1){
            cout << "Enter valid choice.";
            cin >> input;
        }

        switch(input) {

case 1:  addResistor();
        break;

case 2:  enterVoltage();
        break;

case 3:  deleteResistor();
        break;

case 4:  editResistor();
        break;

case 5:  enterResistance();
        break;


case 6:  calculateNodes();
        break;

case 7: break;

        }

        cout << endl;

        } while(input != 7);


}

void Circuit::addResistor(){
    double input;
    cout << "Enter Resistance: ";
    cin >> input;
    resistance.push_back(input);
}

void Circuit::deleteResistor(){
    cout << "Current resistors:" << endl;

    for(unsigned int i = 0; i < resistance.size(); ++i){
        cout << "Resistor " << i << ": ";
        cout << resistance.at(i) << endl;
    }

    cout << "Choose the resistor to delete:" << endl;
    int choice = 0;
    cin >> choice;
    resistance.erase(resistance.begin() + choice);
}

void Circuit::editResistor(){
    cout << "Current resistors:" << endl;

    for(unsigned int i = 0; i < resistance.size(); ++i){
        cout << "Resistor " << i << ": ";
        cout << resistance.at(i) << endl;
    }

    cout << "Choose the resistor to edit:" << endl;
    unsigned int choice;
    cin >> choice;
    cout << "Enter the new value: ";
    int edit;
    cin >> edit;

    resistance.at(choice) = edit;
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

    C1.Menu();

    return 0;
}


