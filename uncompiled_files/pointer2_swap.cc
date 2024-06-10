// definition and call of function swap
// usage of pointers as parameters
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

// prototype of swap: has to be here in case
// function is defined after use (here main)
void swap(float *, float *);

int main()
{
    float x = 11.1F;
    float y = 22.2F;

    cout << "before swap x address: " << &x << endl;
    cout << "before swap y address: " << &y << endl;
    cout << "before swap x value  : " << x << endl;
    cout << "before swap y value  : " << y << endl;
    swap(&x, &y);
    cout << " after swap x address: " << &x << endl;
    cout << " after swap y address: " << &y << endl;
    cout << " after swap x value  : " << x << endl;
    cout << " after swap y value  : " << y << endl;
    return 0;
}

void swap(float *p1, float *p2)
{
    float temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}