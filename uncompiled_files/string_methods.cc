#include <iostream>

int main (){
    std::string s("i am a string"); // instantiation of s as a string variable with an initial value
    std::cout << s << "\n\0";
    std::cout << s.length() << "\n\0";
}