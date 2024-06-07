#include <iostream>
using namespace std;
auto add(float, float) -> double;
// alternatively:
// double add(float, float);

// Definition of function sub()
auto sub(float x, float y)
{
    // return type is double, because expression x-y has type double
    return x - y;
}

// Definition of recursive function powerOf2()
auto powerOf2(unsigned n)
{
    if (n == 0)
    // any return has to come before recall of self in recursive functions
    // to define the return type (here long long int)
    return 1LL; // return type is long long
    else
    return 2 * powerOf2(n - 1);
}

int main()
{
    float a = 1.2F, b = 3.4F;
    double sum = add(a, b);
    cout << "Sum of " << a << " and " << b << " is "
    << sum << endl; // 4.6
    cout << "Difference of " << a << " and " << b
    << " is " << sub(a, b) << endl; // -2.2
    cout << "2 to the power of 5 is " << powerOf2(5) << endl; // 32
    return 0;
}

auto add( float x, float y) -> double
{
    return x + y;
}