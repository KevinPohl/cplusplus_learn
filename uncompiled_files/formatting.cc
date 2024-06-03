#include <iostream>
int abc = 0;
int plus_three(int someint){
    return someint + 3;
}

int main(){
    int x = plus_three(8);
    // int
    std::cout << "int dec: " << x << "\n";
    std::cout << std::dec << "int dec: " << x << " (explixit) \n";
    std::cout << std::hex << "int hex: " << x << "\n";
    std::cout << std::oct << "int oct: " << x << "\n";

    // float
    std::cout << std::dec << "float 13.3 dec: " << 13.3 << "\n";
    std::cout << std::hex << "float 13.3 hex: " << 13.3 << "\n"; // does nothing
    std::cout << std::dec << "float 3e-2 dec: " << 3e-2 << "\n";
    std::cout << std::oct << "float 3e-2 oct: " << 3e-2 << "\n"; // does nothing

    // hex
    std::cout << "hex 13h: " << "13h" << "\n";


    // oct
    std::string octal = "\013";
    std::cout << std::dec << "oct \013: " << octal << std::endl; // does nothing

    // multiline strings
    std::string mls = "multiline\
 string\0";
    std::cout << mls << "\n";
    std::cout << "multiline \
string\n";

}