#include <iostream>
#include <iomanip>
using namespace std;

void throw_error(){
    cout << "an error occured, good luck" << endl;
}

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

    cout << "<any key to close>\n"; //  << endl;
    cin.get(), cin.get();
    return 0;
}