//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "account5_destructor.h"
using namespace std;

int main(){

    Account cust1;
    cust1.display();

    cust1.setName("Miller, John");
    cust1.setNumber(123456UL);
    cust1.setBalance(12.45);

    cust1.display();

    // string name = cust1.getName();
    string full_name = cust1.getName();
    int findcomma = full_name.find(',');
    cout << findcomma << endl;

    string last_name = full_name.substr(0, findcomma);
    string first_name = full_name.substr(findcomma+2, 1000);

    cout << "some custom text about " << first_name << " " << last_name << ", whose account number\nis " << cust1.getNumber() << " and whose balance is " << cust1.getBalance() << " at the moment." << endl;
    
    cust1.setName("someone, else");
    cust1.display();

    return 0;
}