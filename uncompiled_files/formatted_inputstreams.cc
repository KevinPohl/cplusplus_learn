#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    string name;
    double price;

    cout << "\nInput a name: ";
    // max 16 chars for a name:
    cin >> setw(16); // or: cin.width(16);
    cin >> name;
    // ignore rest of line. at least \n is in inputbuffer
    cin.ignore(LLONG_MAX, '\n'); // empty buffer
    cout << "\nInput a price: ";
    cin >> price; // read price
    // control:
    cout << fixed << setprecision(2)
    << "\nArticle:"
    << "\nName: " << name
    << "\nPrice: " << price << endl;
    // program goes on ...





    return 0;
}