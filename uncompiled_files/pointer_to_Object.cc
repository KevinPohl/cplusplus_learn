// Work with Pointer to Oject on class Account
//------------------------------------------------------------------------------
// #include "account.h"                        // includes <iostream>, <string>
#include "account.cc"                       // includes <iostream>, <string>

bool getAccount(Account *pAccount);         // prototype

int main()
{
    Account giro1, giro2, *ptr = &giro1;
    ptr->init("Munter, Gabi", 3512345, 99.40); // giro1.init(...)
    
    ptr -> display();       // equivalent: ptr->display();
    giro1.display();        // equivalent to ptr -> display();
    (*ptr).display();       // equivalent to ptr -> display();
    // () has to be written because * has higher priority than .
    // left of . has to be an object
    // left of -> has to be a pointer to an object

    ptr = &giro2;           // let ptr point to giro2
    if(getAccount(ptr))     // read and display new account data
        ptr->display();
    else
        cout << "invalid input!" << endl;
    return 0;
}

//------------------------------------------------------------------------------
// getAccount reads data from cin by pointer into a new account object

bool getAccount(Account *pAccount)
{
    string name, line(50,'-');
    unsigned long number;
    double starting_capital;

    cout << line << '\n'
        << "Please input data for new account: \n"
        << "Account holder: ";
    if(!getline(cin, name) || name.size() == 0)
        return false;
    cout << "Account number: ";
    if(!(cin >> number)) return false;
    cout << "Starting capital: ";
    if(!(cin >> starting_capital)) return false;
    // all inputs valid
    pAccount->init(name, number, starting_capital);
    return true;
}