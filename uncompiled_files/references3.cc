// shows usage of references as return type
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// return reference to minimum
double& refMin(double&, double&);

int main()
{
    double x1 = 1.1, x2 = x1 + 0.5, y;
    y = refMin(x1, x2);                 // allocate minimum to y
    cout << "x1 = " << x1 << " "
         << "x2 = " << x2 << endl;
    cout << "Minimum: " << y << endl;
    ++refMin(x1, x2);                   // ++x1, x1 is minimum now
    cout << "x1 = " << x1 << " "        // x1 = 2.1
         << "x2 = " << x2 << endl;      // x2 = 1.6
    ++refMin(x1, x2);                   // ++x2, x2 is minimum now
    cout << "x1 = " << x1 << " "        // x1 = 2.1
         << "x2 = " << x2 << endl;      // x2 = 2.6
    refMin(x1, x2) = 10.1;              // x1 = 10.1, x1 is minimum now
    cout << "x1 = " << x1 << " "        // x1 = 10.1
         << "x2 = " << x2 << endl;      // x2 = 2.6
    refMin(x1, x2) += 5.0;              // x2 += 5.0, x2 is minimum now
    cout << "x1 = " << x1 << " "        // x1 = 10.1
         << "x2 = " << x2 << endl;      // x2 = 7.6
    return 0;
}

// return reference to minimum
double& refMin(double& a, double& b)
{
    return a <= b ? a : b;
}