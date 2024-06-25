// calc_err.cpp: Definition der Funktion calc(),
// die Exceptions auslöst.
//------------------------------------------------------------------------------
#include <iostream>
class Error
{
    // Info on source of error. None here.
};

double calc(int a, int b)
{
    if (b < 0)
        // throw (std::string)"Denominator is negative!";
        throw static_cast<std::string>("Denominator is negative!");
    if (b == 0)
    {
        Error errorObj;
        throw errorObj;

        // // alternatively
        // throw Error();
    }
    return static_cast<double>(a/b);
    
}




// calc_err.cpp: Test der Funktion calc(),
// die Exceptions auslöst.
// ----------------------------------------------------
// #include <iostream>
// #include <string>
// using namespace std;
double calc( int a, int b );
// class Error { };

int main()
{
    // no error: returns 5
    std::cout << calc(10, 2) << std::endl;
    
    // // terminate called after throwing an instance of 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >'
    // std::cout << calc(10, -2) << std::endl;
    
    // // terminate called after throwing an instance of 'Error'
    // std::cout << calc(10, 0) << std::endl;
    
    int x, y;
    double result;
    bool flag = false;
    
    do
    {
        try // try-Block
        {
            std::cout << "please input two positive integer: ";
            std::cin >> x >> y;
            result = calc(x, y);
            std::cout << x << "/" << y << " = " << result << std::endl;
            flag = true; // leave loop
        }
        catch( std::string& s) // first catch block
        {
            std::cerr << s << std::endl;
        }
        catch( Error& ) // second catch block
        {
            std::cerr << "Division by 0! " << std::endl;
        }
        catch(...) // third catch block
        {
            std::cerr << "Unexpected Exception! \n";
            exit(1);
        }
    } while(!flag);

    // continue the program...
    return 0;
}