#include <iostream>

using namespace std;

int main()
{

    int width = 0;
    int height = 0;

    cout << "Width?";
    cin >> width;
    cout << "Height?";
    cin >> height;
    cout << endl;

   for (int q = 0; q < height; q++ ) {

   if (q == 0 || q == (height - 1)) {

    for (int i = 0; i < width; i++) {
        cout << "*";
         }

        }

   else {

       cout << "*";

       for (int i = 1; i < (width - 1); i++ ) {
           cout << " "; }

       cout << "*";

       }
   cout << endl;

   }


    cout << endl;





    return 0;
}
