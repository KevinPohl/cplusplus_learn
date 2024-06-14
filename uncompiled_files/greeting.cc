// demoprogram for arguments from command line
// Call: .\\greeting name1 name2
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if( argc != 3 )
    {
        cerr << "Usage: .\\greeting name1 name2" << endl;
        return 1;
    }
    cout << "Hello " << argv[1] << '!' << endl;
    cout << "Greetings\n" << "\tYour " << argv[2] << endl;
    return 0;
}