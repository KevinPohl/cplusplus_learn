// read text with operator >> and function getline()
#include <iostream>
#include <string>
using namespace std;
string header = 
" --- exemplary program for unformatted input ---";
int main()
{
    string word, rest;
    cout << header
    << "\n\ncontinue with <Return>" << endl;
    cin.get(); // read newline, but don't save
    cout << "\nPlease input text containing multiple words."
    << "\nContinue with <!> and <Return>."
    << endl;
    cin >> word; // 1. read word and save into variable
    getline( cin, rest, '!'); // save rest in other variable up until !
    cout << "\nFirst Word: " << word
    << "\nRest of input: " << rest << endl;
    return 0;
}