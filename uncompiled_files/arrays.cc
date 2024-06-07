#include <iostream>
#include <array>
#include <vector>

#include "stay_alive.h"

int main(){
// // works with chars but not strings, saves int of char
// // this array is initialized with size and values
// int array1[5] = {'a', 'c', 'b', 'a', 'a'};

// // this works
// // this array is initialized with size and values
// std::string array1[5] = {"abc", "ccb", "bcb", "acb", "acb"};

// // string can't be conversed to int
// int array1[5] = {"abc", "ccb", "bcb", "acb", "acb"};


// // this array is initialized without size but with values, both are equal
// int array1[] = {1, 2, 3, 4, 5};
int array1[] {1, 2, 3, 4, 5};
std::cout << "first entry of C-Style array1: " << array1[1] << std::endl;
// int size {std::extent<decltype(array1)>::value};
int size = std::extent<decltype(array1)>::value;
std::cout << "new measure for size of C-Style array1: " << size << std::endl;

// those are all C arrays, c++ array are found here: #include <array>
std::array<int, 3> cpparray {3, 4, 5};
std::cout << "size of array cpparray: " << cpparray.size() << std::endl;
// initialize an array with a constexpr
constexpr int len {8};
std::array<int, len> arr2 {};
std::cout << "size of array arr2: " << arr2.size() << std::endl;


// if a non-fixed size array is needed, a vector has to be used instead
// #include <vector>

// std::vector<int> vect1(4);
// vect1 = {1,2,3,4,5};
// std::vector<int> vect1 = {1,2,3,4,5}; // alternatively
std::vector<int> vect1 {1,2,3,4,5}; // alternatively

for(unsigned long long i = 0; i < vect1.size(); i++){
        std::cout << "vector vect1[" << i << "]: ";
        std::cout << " " << vect1[i] << std::endl;
}

std::cout << "size of vector vect1: " << vect1.size() << std::endl;
std::cout << "back of vector vect1: " << vect1.back() << std::endl;
std::cout << "begin of vector vect1: " << vect1[0] << std::endl;

std::cout << "push_back and resizing..." << std::endl;
vect1.push_back(8); // insert value after last
// vect1.pop_back(); // delete last
vect1.resize(4);
vect1.resize(10);

std::cout
    << "length after deletion of last entry of vect1: "
    << vect1.size()
    << std::endl;
std::cout
    << "back of vector vect1: "
    << vect1.back()
    << std::endl;

for(unsigned long long i = 0; i < vect1.size(); i++){
        std::cout << "vector vect1[" << i << "]: ";
        std::cout << " " << vect1[i] << std::endl;
}

stay_alive();
return 0;
} // end main

//-----------------------------------------------------------------------------| 80 chars
