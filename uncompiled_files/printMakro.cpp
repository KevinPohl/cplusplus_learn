#include <iostream>
using namespace std;

// output value with field width fw
#define printW(value, fw) (cout.width(fw), cout << (value))
// can be undone with #undef printW, #ifdef and ifndef can test, if a macroname exists
// can be combined into
//#ifndef name
//#define name
//#endif

int main()
{
    double x = 3.33; 
    printW(1, 10); printW(2, 10) << endl;
    printW(x, 20) << endl;
    printW("field width 20", 20) << endl;
    return 0;
}