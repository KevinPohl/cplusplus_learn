#include <iostream>
#include <iomanip>
#include <string>
#include "stay_alive.h"
using namespace std;

// void stay_alive(){
//     std::cout << "\n<any key to close>\n";
//     std::cin.ignore();
//     std::string str;
//     std::getline(std::cin, str);
// }

// this namespace is there to hide the method from outside usage
namespace {
void throw_error(){
    cout << "an error occured, good luck" << endl;
}
} // namespace
int main(){    
    int max;

    cout << "Create a Fibonacci up until which value?\nPlease insert an integer: " << endl;
    cin >> max;
    if (max < 1) throw_error();
    
    cout << setw(12) << right
        << "Iteration"
        << setw(12) << right
        << "Fibonacci"
        << endl;
    
    int i = 1, x=0, y=1, sum=0;
    while (x <= max){
        cout
            << setw(12) << right
            << i
            << setw(12) << right
            << x
            << endl;
        sum = x + y;
        x = y;
        y = sum;
        ++i;
    }

    stay_alive(true);
    return 0;
}