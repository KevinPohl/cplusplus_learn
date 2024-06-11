// Definition of account methods init() and display()
//------------------------------------------------------------------------------
#include "account.h" // definition of class
#include <iostream>
#include <iomanip>
using namespace std;

// init() copies its arguments into private elements of the class
bool Account::init(const string& i_name,
    unsigned long i_number,
    double i_balance)
{
    if(i_name.size() < 1) // can't be empty
        return false;
    name = i_name;
    number = i_number;
    balance = i_balance;
    return true;
}

// display() shows the private data on display
void Account::display()
{
    cout << fixed << setprecision(2)
    << "--------------------------------------\n"
    << "Account holder: " << name << '\n'
    << "Account number: " << number << '\n'
    << "Account balance: " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}

int main1()
{
    // instantiate class object
    class Account abc;

    // use method init() from account.h
    abc.init("Peter", (unsigned long)12, (double)1264.43);

    // use method display() from account.h
    abc.display();

    Account instance_copy, instance;
    instance.init("Reich, Franzi",350123, 10000.0);
    instance_copy = instance;

    cout << "instance_copy\n\0";
    instance_copy.display();
    cout << "instance\n\0";
    instance.display();
    
    return 0;
}