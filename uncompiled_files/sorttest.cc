#include <algorithm>
#include <array>
#include <vector>
#include <functional>
#include <iostream>
#include <string_view>
 
void print (std::string title, std::array<int, 10> array)
{
    std::cout << title << ' ';
    for (int element : array)
        std::cout << "" << element << ", ";
    std::cout << std::endl;
};

struct sometype {std::string name; int id;};

void print_v (std::string title, std::vector<sometype> vect)
{
    std::cout << title << ' ';
    for (sometype element : vect)
        std::cout << "" << element.id << ", ";
    std::cout << std::endl;
};

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    print("unsorted", s);
 
    std::sort(s.begin(), s.end());
    print("sorted with the default operator<", s);
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object", s);
 
    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    }
    customLess;
 
    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object", s);
 
    std::sort(s.begin(), s.end(), [](int a, int b){return a > b;});
    print("sorted with a lambda expression", s);

    std::vector<sometype> v = {{"John", 1}, {"Jim", 2}};
    print_v("vector with struct", v);
}