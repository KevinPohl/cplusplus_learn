// demoprogram for arguments from command line
// Call: .\greeting name1 name2
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

// main with arguments
// argc is count of args, argv is vector of arg values
// first argument is program name itself, greeting in this case
// argv[0] program name
// argv[1] first arg
// argv[2] second arg
// argv[argc-1] last arg
// argv[argc] null pointer

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cerr << "Usage: .\\greeting name1 name2" << endl;
        return 1;
    }
    cout << "Hello " << argv[1] << '!' << endl;
    cout << "Greetings\n" << "\tYour " << argv[2] << endl;
    return 0;
}