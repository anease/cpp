#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    float sum = 0;

    int startIndex = 0;
    int endingIndex = 0;
    int stepCount = 0;

    cin >> startIndex ;
    cin >> endingIndex ;
    cin >> stepCount ;

    for (int x = startIndex; x <= endingIndex; i++) {

        sum = sum + x;
        x += stepCount ;

    }

    float avg = sum / i;

    cout << "SUM: " << sum << endl;
    cout << "AVERAGE: " << avg << endl;

    float startPoint = 0;
    cin >> startPoint ;

    for (float out = startPoint; out >= 0;) {

        cout << out;

        if (out != 0) cout << ",";

        out = out - 0.5;
    }

    return 0;
}
