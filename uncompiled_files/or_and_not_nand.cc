#include <iostream>
// using namespace std;

// 0110 - 6 or
// 0011 - 3
// 0111 - 7

// 0110 - 6 and
// 0011 - 3
// 0010 - 2

// 4 bit unsigned
// 1001 - 9  (~6) and
// 1100 - 12 (~3)
// 1000 - 8
// 0111 - 7  (~8)

// 8 bit unsigned
// 1111 1001 - 249 - (~6)   - and
// 1111 1100 - 252 - (~3)
// 1111 1000 - 248
// 0000 0111 - 7   - (!248)

//      1111 -7

int main (){
    uint8_t x = 6, y = 3;

    std::cout << "x or y: " << (x | y) << std::endl;
    std::cout << "~x: " << ~x << std::endl;
    std::cout << "~y: " << ~y << std::endl;
    std::cout << "~(~x and ~y): " << ~(~x & ~y) << std::endl;

    return 0;
}
