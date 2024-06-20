//------------------------------------------------------------------------------
#include <iostream>
#include "daytime_operator_overloading.h"

int main ()
{
    DayTime departure1(11, 11, 11), departure2(12,0,0), departure3;

    if(departure1 < departure2)
        std::cout << "\nFirst flight takes off earlier!" << std::endl;
    else
        std::cout << "\nSecond flight takes off earlier!" << std::endl;
    
    departure3 = departure1 + departure2;
    departure3.print();

    return 0;
 }