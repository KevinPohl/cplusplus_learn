#include <iostream>
#include <iomanip>

int main(){
    int x, count = 0;
    float sum;

    std::cout << "Please input integers:\n"
        "(cancel with any alpha)"
        << std::endl;

    // while loop
    while( std::cin >> x ){
        sum += x;
        ++count;
    }

    std::cout << "Mean of numbers: "
        << sum / count << std::endl;

    // std::fixed fills all following decimals with zero, standard is 6 places
    // std::setprecision changes those places (after point)
    std::cout << std::fixed << std::setprecision(4);
    // for loop
    for(int euro = 1; euro <= 5; ++euro) {
        std::cout << "\t" << euro * 1.005 << "\t" << std::endl;
    }

    // do while is executed once regardless of while condition
    int i=0;
    do {
        std::cout << "hi\n", ++i;
    } while (i<5);
    std::cout << "done.";
    
    return 0;
}