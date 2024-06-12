// Definition of class account with two constructors
//------------------------------------------------------------------------------
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
    private:
        string name = "X";                  // account holder
        unsigned long number = 1111111UL;   // account number
        double balance = 0.0;               // account balance
        // the default values X, 1111111 and 0.0 are used in account3.cc, if
        // instantiated with default constructor
        // Account abc;
        // abc.display();
    
    public:
        Account();
        Account(const string&, unsigned long, double);
        Account(const string&);
        bool init(const string&, unsigned long, double);
        void display();
};

#endif // ACCOUNT_H