// Definition of class account with two constructors
//------------------------------------------------------------------------------
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
    private:
        string name;            // account holder
        unsigned long number;   // account number
        double balance;         // account balance
    
    public:
        Account();
        Account(const string&, unsigned long, double);
        Account(const string&);
        bool init(const string&, unsigned long, double);
        void display();
};

#endif // ACCOUNT_H