#include <iostream>
#include <iomanip>
using namespace std;

// read hex and float
int main() {
    int number = 0;
    cout << "\nInput a hexnumber: " << endl;
    cin >> hex >> number; // read hex number
    cout << "Your Input as decimal: " << number << endl;
    // if incorrect input:
    cin.clear(); // clear failure flags
    cin.ignore(LLONG_MAX,'\n'); // empty input buffer
    double x1 = 0.0, x2 = 0.0;
    cout << "\nPlease input two floats: "
    << endl;
    cout << "1. Number: ";
    cin >> dec >> x1; //standard is dec, oct and hex is possible as well
    cout << "2. Number: ";
    cin >> x2;
    cout << fixed << setprecision(2)
    << "\nthe sum of both numbers is: "
    << setw(10) << x1 + x2 << endl;
    cout << "\nthe product of both numbers is: "
    << setw(10) << x1 * x2 << endl;
    return 0;
}