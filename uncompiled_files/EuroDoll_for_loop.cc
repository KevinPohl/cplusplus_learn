#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long euro, maxEuro;
    double exchange_rate; // Euro to $ exchange rate
    cout << "\n* * * Exchange rates Euro – US-$ * * *\n\n";
    cout << "\nPlease input an exchange rate of 1 Euro in US-$: ";
    cin >> exchange_rate;
    cout << "\nDefine the maximal Euro upper bound: ";
    cin >> maxEuro;
    // --- Output table ---
    // column names:
    cout << '\n'
    << setw(12) << "Euro" << setw(20) << "US-$"
    << "\t\tExchange rate: " << exchange_rate << endl;
    // format for $:
    cout << fixed << setprecision(2) << endl;
    long lower, upper,
    step;
    // the outer loop defines the lower bound and step
    for (lower=1, step=1; lower <= maxEuro; step*= 10, lower = 2*step){
        // two counters initialised in arg1, both cycled in arg3
        // the inner loop prints one block:
        // cout << "l: " << lower << "\t s: " << step << endl; // test print
        for (euro = lower, upper = step*10; euro <= upper && euro <= maxEuro; euro+=step){
            // combined arg2 (condition)
            cout << setw(12) << euro << setw(20) << euro*exchange_rate << endl;
        }
    }
    // the inner loop manipulates variables of the outer loop to then be used by that again


    // comma can be used to string code together - order is from left to right
    int x;
    x=1, cout << x << endl;
    
    return 0;
}