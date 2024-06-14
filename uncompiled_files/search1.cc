// a filter giving back lines if a pattern is found, uses function strstr()
// call: search1 [ < text.dat ]
//------------------------------------------------------------------------------
#include <iostream>
#include "strstr.cc"
using namespace std;
#define MAXL 200 // max line length

namespace MyScope
{ // own version of function strstr():
    char *strstr(const char *str, const char *pattern);
}

// one text line, search pattern
char line[500], pattern[] = "ei";

int main()
{
    int lineNum = 0;
    // as long as a line is left
    while(cin.getline(line, MAXL))
    {
        ++lineNum;
        if(MyScope::strstr(line, pattern) != NULL)
        {
            // if pattern is found
            cout.width(3);
            // output as line number and line
            cout << lineNum << ": " << line << endl;
        }
    }
    return 0;
    // abort from terminal with <ctrl>+<c>
}