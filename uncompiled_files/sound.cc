#include <iostream>
using namespace std;
const long delay = 1000000000L;

int main(){
    int tic;
    cout << "\nHow often should the sound be printed? ";
    cin >> tic;
    do {
        for(long i = 0; i < delay; ++i);
        cout << "Sound starts!\a" << endl;
        // "\a" (bell) didn't work for me on vscode, couldn't be bothered to sift through options
    } while(--tic > 0);
    
    cout << "End of acoustics!\n";
    
    return 0;
}