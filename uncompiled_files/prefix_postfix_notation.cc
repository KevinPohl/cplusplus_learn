#include <iostream>

int main(){
    int i(2), j(8);
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j--: " << j-- << std::endl;
    std::cout << "--j: " << --j << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i: " << i << std::endl;

    return 0;
}