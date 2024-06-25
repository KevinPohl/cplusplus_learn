#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct auto_t
{
    string modellname;
    string herstellername;
    int ps;
};

int main()
{
    vector<auto_t> mein_vektor=
    {
        {"911", "Porsche", 370},
        {"Testarossa", "Ferrari", 390}
    };

    // cout << mein_vektor[0].ps << endl;


    for (auto_t datensatz : mein_vektor)
    {
        cout
            << "Hersteller: " << datensatz.herstellername << "\n"
            << "Modell:     " << datensatz.modellname << "\n"
            << "PS:         " << datensatz.ps << "\n"
            << endl;

    }

    return 0;
}