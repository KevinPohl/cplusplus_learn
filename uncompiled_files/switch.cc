#include <iostream>
using namespace std;

char menu(void){
    cout << "Please input a character: " << endl;
    char input;
    cin >> input;
    return input;
}

void action1(void){
    cout << "first action is being executed" << endl;
}

void action2(void){
    cout << "second action is being executed" << endl;
}

int main(){
    char commando = menu(); // Die Funktion menu() liest ein Kommando ein.

    switch(commando){
        case 'a':
        case 'A': action1(); // 1. action
        break;
        case 'b':
        case 'B': action2(); // 2. action
        break;
        default: cout << '\a' << flush; // beep for wrong commando
    }
}