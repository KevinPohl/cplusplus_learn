#include <iostream>
#include <climits> // Definition von INT_MIN, ...
// #include <limits.h>
using namespace std; // not needed if referenced as std::string no namespace collisions

std::string tabber(std::string str){
    std::string final;
    
    // if normal
    if (str.length() > 15) {
        final = "\t";
    } else if (str.length() > 9) {
        final = "\t\t";
    } else {
        final = "\t\t\t";
    }

    // // if shorthand
    // final = (str.length() < 10) ? "\t\t\t" : "\t\t";

    return final;
}

std::int8_t scoreliner(){
    std::string scoreline = "--------------------------------------------------------------------\n";
    std::cout << scoreline << std::flush;
    return 0;
}

int main()
{
    std::string name;

    std::cout << "Range of types\n\n" << std::flush;
    std::cout << "Type\t\t\tMinimum\t\t\tMaximum\n" << std::flush;
    scoreliner();

    // char
    name = "char";
    std::cout << name << tabber(name) << CHAR_MIN << "\t\t\t" << CHAR_MAX << std::endl;

    name = "signed char";
    std::cout << name << tabber(name) << SCHAR_MIN << "\t\t\t" << SCHAR_MAX << std::endl; 

    name = "unsigned char";
    std::cout << name << tabber(name) << "0" << "\t\t\t" << UCHAR_MAX << std::endl;

    scoreliner();

    // int
    name = "signed int";
    std::cout << name << tabber(name) << INT_MIN << "\t\t" << INT_MAX << std::endl; 

    name = "unsigned int";
    std::cout << name << tabber(name) << "0" << "\t\t\t" << UINT_MAX << std::endl;

    scoreliner();

    // short
    name = "signed short";
    std::cout << name << tabber(name) << SHRT_MIN << "\t\t\t" << SHRT_MAX << std::endl; 

    name = "unsigned short";
    std::cout << name << tabber(name) << "0" << "\t\t\t" << USHRT_MAX << std::endl;

    scoreliner();
    
    // long
    name = "signed long";
    std::cout << name << tabber(name) << LONG_MIN << "\t\t" << LONG_MAX << std::endl; 

    name = "unsigned long";
    std::cout << name << tabber(name) << "0" << "\t\t\t" << ULONG_MAX << std::endl;

    scoreliner();
    
    // long long
    name = "signed long long";
    std::cout << name << tabber(name) << LLONG_MIN << "\t" << LLONG_MAX << std::endl; 

    name = "unsigned long long";
    std::cout << name << tabber(name) << "0" << "\t\t\t" << ULLONG_MAX << std::endl;

    scoreliner();

    return 0;
}