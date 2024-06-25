#include <string>
#include <iostream>
// using namespace std;

class MathError
{
    private:
        std::string message;
    
    public:
        MathError(const std::string& s) : message(s) {}
        const std::string& getMessage() const {return message;}
};

double calc( int a, int b ); // possible Exception: MathError

int main()
{
    int x, y; bool flag = false;
    do
    {
        try // try-Block
        {
            std::cout << "Zwei positive ganze Zahlen eingeben: ";
            std::cin >> x >> y;
            std::cout << x <<"/"<< y <<" = "<< calc( x, y) << '\n';
            flag = true; // leave loop
        }
        catch(MathError& err) // catch block
        {
            std::cerr << err.getMessage() << std::endl;
        }
    } while(!flag);
    // continue the program...
    return 0; 
}

double calc(int a, int b)
{
    if (b < 0)
    throw MathError("Denominator is negative!");
    if (b == 0)
    throw MathError("Division of 0!");
    return static_cast<double>(a/b);
}