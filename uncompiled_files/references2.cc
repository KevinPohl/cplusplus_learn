// demo for functions with reference parameters
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// prototypes:
bool get_customer(string& name, long& nr);
void put_customer(const string& name, const long& nr);

int main()
{
    string customerName;
    long customerNr;
    cout << "\nread  and output customer data\n" << endl;
    if(get_customer(customerName, customerNr)) // calls
        put_customer(customerName, customerNr);
    else
        cout << "invalid input!" << endl;
    return 0;
}

bool get_customer(string& name, long& nr) // definition
{
    cout << "\ninput customer data!\n"
    << " Name: ";
    if( !getline(cin, name)) return false;
    cout << " Number: ";
    if( !(cin >> nr)) return false;
    return true;
}

 // definition
void put_customer(const string& name, const long& nr)
{ 
    // name and number are read-only
    cout << "\n-------- customersdata ---------\n"
    << "\n Name: "; cout << name
    << "\n Number: "; cout << nr << endl;
}