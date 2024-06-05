#include <iostream>
#include <iomanip>

void print_calculations(int x, int y){
    std::cout
        << std::left
        << std::setw(12) << "sum"
        << std::setw(12) << "difference"
        << std::setw(12) << "product"
        << std::setw(12) << "quotient"
        << std::endl;

    std::cout
        << std::left
        << std::setw(12) << x+y
        << std::setw(12) << x-y
        << std::setw(12) << x*y
        << std::setw(12) << x/y
        << std::endl;
}

int main(){
    int a=15, b=4;
    print_calculations(a, b);
    print_calculations(++a, --b);
    
    std::cout << std::boolalpha
        << "a is greater than b: "
        << (a>b)
        << std::endl;
    
    std::cout << std::boolalpha
        << "a is greater than 10 and b is lesser than 5 simultaneously: "
        << (a>10 && b<5)
        << std::endl;

    std::cout
        << "a + b + 2.5: "
        << a + b + 2.5
        << std::endl;

    return 0;
}