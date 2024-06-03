#include <iostream>
#include <sstream>
#include <list>
using namespace std;

int main(){
    int x, o = 000, d=0, h=0x0; // start octal with a zero, decimal normal, hex with 0x or 0X
    std::string y;
    std::cout << "Give an integer: ";
    std::cin >> x;
     
    
    std::stringstream strm;
    strm << x;
    strm >> y;

    std::cout << std::uppercase // upper or lowercase for hex values
            << "   octal   \t  decimal  \thexadecimal\n"
            << std::oct << x << "\t\t"
            << std::dec << x << "\t\t"
            << std::hex << x << std::endl;

    list<string> columns = {"octal", "decimal", "hexadecimal"};
    o += x;
    d += x;
    h += x;
    list<int> values = {o, d, h};
    for (int i : values){
        cout << dec << i << std::endl;
        // is given in as oct, dec, hex but given out as dec, dec, dec here
        // stored as binary, printed as dec as standard
    }


    // '<<' can give out short, int, long, signed or unsigned


    return 0;
}