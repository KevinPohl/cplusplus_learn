/******************************************************
 A Program with multiple functions and comments
 ******************************************************/
#include <iostream>
using namespace std;
void line(), message(); // Prototypes
int main()
{
 cout << "Hello! The program starts in main()." 
 << endl;
 line();
 message();
 line();
 cout << "At the end of main()." << endl;
 return 0;
}
void line() // Print a line.
{
 cout << "--------------------------------" << endl;
}
void message() // Print a message.
{
 cout << "Message from inside the function()." << endl;
}