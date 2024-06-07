#include <iostream>
using namespace std;

void getput(void);

int main()
{
    cout << "Please input a line of text:\n";
    getput();
    cout << "\nBye Bye!" << endl;
    return 0;
} // end of main

void getput()
{
    char c;
    
    // if first character of cin is not empty or '\n'
    if(cin.get(c) && c != '\n') {
        // call yourself (while first character of cin is popped)
        getput();
    }
    cout << c;
} // end of getput