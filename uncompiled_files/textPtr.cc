// char-Vectors and char-Pointer
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    cout << "Demo with char-Vectors and char-Pointers.\n" << endl;
    char text[] = "Good morning!", name[] = "Hans!";
    char *cPtr = (char*)"Hello "; // let cPtr point to "Hello "
    cout << cPtr << name << '\n' << text << endl;
    cout << "The Text \"" << text << "\" starts at Adress "
        << (void*)text << endl;
    cout << text + 6  << endl; // What happens here? 
    cPtr = name; // let cPtr point to name, meaning *Ptr is name[0]

    cout << "This is the " << *cPtr << " from " << cPtr << endl;
    *cPtr = 'c';
    cout << "That's Hans' " << cPtr << endl;
    return 0;
}