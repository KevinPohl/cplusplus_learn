// Demo for blockwise writing of records
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
char header[] =
" * * * P I Z Z A P R O N T O * * *\n\n";
// data-structure:
struct Pizza { char name[32]; float price; };
const int MAXCNT = 10;
Pizza pizzaMenu[MAXCNT] =
{
 { "Margerita", 9.90F }, { "Regina", 15.90F },
 { "Pizza Fungi", 12.50F }, { "Calzone", 14.90F } };
int cnt = 4;
char pizzaFile[256] = "pizza.dat";

int main() // Datensätze schreiben.
{
    cout << header << endl;
    // write data into file
    int exitCode = 0;
    ofstream outFile(pizzaFile, ios::out|ios::binary);
    if(!outFile)
    {
        cerr << "Fehler beim Öffnen der Datei!" << endl;
        exitCode = 1;
    }
    else
    {
        for(int i = 0; i < cnt; ++i)
            if(!outFile.write((char*)&pizzaMenu[i], sizeof(Pizza)))
            {
                cerr << "Error while writing!" << endl;
                exitCode = 2;
            }
    }
    if(exitCode == 0)
        cout << "\nWrite Data into file " << pizzaFile << ".\n" << endl;
    return exitCode;
}