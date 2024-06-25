//------------------------------------------------------------------------------
#include <iostream>
// using namespace std;

template <class T>
T minimum(T x, T y)
{
    return((x < y) ? x : y);
}

int main()
{
    short x = 10, y = 2;
    std::cout << "x = " << x << " y = " << y << std::endl;
    std::cout << "Smaller number: " << minimum(x, y) << std::endl; // Aufruf o.k.
    double z1 = 2.2;
    float z2 = 1.1F;
    z2 = z2;
    // // error, because of double and float in template
    // std::cout << "\nDie kleinere Zahl: " << minimum(z1, z2) << std::endl;
    double z3 = 1.1;
    std::cout << "\nz1 = " << z1 << " z3 = " << z3 << std::endl;
    std::cout << "Smaller number: " << minimum(z1, z3) << std::endl; // Aufruf o.k.
    return 0;
}