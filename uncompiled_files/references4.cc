// Output with reference type with example of reference operators for strings.
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype> // for toupper()
using namespace std;
void strToUpper(string&); // prototype

int main()
{
    string text("Text with references\n");
    strToUpper(text);
    cout << text << endl;
    strToUpper(text = "sour");
    cout << text << endl;
    strToUpper(text += " is funny!\n");
    cout << text << endl;
    return 0;
}

void strToUpper(string& str) // change value of str to uppercase string
{
    int len = str.length();
    for(int i=0; i < len; ++i)
        str[i] = toupper(str[i]);
}