// mitarb_t.cpp : Die Mitarbeiter-Klassen verwenden.
// -------------------------------------------------
#include "mitarb.h"

int main()
{
    Mitarbeiter* mitPtr[2];
    mitPtr[0] = new Arbeiter("Nell, Rudi", 25.0, 140);
    mitPtr[1] = new Angestellter("Sommer, Eva", 3850.0);
    for( int i = 0; i < 2; ++i)
    {
        mitPtr[i]->display();
        cout << "\nEinkommen von " << mitPtr[i]->getName()
        << " : " << mitPtr[i]->einkommen() << endl;
    }
    delete mitPtr[0];
    delete mitPtr[1];
    return 0;
}