#include <iostream>
using namespace std;

int main()
{
    float x, y;
    cout << "Input two floats:\n";
    if( !(cin >> x && cin >> y) ){ // in case input is not successful
        cout << "\nError!" << endl;
    } else {
        cout << "\nThe greater number is: "
            << (x > y ? x : y) << endl;
    }
    
    return 0;
}