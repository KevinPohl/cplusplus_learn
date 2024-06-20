// fcopy1.cc : copies files
// Aufruf: fcopy1 source_file [ destination_file ]
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

inline void openerror(const char *file)
{
    cerr << "Error on opening of " << file << endl;
    exit(1); // closes the program and all open files
}

void copy(istream& is, ostream& os); // prototype

int main(int argc, char *argv[])
{
    if(argc < 2 || argc > 3)
    {
        cerr << "Aufruf: fcopy1 quelldatei [ zieldatei ]" << endl;
        return 1; // or: exit(1);
    }

    ifstream infile(argv[1]); // 1. open file
    if(!infile.is_open())
        openerror( argv[1]);
    if( argc == 2) // only one source file
        copy( infile, cout);
    else // source and destination file
    {
        ofstream outfile(argv[2]); // 2. open file
        if(!outfile.is_open() )
            openerror(argv[2]);
        copy(infile, outfile);
        outfile.close(); // unnecessary here
    }
    infile.close(); // unnecessary here
    return 0;
}

void copy(istream& is, ostream& os) // copy is to os
{
    char c;
    while(is.get(c))
        os.put(c); // or: os << c;
}