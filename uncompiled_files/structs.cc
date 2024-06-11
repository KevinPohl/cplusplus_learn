// define and use a struct
//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Agent // definition of structure
// a struct is a class with only public attributes and no methods, so a data
// container in essence
{
    string name; // name of agent
    double sales; // sales per month
};

// class  Agent {public: string name; double sales;};
// is therefore equivalent to
// struct Agent {string name; double sales;};

// as class attributes are implicitly private, if not defined otherwise, struct
// attributes are implicitly public 

inline void print(const Agent& a)
{
    cout << fixed << setprecision(2)
    << left << setw(20) << a.name
    << right << setw(10) << a.sales << endl;
};

int main()
{
    Agent heidi, hannes;
    heidi.name = "Sturm, Heidi";
    heidi.sales = 37000.37;
    hannes.name = "Forsch, Hannes";
    hannes.sales = 23001.23;

    heidi.sales += 1700.11; // adding sales
    // heidi.sales -= 20000;

    cout << " Agent sales\n"
        << "-------------------------------" << endl;
    print(heidi);
    print(hannes);
    cout << "\nSum of sales: "
        << heidi.sales + hannes.sales << endl;
    Agent *ptr = &hannes; // ptr.

    // who does most sales?
    if(hannes.sales < heidi.sales)
        ptr = &heidi;
    cout << "\nOur best horse: "
        << ptr->name << endl; // name of agent, ptr points to
    return 0;
}