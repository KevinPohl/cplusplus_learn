#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int ac = 32; // start from ASCII-Code 32
    while(true)
    {
        cout << "\n Char Decimal Hexadecimal\n\n";
        int upper;
        for(upper = ac+20; ac < upper && ac < 256; ++ac)
            cout << " " << (char)ac // typecasting ac as char
            << setw(10) << dec << ac
            << setw(10) << hex << ac << endl;
        if(upper >= 256) break;
        cout << "\nContinue -> <Return>, End -> <q>+<Return>";
        char answer;
        cin.get(answer);
        while (answer != '\n' && answer != 'q') {
            cin.ignore(LLONG_MAX, '\n'); cin.get(answer);
        }

        if (answer == 'q')
            break;
    }

    for(int i = 0; i < 100; i++) {
        cout << "all:  " << dec << i << endl;
        if(i % 2 == 1)
            continue; // jump to next i immediately
        cout << "even: " << dec << i << endl;

        if(i == 42){
            goto errorcheck;
        }
    }

    errorcheck:
        cout << "an error occured" << endl;

    return 0;
}