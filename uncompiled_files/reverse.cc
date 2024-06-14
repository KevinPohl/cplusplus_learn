// definition and call of function reverse()
// copies a c-string into a second and reverses order of chars
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <string.h> // header-file for C-Strings, here for strlen()
void reverse(char str[], char umstr[]); // prototype

int main()
{
    const int COUNT = 81;

    char word[COUNT], reversed_word[COUNT];
    cout << "input a word: ";
    cin.width(COUNT); // read max COUNT-1 chars
    cin >> word;
    reverse(word, reversed_word); // call
    cout << "\nThe \"reversed\" word: " << reversed_word
    << endl ;
    return 0;
}
void reverse(char s1[], char s2[]) // copies C-String s1 reversed into s2
{
    int j = 0;
    // i starts at end moving to front, j front to back
    for(int i = strlen(s1)-1; i >= 0; i--, j++)
    s2[j] = s1[i];
    s2[j] = '\0'; // string end char
}