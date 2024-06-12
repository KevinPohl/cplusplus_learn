// activate or deaktivate methods
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class DefaultDeleteDemo
{
    double val;
    public:
    // activate default constructor
    DefaultDeleteDemo() = default;

    // double constructor
    DefaultDeleteDemo(double x) {val = x;}

    // don't allow int argument
    DefaultDeleteDemo(int x) = delete;

    // don't allow copy constructor assignment
    DefaultDeleteDemo( const DefaultDeleteDemo& n) = delete;
    DefaultDeleteDemo& operator=(const DefaultDeleteDemo& n) = delete;
    
    // assignment methods
    double getVal() const {return val;}
    void setVal(double x) {val = x;}

    // don't allow int argument
    void setVal(int x) = delete;
};

int main()
{
    DefaultDeleteDemo ddObj1,   // default constructor
    ddObj2(2.2);                // double constructor
    ddObj1.setVal(1.1);
    cout << "Values: \n" << ddObj1.getVal() << " " << ddObj2.getVal() << endl;

    // // these produce an exception at compile time
    // ddObj1 = ddObj2;            // assignment not allowed
    // DefaultDeleteDemo ddObj3(ddObj2), // copy constructor not allowed
    // ddObj4(100);                // int constructor not allowed
    // ddObj1.setVal(200);         // int arg not allowed
    return 0;
}