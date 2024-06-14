//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring> 
using namespace std;
char header[] = "\n *** Demo for C-Strings ***\n\n";
int main()
{
    char hello[30] = "Hello ", name[20], message[80];
    cout << header << "Your Surname: ";
    cin >> setw(20) >> name;
    strcat(hello, name);
    cout << hello << endl;
    cin.ignore(LLONG_MAX,'\n'); // ignore inputs from before
    cout << "\nWhat's your message of the day?"
    << endl;
    cin.getline(message, 80);   // read a line up to 79 chars + '/0'
    if(strlen(message) > 0)     // if string length > 0
    {
        for(int i=0; message[i] != '\0'; ++i)
            cout << message[i] << ' ';
        cout << endl;
    }
    return 0;
}