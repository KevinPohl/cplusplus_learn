// function displayError() gives a message for an errornum
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

void displayError(int errorNum)
{
    static const char* errorMsg[] =
    // implicit indexing: 0, 1, 2, 3
    {
        "invalid errornum",
        "Error 1: too much data",
        "Error 2: not enough memory",
        "Error 3: no existing data"
    };
    if(errorNum < 1 || errorNum > 3)
        errorNum = 0;
    cerr << errorMsg[errorNum] << endl;
}