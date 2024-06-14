// a vector with objects of account class
//------------------------------------------------------------------------------
#include "account5_destructor.h" // definition of account class
#include <iostream>
using namespace std;
Account giro("Lustig, Peter", 1234567, -1200.99 );
Account accountTab[] =
{
    Account("Müller, Sarah", 123000, 2500.0),
    Account("Schmidt, Jean", 543001),
    Account("Ulk, Mira"),
    Account(), // Default-Konstruktor
    giro // Konto(giro)
};
int anz = sizeof(accountTab) / sizeof(Account);
int main()
{
    // set some values
    accountTab[1].setBalance(10000.00);

    accountTab[2] = Account("Traurig, Otto", 727003, 200.00);
    cout << "The accounts of table:" << endl;
    
    for(int i = 0; i < anz; ++i)
    {
        accountTab[i].display();
        if(i % 3 == 2)
        {
            cout << "Continue with <return>!\n";
            cin.get();
        }
    }
    cout << endl;
    return 0;
}