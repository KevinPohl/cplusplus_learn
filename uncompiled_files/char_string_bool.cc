// Ein Zeichen einlesen und den Zeichencode
// oktal, dezimal und hexadezimal ausgeben.
#include <iostream> // Declaration of cin, cout
#include <iomanip> //manipulators that are called with arguments
#include <string>
using namespace std;

int main()
{
    int num = ' ';
    cout << "Code of space: " << num << endl;
    char ch;
    string prompt = "\nGive a character and press <Return>: ";
    cout << prompt;
    cin >> ch; // read char
    num = ch;
    cout << "The character " << ch << " has code " << endl;

    cout << uppercase // for hex
        << "octal  decimal  hexadecimal\n"
        << oct << setw(7) << setfill(' ') << left << num
        << dec << setw(9) << left << num
        << hex << setw(11) << left << uppercase << num << endl;

    char ch1 = '0';
    cout << ch1 << ' ' << "A" << endl;

    string s1("are things things");
    cout << left << setfill('?') << setw(25) << s1 << endl;

    // bools
    bool ok = 1==1;
    cout << ok << endl;
    cout << boolalpha << ok << endl; // revert with noboolalpha
    

    return 0;
}