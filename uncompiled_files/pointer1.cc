// show value and address of variable
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int var, *ptr;              // definition of variables var and ptr
int main()                  // show value and address of variables var and ptr
{
    var = 100;
    ptr = &var;

    cout << "Value of var: " << var << "\n"
         << "Address of var: " << &var
         << endl;

    cout << "Value of ptr: " << ptr << "\n"
         << "Address of ptr: " << &ptr
         << endl;

    
    cout
        << "\n---------------------------------------" << endl
        << "address of ptr : &ptr : " << &ptr << endl
        << "address of var : &var : " << &var << endl
        << "address of var : ptr  : " << ptr << endl
        << "value of var   : var  : " << var << endl
        << "value of var   : *ptr : " << *ptr << endl;

    cout
        << "\n" 
        << "& : address of self\n"
        << "  : value of self\n"
        << "* : indirect" << endl;

    return 0;
}