#include <iostream>
#include <limits>
#include <string>

// keeps the terminal window alive and can be exited with enter or any other key
// if cin was used in before cinned = true
// >>> stay_alive(true)
// else stay_alive(false), which is standard
void stay_alive(bool cinned=false){
    std::cout << "\n<any key to close>\n";
    if (cinned){
        char garbage;
        std::cin.get(garbage);
    }
    std::string str;
    std::getline(std::cin, str);
}