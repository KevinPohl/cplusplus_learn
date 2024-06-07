#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

#include "stay_alive.h"

auto bitter(int x) -> std::bitset<8>
{
    std::bitset<8> bit(x);
    return bit;
} // end bitter

void tabprinter(
    int value,
    std::string prompt,
    bool plus_op=true,
    bool and_op=false,
    bool not_op=false,
    int val_width = 4,
    int line_len = 60
    )
{

std::string line(line_len, '-');

int temp = value;
std::cout << bitter(temp) << " | " << std::setw(val_width) << temp << " | x" << std::endl;

if (not_op){
    temp = ~value;
    std::cout << bitter(temp) << " | " << std::setw(val_width) << temp << " | ~x" << std::endl;
}

if (plus_op){
    temp = value + 1;
    std::cout << bitter(temp) << " | " << std::setw(val_width) << temp << " | x + 1" << std::endl;
} else {
    temp = value - 1;
    std::cout << bitter(temp) << " | " << std::setw(val_width) << temp << " | x - 1" << std::endl;
}

if (and_op) {
    temp = (not_op ? ~value : value) & (value + (plus_op ? 1 : -1));
    std::cout << bitter(temp) << " | " << std::setw(val_width) << temp
        << " | " << (not_op ? "~" : "") << "x & (x " << (plus_op ? "+" : "-") << " 1)" << std::endl;
} else {
    temp = (not_op ? ~value : value) | (value + (plus_op ? 1 : -1));
    std::cout << bitter(temp) << " | " << std::setw(val_width) << temp 
        << " | " << (not_op ? "~" : "") << "x | (x " << (plus_op ? "+" : "-") << " 1)" << std::endl;
}
std::cout << prompt << std::endl;
} // end tabprinter

int main()
{
int line_len = 60;
std::string line(line_len, '-');
int WIDTH = 4;

std::ostringstream header;
header << std::setw(8) << "bin"
    << " | "
    << std::setw(WIDTH) << "dec"
    << " | "
    << std::setw(12) << std::left << "formula"
    << std::endl;
std::cout << header.str();

// (x & (x - 1))
tabprinter(
    16,     // used value
    "turns off rightmost bit\ncan be used to check for power of 2 == 0, but 0 has to be filtered",
    false,   // true = plus operation | false = minus operation
    true,  // true = and operation | false = or operation
    false,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (x | (x + 1))
tabprinter(
    16,     // used value
    "turns on rightmost 0-bit",
    true ,  // true = plus operation | false = minus operation
    false,  // true = and operation | false = or operation
    false,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (x & (x + 1))
tabprinter(
    51,     // used value
    "turns off trailing bits",
    true ,  // true = plus operation | false = minus operation
    true ,  // true = and operation | false = or operation
    false,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (x | (x - 1))
tabprinter(
    52,     // used value
    "turns on trailing bits",
    false,  // true = plus operation | false = minus operation
    false,  // true = and operation | false = or operation
    false,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (~x & (x + 1))
tabprinter(
    13,     // used value
    "turns on rightmost 0-bit, everything else 0",
    true ,  // true = plus operation | false = minus operation
    true ,  // true = and operation | false = or operation
    true ,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (~x | (x - 1))
tabprinter(
    168,     // used value
    "turns off rightmost 1-bit, everything else 1",
    false,  // true = plus operation | false = minus operation
    false,  // true = and operation | false = or operation
    true ,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (~x & (x - 1))
tabprinter(
    168,     // used value
    "turns trailing zeros to one, everything else to zero",
    false,  // true = plus operation | false = minus operation
    true,  // true = and operation | false = or operation
    true ,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

// (~x | (x + 1))
tabprinter(
    171,     // used value
    "turns trailing ones to zero, everything else to one",
    true ,  // true = plus operation | false = minus operation
    false,  // true = and operation | false = or operation
    true ,  // true = not x | false = x
    WIDTH,
    line_len
    );

std::cout << line << std::endl;

int x, temp;

// (x & (-x))
x = 160;
temp = x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x" << std::endl;
// temp = ~x;
// std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | ~x" << std::endl;
temp = -x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | -x" << std::endl;
temp = x & (-x);
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x & (-x)" << std::endl;
std::cout << "isolate rightmost 1-bit" << std::endl;

std::cout << line << std::endl;


// (x ^ (x-1)) // ^ is bitwise equivalence
x = 88;
temp = x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x" << std::endl;
temp = x-1;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x-1" << std::endl;
temp = x ^ (x-1);
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x ^ (x-1)" << std::endl;
std::cout << "find rightmost 1-bit and put a trail of 1 including that bit\neverything else to 0" << std::endl;

std::cout << line << std::endl;


// (x ^ (x+1))
x = 87;
temp = x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x" << std::endl;
temp = x-1;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x-1" << std::endl;
temp = x ^ (x+1);
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x ^ (x+1)" << std::endl;
std::cout << "find rightmost 1-bit and put a trail of 1 including that bit\neverything else to 0" << std::endl;

std::cout << line << std::endl;


// (((x & (-x)) + x) & x)
x = 92;
temp = x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | x" << std::endl;
temp = -x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | -x" << std::endl;
temp = ((x & (-x)) + x) & x;
std::cout << bitter(temp) << " | " << std::setw(WIDTH) << temp << " | ((x & (-x)) + x) & x" << std::endl;
std::cout << "turn off rightmost contiguous string of 1-bits" << std::endl;

std::cout << line << std::endl;





// stay_alive();
return 0;
} // end of main