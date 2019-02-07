#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    const float g = 9.8;
    float v = 0;
    float height = 0;
    int t = 0;

    cout << "Enter Initial V0: ";
    cin >> v;

    cout << "Time   Height" << endl;

    while (height >= 0) {

        height = (v*t) - (0.5 * g ) * pow(t,2);
        cout << t << "   " << height << endl;
        if (height < 0) {
            break; }

        t = t + 1;

    }

    float maxHeight = (v*(t/2)) - (0.5 * g ) * pow((t/2),2);


    cout << "Total Time: " << t << "-seconds" <<endl;
    cout << "Maximum Height: "<< maxHeight << " @ " << (t/2) << "-seconds";
    cout << endl;

    return 0;
}
