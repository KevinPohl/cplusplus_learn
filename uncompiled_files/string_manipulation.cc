
#include <iostream>
#include <iomanip>

int main(){
int WIDTH = 25, temp;


std::string s1("Miss Summer");
std::cout << std::setw(WIDTH) << "before: " << s1 << std::endl;

// insert into string
s1.insert(5, "Valerie ");
std::cout << std::setw(WIDTH) << "after insert: " << s1 << std::endl;

// erase
s1.erase(4, 8);
std::cout << std::setw(WIDTH) << "after erase: " << s1 << std::endl;

// replace
s1.replace(0, 4, "Mister");
std::cout << std::setw(WIDTH) << "after replace: " << s1 << std::endl;

// replace with extract
s1.replace(9, 2, "Muppet", 2, 2);

// find
temp = s1.find("er");
std::cout << std::setw(WIDTH) << "find 'er' from left: " << temp << std::endl;

// find
temp = s1.rfind("er");
std::cout << std::setw(WIDTH) << "find 'er' from right: " << temp << std::endl;

// extract charwise
temp = s1[4];
std::cout << std::setw(WIDTH) << "5th of string: " << (char)temp << std::endl;

for (long long unsigned int i=0; i < s1.length(); i++){
    std::cout << s1[i] << " ";
}
std::cout << std::endl;

// last char
temp = s1[s1.length()-1];
std::cout << std::setw(WIDTH) << "last character: " << (char)temp << std::endl;

// replaced last char
s1[s1.length()-1] = 'n';
std::cout << std::setw(WIDTH) << "replaced last character: " << s1 << std::endl;

// index out of bounds
temp = s1[s1.length()];
std::cout << std::setw(WIDTH) << "index 1 after last: " << (char)temp << std::endl;

// // index out of bounds with at
// temp = s1.at(s1.length()); // throws out_of_range exception
// std::cout << std::setw(WIDTH) << "index 1 after last (with .at): " << (char)temp << std::endl;

// replace values with empty char

s1.replace(0, 7, "");
s1.replace(3, 1, "");
s1.replace(4, 1, "r");
std::cout << std::setw(WIDTH) << "erased via replace: " << s1 << std::endl;

std::cout << std::setw(WIDTH) << "substring: " << s1.substr(0, 3) << std::endl;


return 0;
}