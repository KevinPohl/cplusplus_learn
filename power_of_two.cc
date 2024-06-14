#include <iostream>
#include <cmath>

bool isPowerOfTwo_log2(unsigned int x)
{
    if (x == 0) {return false;}
    return log2(x) == floor(log2(x));
}

bool isPowerOfTwo(unsigned int x)
{
    if (x == 0) {return false;}
    return (x & (x - 1)) == 0;
}


int main()
{
    // int i = 32;
    // std::cout << "is a power of two (" << i << "): " << std::boolalpha << isPowerOfTwo(i) << std::endl;
    
    // i = 0;
    // std::cout << "is a power of two (" << i << "): " << std::boolalpha << isPowerOfTwo(i) << std::endl;
    
    // i = 1;

    for (int i=-10; i<20; i++)
    {
    std::cout << "is a power of two (" << i << "): " << std::boolalpha << isPowerOfTwo_log2(i) << std::endl;
    }

    for (int i=-10; i<20; i++)
    {
    std::cout << "is a power of two (" << i << "): " << std::boolalpha << isPowerOfTwo(i) << std::endl;
    }

    return 0;
}