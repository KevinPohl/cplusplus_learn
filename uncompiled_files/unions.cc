// define and use a union
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

union WordByte
{
    private:
        unsigned short w;       // 16-Bit
        unsigned char b[2];     // 2 Bytes: b[0], b[1]
    
    public:                     // Word and Byte-access:
        unsigned short& word() {return w;}
        unsigned char& lowByte() {return b[0];}
        unsigned char& highByte() {return b[1];}
};

int main()
{
    WordByte wb;
    wb.word() = 256;
    cout << "\nWord: " << (int)wb.word();
    cout << "\nLow-Byte: " << (int)wb.lowByte()
        << "\nHigh-Byte: " << (int)wb.highByte()
        << endl;
    return 0;
}

// a union uses the same memory to save different kinds of data at different
// times

// all attributes are implicitly public, if not otherwise flagged

// this union allows for a 16bit memory to be read whole or bitwise
