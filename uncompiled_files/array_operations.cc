//------------------------------------------------------------------------------
#include <array>
#include <string>
#include <iostream>
using namespace std;

template<class Arr>

// Call by Reference
void showArray(Arr& a)
{
    for( auto& el : a) // output with range for loop
        cout << el << " ";
    cout << endl;
}

int main()
{
    // with and without instatiation
    array<int,5> arr1, arr2 = { 1, 2, 3, 4, 5 };

    // // version is before C++17
    // array arr3{ 1, 5, 4, 3, 2 }; // possible after (C++17).
    // arr3[0] = 10; // Index-Operator.
    // array<int,5> arr4(arr3); // Kopie von arr3.
    // cout << "Die Kopie des 3. Arrays:\n";
    // showArray(arr4);
    
    // assignment of same size arrays
    arr1 = arr2;
    cout << "1. array after assignment:\n";
    showArray(arr1);
    
    // fill with value 1
    arr1.fill(1);
    
    // true, because arr1[0] == arr2[0] and arr1[1] < arr2[1]
    if(arr1 < arr2)
    {
        cout << "The array "; showArray(arr1);
        cout << "is smaller than "; showArray(arr2);
    }

    // a "two dimensional" vector:
    array<string, 3> fNames = { "Emely", "Edith", "Romy" },
    mNames = { "Anton", "Daniel", "Max" };
    array<array<string, 3>, 2> names = { fNames, mNames };
    showArray(names[0]);
    showArray(names[1]);
    return 0;
}