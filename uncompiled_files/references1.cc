//------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

float x = 10.7F;                        // global

int main()
{
    float &rx = x;                      // local reference to x
    // float &rx = x; // is the same as
    // float& rx = x; // and means rx is a reference to x

    // double &ref = x;                 // Error: different type!

    rx *= 2;

    cout << " x = " << x << endl        // x = 21.4
        << " rx = " << rx << endl;      // rx = 21.4
    const float& cref = x;              // read-only-reference
    cout << "cref = " << cref << endl;  // ok!
    // ++cref;                          // Error: Read-only!
    
    const string str = "I am a constant string!";
    
    // str = "That's not possible!";    // Error: str constant!
    // string& text = str;              // Error: str constant!
    const string& text = str;           // ok!
    cout << text << endl;               // ok! text will be read-only
    return 0;
}
