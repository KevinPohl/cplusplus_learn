// array class with range check
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib> // for exit()
using namespace std;
#define MAX 100

class FloatVek
{
    private:
    float v[MAX]; // the vector
    public:
    float& operator[](int i);
    static int MaxIndex(){ return MAX-1; }
};

float& FloatVek::operator[]( int i )
{
    if( i < 0 || i >= MAX )
    {
        cerr << "\nFloatVek: Out of Range!" << endl;
        exit(1);
    }
    return v[i]; // reference to i-th element
}

int main()
{
    cout << "\n A vector with index check!\n"
    << endl;
    FloatVek rnd; // create a vector, fill with RNDs
    int i;

    for(i=0; i <= FloatVek::MaxIndex(); ++i)
        rnd[i] = (rand() - RAND_MAX/2) / 100.0F;

    cout << "\n Input an index in between 0 and " << FloatVek::MaxIndex()
        << "!" << "\n (Cancel with invalid input)" << endl;
    while(cout << "\nIndex: " && cin >> i )
        cout << i << ". Element: " << rnd[i];
    return 0;
}