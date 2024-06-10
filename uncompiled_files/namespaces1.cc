// define and test namespaces
//------------------------------------------------------------------------------
#include <string>           // string in namespace std
namespace MySpace
{
    std::string output = "In namespace MySpace";
    int count = 0;          // definition: MySpace::count
    double f(double);       // prototype: MySpace::f()
}

namespace YourSpace
{
    std::string output = "In namespace YourSpace";
 
    // Definition von YourSpace::f()
    void f()
    {
        output+= '!';
    }
}

// back in MySpace.
namespace MySpace
{
    int g(void);            // prototype of MySpace::g()
    double f(double y)      // definition of MySpace::f()
    { return y / 10.0; }
}

    // separate definition of MySpace::g() 
    int MySpace::g()
    {
        return ++count;
    }

#include <iostream>         // cout, ... in namenspace std

int main()
{
    std::cout << "test namespaces!\n\n"
        << MySpace::output << std::endl;
    MySpace::g();
    std::cout << "\nreturn-value g(): " << MySpace::g()
        << "\nreturn-value f(): " << MySpace::f(1.2)
        << "\n---------------------" << std::endl;
    YourSpace::f();
    std::cout << YourSpace::output << std::endl;
    return 0;
}
//------------------------------------------------------------------------------