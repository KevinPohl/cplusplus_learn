//------------------------------------------------------------------------------
#ifndef KONTO_H
#define KONTO_H
#include <iostream>
#include <iomanip>
#include <string>
// using namespace std;

class Account
{
    private:
        std::string account_holder;
        unsigned long account_number;
        double account_balance;

    public:
    // constructor
    Account(const std::string& a_name = "X", unsigned long a_nr = 1111111L, double a_bal = 0.0)
    {
        account_holder = a_name;
        account_number = a_nr;
        account_balance = a_bal;
    }

    // destructor
    ~Account(){ }

    // setter
     bool setName( const std::string& s)
     {
        // can't be empty
        if(s.size() < 1)
            return false;
        account_holder = s;
        return true;
    }
    void setNr (unsigned long n) { account_number = n; }
    void setBalance (double x) { account_balance = x; }

    // getter
    const std::string& getName() const { return account_holder; }
    unsigned long getNr() const { return account_number; }
    double getBalance() const { return account_balance; }

    // other
    void display() const;
};
#endif // KONTO_H

//------------------------------------------------------------------------------
inline void Account::display() const
{
    std::cout << std::fixed << std::setprecision(2)
    << "--------------------------------------\n"
    << "Kontoinhaber: " << account_holder << '\n'
    << "Kontonummer: " << account_number << '\n'
    << "Kontostand: " << account_balance << '\n'
    << "--------------------------------------\n\n";
}
//------------------------------------------------------------------------------
// sorts a vector of pointers on accounts by account number

void ptrSwap(Account**, Account**);

void accountSort(Account** account_ptr, int n)
{
    Account **temp, **minp, **lastp;
    
    // point to last pointer in vector
    lastp = account_ptr + n - 1;

    for( ; account_ptr < lastp; ++account_ptr)
    {
        minp = account_ptr;
        for(temp = account_ptr + 1; temp <= lastp; ++temp)
        {
            if((*temp)->getNr() < (*minp)->getNr())
            minp = temp;
        }
        ptrSwap(account_ptr, minp);
    }
}

void ptrSwap(Account **p1, Account **p2)
{
    Account *help;
    help = *p1; *p1 = *p2; *p2 = help;
}

//------------------------------------------------------------------------------
int main()
{
    return 0;
}