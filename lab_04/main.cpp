#include <iostream>

using namespace std;

bool isPrime(int A){

    bool prime = false;

    if (A <= 1) {
        prime = false;
        return prime; }

    for(int i = 2; i <= A/2; ++i){

        if (A % i == 0){
            prime = true;
            break;     }
    }

    return !prime;
}


int main()
{
    int num;
    cin >> num;
    bool prime_bool = isPrime(num);
    cout << (prime_bool ? "Prime" : "Not Prime") << endl;

    return 0;
}
