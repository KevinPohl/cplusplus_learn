// account.h
//------------------------------------------------------------------------------
#ifndef ACCOUNT_H // prevent multiple inclusions
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account
{
    // public/private can be set indefinitely often
    // if no flag is given, private is implicit
    private:                    // private elements
        string name;            // account holder
        unsigned long number;   // account number
        double balance;         // account balance
    
    public:                     // public elements (public interface in sum)
        // bool init(const string&, unsigned long, double);
        
        bool init(const string&, unsigned long, double);
        // string = string value gets passed
        // string& = string reference gets passed (cheaper than copy of value)
        // const string& = string reference with read only marker "const"
        
        void display();
};

#endif // ACCOUNT_H