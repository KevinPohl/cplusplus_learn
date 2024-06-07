// random.cpp
// Zufallszahlen in einem Bereich erzeugen u. ausgeben.
//-----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib> // Für rand(), srand()
#include <time.h> // Für time()
using namespace std;

bool setrand = false;
inline void init_random() // initialize rnd gen with current time
{
    if(!setrand)
    {
        srand((unsigned int)time(NULL));
        setrand = true;
    }
} // end of init_random

inline double myRandom() 
{
    // calculates random number x with 0.0 <= x <= 1.0
    init_random();
    return (double)rand() / (double)RAND_MAX;
} // end of double myRandom

inline int myRandom(int start, int end)
{
    // calculates random number n with start <= n <= end
    init_random();
    return (rand() % (end+1 - start) + start);
} // end of int myRandom

// test myRandom(), myRandom(int,int)
int main()
{
    int i;
    cout << "5 random numbers between 0.0 und 1.0 :" << endl;
    for( i = 0; i < 5; ++i)
        cout << setw(10) << myRandom();
    cout << endl;
    cout << "\n5 random integers"
    " between -100 and +100 :" << endl;
    for( i = 0; i < 5; ++i)
    cout << setw(10) << myRandom(-100, +100);
    cout << endl;
    return 0;
} // end of main