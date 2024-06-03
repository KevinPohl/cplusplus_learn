#include <iostream>
#include <string>
// using namespace std;

int main(){
    // define 4 strings
    std::string prompt("What's your name: "),
        name,                   // empty
        line(40, '-'),          // String with '-'
        total = "Hello ";       // possible as well

    std::cout << prompt;
    std::getline(std::cin, name); // read one row
    total = total + name; // concatenate string, alternatively with + and += possible
    std::cout << line << std::endl << total << std::endl;
    std::cout << "Your name has " << name.length() << " characters." << std::endl;
    std::cout << line << std::endl;

    return 0;
}