#include <iostream>
const double pi = 3.141593; // const == read only

// volatile == variable is read in on every read, because alien programs can change the variable value
// so the variable is constantly marked as "dirty"
volatile double pi2 = 3.14159; 

// the combination of const and volatile means, the value of the variable can only be changed from outside the program
const volatile double pi3 = 3.1415; 

int main(){
    double area, circumference, radius = 1.5;
    area = pi * radius * radius;
    circumference = 2 * pi * radius;
    std::cout << "calculation of area:\n";
    std::cout << "radius:\t" << radius << std::endl;
    std::cout << "circ.:\t" << circumference << std::endl;
    std::cout << "area:\t" << area << std::endl;
    return 0;
}