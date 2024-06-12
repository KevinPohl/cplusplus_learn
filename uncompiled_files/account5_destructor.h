// konto.h
// new definition of class account with inline methods
//------------------------------------------------------------------------------
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account
{
    private:
        string name;                // account holder
        unsigned long number;       // account number
        double balance;             // account balance

    public:

        // constructor: implicit inline
        Account(
            const string& a_name = "X",
            unsigned long a_number = 1111111L,
            double a_balance = 0.0)
        {
            name = a_name;
            number = a_number;
            balance = a_balance;
        }

        // dummy destructor: implicit inline
        ~Account(){}

        const string& getName() const {return name;}
        bool setName(const string& s)
        {
            if(s.size()<1) {return false;}
            name = s;
            return true;
        }

        unsigned long getNumber() const {return number;}
        void setNumber(unsigned long n) {number = n;}
        double getBalance() const {return balance;}
        void setBalance(double x) {balance = x;}
        void display() const;
};

inline void Account::display() const // explicit inline
{
    cout << fixed << setprecision(2)
    << "--------------------------------------\n"
    << "Kontoinhaber: " << name << '\n'
    << "Kontonummer: " << number << '\n'
    << "Kontostand: " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}
#endif // ACCOUNT_H