#include <iostream>
#include <iomanip>
#include <cmath>
// #include <string>
#include "stay_alive.h"
using namespace std;

#define PI      3.1415926536
#define START   0.0             // lower bound
#define END     (2.0 * PI)      // upper bound
#define STEP    (PI / 8.0)      // step
#define HEADER  (cout << " ***** table for the sine function *****\n\n")

int main()
{
    HEADER;                     // header
                                // column names:
    cout << setw(16) << "x" << setw(20) << "sin(x)\n"
        << " -----------------------------------------"
        << fixed << endl;
    
    double x;
    for(x = START; x < END + STEP/2; x += STEP)
        cout << setw(20) << x << setw(16) << sin(x)
            << endl;
    
    cout << endl << endl;
    
    // std::cout << "<any input to close>\n";
    // std::string str;
    // std::getline(std::cin, str);
    stay_alive();
    return 0;
}