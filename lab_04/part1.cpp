#include <iostream>

using namespace std;

int absolute(int A){
    return (A < 0) ? -A : A;
}

int minimum(int A, int B){
    return (A < B) ? A : B;
}

int maximum(int A, int B){
    return (A > B) ? A : B;
}

void swapEm(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

int main()
{
    int A = 0;
    int B = 0;

    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;

    cout << "You entered: " << A << " and " << B << endl;

    cout << "Absolute of A: " << absolute(A) << endl;
    cout << "Minimum of A and B: " << minimum(A,B) << endl;
    cout << "Maximum of A and B: " << maximum(A,B) << endl;
    swapEm(A,B);
    cout << "Swapped A and B: " << A << " " << B << endl;

    return 0;
}
