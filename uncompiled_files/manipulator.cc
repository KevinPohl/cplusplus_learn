#include <iostream>
#include <ios>

// using namespace std;

int main(){
    std::cout << std::showpos << 123 << std::endl;

    // same as the following (this happens under the hood)
    std::cout.setf(std::ios::showpos);
    std::cout << 123 << std::endl;

    // all following couts are treated the same
    std::cout << 22 << std::endl;
    std::cout << 22 - 30 << std::endl;

    // reset show positive sign
    std::cout << std::noshowpos << 22 << std::endl;

    // same as this
    std::cout.unsetf(std::ios::showpos);
    std::cout << 22 << std::endl;

    return 0;
}