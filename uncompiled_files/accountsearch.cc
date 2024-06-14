// search for an account number in account table and display if found
//------------------------------------------------------------------------------
#include "account5_destructor.h" // definition of class Account.
Account accountTab[100]; // table with account objects

int main()
{
    int count; // current count of accounts in table
    Account *kPtr; // pointer to Account object
    // read data into accountTab, update count
    // search account number 1234567
    bool found = false;

    for(kPtr = accountTab; kPtr < accountTab + count; ++kPtr)
        if(kPtr->getNumber() == 1234567)
        {
            found = true;
            break;
        }
    if(found)
        kPtr->display();

}