// the operators new and delete for classes
//------------------------------------------------------------------------------
// #include "account.h"
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
    << "Account holder : " << name << '\n'
    << "Account number : " << number << '\n'
    << "Account balance: " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}
#endif // ACCOUNT_H


// create dynamic copy - prototype
Account *clone(const Account* pK);

int main()
{
    cout << "dynamically created objects\n" << endl;

    // reserve memory from heap
    Account *ptrK1, *ptrK2, *ptrK3;
    
    // with default constructor.
    ptrK1 = new Account;
    
    // display default values
    ptrK1->display();
    
    // set other values with setters
    ptrK1->setNumber(302010);
    ptrK1->setName("Meier, Max");
    ptrK1->setBalance(2345.87);
    
    // display new values
    ptrK1->display();
    
    // use constructor with 3 arguments
    ptrK2 = new Account("Lieblich, Anna", 7531357, 999.99);

    // display new account
    ptrK2->display();
    
    // point to dynamically created copy
    ptrK3 = clone(ptrK1);
    cout << "Copy of first account: " << endl;
    
    // display copy
    ptrK3->display();
    
    // free memory
    delete ptrK1;
    delete ptrK2;
    delete ptrK3;

    return 0;
}

// create dynamic copy
Account *clone( const Account* pK)
{
    return new Account(*pK);
}