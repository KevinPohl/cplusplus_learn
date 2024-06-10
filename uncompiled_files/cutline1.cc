#include <iostream>
#include <string>
// #include "cutline2.cc"

using namespace std;

void cutline(void);             // prototype
string line;                    // global string

int main()
{
    while( getline(cin, line))  // as long as a line can be read
    {
        cutline();              // cut the line
        cout << line << endl;   // output line.
    }
    return 0;
}