#include <iostream>
#include <iomanip> 
#include <string>
// using namespace std;

int main(){
    int i1, i2;
    double d1, d2;

    std::cout << "Input two integers: "; // << std::endl;
    std::cin >> i1 >> i2;
    std::cout << "Input two doubles: "; // << std::endl;
    std::cin >> d1 >> d2;

    std::cout << "Formatted integers: " << std::setw(10)
        << i1 << std::setw(10) << i2 << std::endl;
    std::cout << "Formatted doubles: " << std::setprecision(5)
        << std::scientific << d1 << " " << d2 << std::endl;

    std::cout << std::boolalpha << true << std::endl;
    std::cout << std::setw(5) << std::setfill('.') << std::internal << 'a' << std::endl;
    std::cout << std::setw(20) << std::left << "teststr" << std::endl;

    return 0;
}