
#include <iostream>
#include <string>
#include <cctype> // for macro isspace()
using namespace std;
//------------------------------------------------------------------------------

int main()
{
    string header(" **** Count words ****\n"),
    prompt("Input text and " "continue with '.' + <Return>:"),
    line( 60, '-'),
    text; // empty string
    cout << header << endl << prompt << endl << line << endl;
    getline(cin, text, '.'); // read text until first dot
    unsigned int i, // Index
    nSpace = 0, // count whitespace chars
    nWord = 0; // count words
    bool fSpace = true; // flag whitespace chars
    for( i = 0; i < text.length(); ++i)
    {
        if(isspace(text[i]) ) {// check if whitespace
            ++nSpace;
            fSpace = true;
        }
        else if(fSpace) {// check if start of word
            ++nWord;
            fSpace = false;
        }
    }
    // output summary:
    cout << line
        << "\nYour text contains (dot not counting)"
        << "\n Characters: " << text.length()
        << "\n Words: " << nWord
        << "\n Whitespace Characters: " << nSpace
        << endl;

    return 0;
} // end of main