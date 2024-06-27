//------------------------------------------------------------------------------
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "account5_destructor.h"
// using namespace std;

int main()
{
    int arr[] { 1, 2, 3, 4, 5 }; // int-Array initialisieren.
    for(int& el : arr) // el is a reference to a vector element
    {
        el += 10; // change every element
        std::cout << el << " "; // display the element
    }
    std::cout << std::endl;
    
    // instantiate a vector with Account objects
    vector<Account> accountVec {
        Account("Heidi", 12345UL, 1950.99),
        Account("Hansi", 54321UL, 1150.99),
        Account("Irmi", 98765UL, 950.99) };
    
    // display vector
    // k is read-only (const and & to prevent copying,
    // auto to set type automatically, can be int here as well)
    for(const auto& k : accountVec)
    k.display();

    // init a list
    list<string> strList = { "Vivi", "Jeany", "Anna" };
    std::cout << "The list contains " << strList.size() << " elements:"
        << std::endl;
    for(const auto& str : strList)
        std::cout << str << " ";
    std::cout << std::endl;

    return 0;
} 