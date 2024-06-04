#include <iostream>
#include <string>

int main(){
    int inum1, inum2;
    float fnum1, fnum2;
    std::cout << "Give first number: ";
    std::cin >> fnum1;
    inum1 = fnum1;

    std::cout << "Give second number: ";
    std::cin >> fnum2;
    inum2 = fnum2;

    std::cout << "integer of numbers: " << inum1 << ", " << inum2 << std::endl;
    std::cout << "float of numbers: " << fnum1 << ", " << fnum2 << std::endl;
    
    // line of 40 dashes
    std::cout << std::string(40, '-') << std::endl;

    // + addition
    std::cout << "sum of int: " << inum1 + inum2 << std::endl;
    std::cout << "sum of float: " << fnum1 + fnum2 << std::endl;

    // - substraction
    std::cout << "substraction of int: " << inum1 - inum2 << std::endl;
    std::cout << "substraction of float: " << fnum1 - fnum2 << std::endl;

    // * multiplication
    std::cout << "multiplication of int: " << inum1 * inum2 << std::endl;
    std::cout << "multiplication of float: " << fnum1 * fnum2 << std::endl;

    // / division
    std::cout << "division of int: " << inum1 / inum2 << std::endl;
    std::cout << "division of float: " << fnum1 / fnum2 << std::endl;

    // % modulo
    std::cout << "modulo of int: " << inum1 % inum2 << std::endl;
    // std::cout << "modulo of float: " << fnum1 % fnum2 << std::endl; // modulo has to be int


    return 0;
}