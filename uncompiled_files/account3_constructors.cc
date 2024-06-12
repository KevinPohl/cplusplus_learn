//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "account3_constructors.h"
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

// default constructor with default values
// Account::Account(){
//     number = 000000;
//     name = "dummyname";
//     balance = 0.00;
// };

// default constructor without default values
Account::Account(){};

Account::Account(const string& k_name, unsigned long k_number, double k_balance)
{
    number = k_number;
    name = k_name;
    balance = k_balance;
}

Account::Account(const string& k_name)
{
    name = k_name;
    number = 1111111; balance = 0.0;
}

int main(){
    Account abc("Steven Smith", 123, 1174.41);
    abc.display();

    Account cust1("Susan"), cust2("Peter", 123, -312.10);
    cust1.display();
    cust2.display();

    cust1.init("Smith, Susan", 123456, 123456.45);
    cust1.display();

    // default constructor Account::Account(); newly added in account2.h
    // plus in this file with dummy default values or empty
    // if there are 
    Account cust3;
    cust3.display();

    return 0;
}