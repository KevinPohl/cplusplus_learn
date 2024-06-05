// geschw.cpp
// Bußgeld für zu schnelles Fahren ausgeben.
#include <iostream>
using namespace std;
int main()
{
    float limit, speed, speeding;
    cout << "\nSpeed limit: ";
    cin >> limit;
    cout << "\nSpeed: ";
    cin >> speed;
    if( (speeding = speed - limit ) < 10)
    cout << "You got lucky!" << endl;
    else if( speeding < 20)
    cout << "Speeding ticket: 40 Euro" << endl;
    else if( speeding < 30)
    cout << "Speeding ticket: 80 Euro" << endl;
    else
    cout << "Your drivers license is gone!" << endl;
    return 0;
}