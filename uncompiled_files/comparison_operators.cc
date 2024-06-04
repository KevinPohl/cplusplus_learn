#include <iostream>
#include <compare>
#include <iomanip>
using namespace std;

int main(){
    int i(5), j(8);
    float k(4.4), l;

    std::cout << "i==j: " << (i==j) << std::endl;
    std::cout << "i!=j: " << (i!=j) << std::endl;

    l = j;

    std::cout << "l: " << l << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "l==k: " << boolalpha << (l==k) << std::endl;
    // problem are 4.0 and .4 which are not interpreted as float
    std::cout << "l-4==k-.4: " << noboolalpha << ((l-4.0)==(k-.4)) << std::endl;
    std::cout << "l-4==k-.4: " << noboolalpha << (l-(float)4.0==k-(float).4) << std::endl; // this
    std::cout << "l-4==k-.4: " << noboolalpha << (float(l-4.0)==float(k-.4)) << std::endl; // or this

    float a(l-4), b(k-.4);
    std::cout << "l-4==k-.4: " << boolalpha << (a==b) << std::endl;
    return 0;
}