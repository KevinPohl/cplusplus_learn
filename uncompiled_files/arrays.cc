#include <iostream>
#include <tuple>
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


// test vector of vector with different types - not possible with std::vector

std::vector<int> vect_b {1,2,3,4};

// std::vector<std::string> vect_c {"abc","def","a","de","ab"};
std::vector<int> vect_c {15,14,13,12,11};

std::vector<std::vector<int>> vect_a;

vect_a.push_back(vect_b);
vect_a.push_back(vect_c);

std::cout << "size vect_a   : " << vect_a.size() << std::endl;
std::cout << "size vect_a[0]: " << vect_a[0].size() << std::endl;
std::cout << "size vect_a[1]: " << vect_a[1].size() << std::endl;

// walk a 2d array regardless of dim sizes
for(unsigned long long i=0; i<vect_a.size(); i++){
    for(unsigned long long j=0; j<vect_a[i].size(); j++){
        std::cout
            << "vector vect_a[" << i << "][" << j << "]: " // vector vect_a[0][0]: 
            << vect_a[i][j] << std::endl;
    }
}

// example for tuple building
std::vector<std::string> categories {
    "sentence count",
    "word count",
    "letter count",
    "numerical count",
    "whitespace count",
    "punctuation count",
    "mean letters per word"
    };

std::vector<float> values {
    (float)48,
    (float)20,
    (float)104,
    (float)1,
    (float)19,
    (float)3,
    (float)104/(float)20
    };

// walk the 2 vectors concurrently
for(unsigned long long i=0; i<values.size(); i++){
    // 0: sentence count | 14 | 1 
    std::cout << i << ": "
        << categories[i] << " | "
        << categories[i].length() << " | "
        << values[i] << std::endl;
}

std::tuple<decltype(categories), decltype(values)> data = make_tuple(categories, values);
unsigned long long int tsize = std::tuple_size<decltype(data)>::value;
std::cout << "tsize: " << tsize << std::endl;
for (unsigned long long int i; i < tsize; i++){}

// // some error with std::get
// for (unsigned long long i; i < tsize; i++){
// decltype(categories) abc = std::get<i>(data);
// for (unsigned long long j; j < abc; j++){
// } // end for abc
// } // end for tsize

stay_alive();
return 0;
} // end main

//-----------------------------------------------------------------------------| 80 chars
