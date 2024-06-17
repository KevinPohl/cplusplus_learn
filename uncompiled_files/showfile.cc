// reads a textfile and prints pagewise, aka in 20 line iterations
// call: showfile filename
// call here: .\showfile filename
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2) // was a file given?
    {
        cerr << "Usage: showfile filename" << endl;
        return 1;
    }

    ifstream file(argv[1]); // create File-Stream and open file to read

    if(!file) // get status
    {
        cerr << "Error on opening file " << argv[1] << endl;
        return 2;
    }

    char line[80];
    int count = 0;

    while(file.getline(line, 80)) // copy file to standard output
    {
        cout << line << endl;
        if(++count == 20)
        {
            count = 0;
            cout << "\n\t ---- Continue with <Return> ---- " << endl;
            cin.get();
        }
    }

    if(!file.eof()) // End of file reached?
    {
        cerr << "Error while reading file " << argv[1] << endl;
        return 3;
    }

    return 0;
}