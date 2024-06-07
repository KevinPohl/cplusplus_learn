// from google styleguide https://google.github.io/styleguide/cppguide.html
//-----------------------------------------------------------------------------| 80 chars only
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

int main(){
    int col1(21), col2(20), col3(7);
    // outputstringstream is more appropriate than stringstream
    std::ostringstream columnnames, breakline;
    columnnames
        << std::setw(col1) << std::left << "cast/conv"
        << std::setw(col2) << std::left << "example"
        << std::setw(col3) << std::left << "value"
        << std::endl;
    std::cout << columnnames.str();

    // calculates length of stringstream columnnames, including whitespace
    // and creates a line of '-' chars of the same length
    breakline << std::string(columnnames.str().length(), '-') << std::endl;
    std::cout << breakline.str();
    // casting is a lossless molding of data into a non-standard type
    // each character is put in integers, at no loss
    std::string str = "hello";
    int cast_from_string = (int)(char)str[0];
    // int cast_from_string = (int)str[0]; // implicit casting string to char
    std::cout
        << std::setw(col1) << std::left << "str to char to int"
        << std::setw(col2) << std::left << "hello -> h -> 104"
        << std::setw(col3) << std::left << cast_from_string
        << std::endl;
    
    // conversion is a recalculation with possible loss
    // the float is rounded down to 3 for integer conversion
    // for rounding (int)3.5+0.5 is possible
    int conversion_from_float = (int)3.5;
    std::cout
        << std::setw(col1) << std::left << "float to int"
        << std::setw(col2) << std::left << "3.5 -> 3"
        << std::setw(col3) << std::left << conversion_from_float
        << std::endl;

    // because of that ambiguity in loss and lossless conversion/casting,
    // google writes the two differently:

    // casting for arithmetics: code will not compile if loss is possible
    int cast_from_string2 = int64_t{'h'};
    std::cout
        << std::setw(col1) << std::left << "char to int64"
        << std::setw(col2) << std::left << "'h' -> 104"
        << std::setw(col3) << std::left << cast_from_string2
        << std::endl;
    // std::cout << cast_from_string2 << std::endl;


    // 

    return 0;
}