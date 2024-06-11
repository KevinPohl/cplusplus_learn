// unpack a structure
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Agent
{
    string name; // name of agent
    double sales; // sales per month
};

inline Agent& increase_sales(Agent& a, double inc)
{
    auto&[nref, uref] = a;      // unpack structure
    uref += inc;                // add sales
    return a;
}

int main()
{
    Agent heidi = {"Sturm, Heidi", 4950.99}; 
    auto[nm, um] = heidi;           // unpack structure via structured bindings
    cout << "\nThe unpacked structure: " << endl; 
    cout << "name: " << nm << "\nsales: " << um << endl;
    
    // references on data elements of structure 
    auto[nref, uref] = heidi;
    cout << "nref before: " << nref << endl;
    nref = "Winter, Heidi";     // change name
    cout << "nref after: " << nref << endl;
    
    // add sales: 
    auto[r1, r2] = increase_sales(heidi, 5000.0); 
    cout << "\nAenderungen in der entpackten Struktur: ";
    cout << "\nname: " << r1 << "\nsales: " << r2 << endl;
    cout << "\nThe changed structure: " << endl; 
    cout << "name: " << heidi.name << "\nsales: " << heidi.sales << endl; 
    return 0; 
}