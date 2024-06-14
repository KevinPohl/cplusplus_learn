// display adresses and values of vector elements
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int arr[4] = { 0, 10, 20, 30 };

int main()
{
    cout << "\nadress and value of vector elements:\n" << endl;
    for(int i = 0; i < 4; i++)
        cout << "Adress: " << (void*)(arr+i) /* &arr[i] */ << " Value: " 
            << *(arr+i) /* arr[i] */ << endl;
    return 0;
}