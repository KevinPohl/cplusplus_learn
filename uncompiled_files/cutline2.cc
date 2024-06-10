#include <string>
// #include "cutline1.cc"

using namespace std;

extern string line;         // extern-declaration - variable from cutline1
void cutline()
{
    int i = line.size();    // position after last character
    while(--i >= 0)
    {
        if(line[i] != ' ' && line[i] != '\t') // if no space or tab
        {
            break;
        }
    }
    line.resize(++i);
}