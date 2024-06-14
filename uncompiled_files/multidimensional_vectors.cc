//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
char salesperson[2][20] = {"Lauber, Otto", "Forsch, Heidi"};

// every salesperson has 5 products, count of sold:
int productCount[2][5] = {{20, 51, 30, 17, 44}, {150, 120, 90, 110, 88}};
int main()
{
    for(int i=0; i < 2; i++)
    {
        cout << "\n Salesperson: " << salesperson[i];
        cout << "\n Sold count: ";
        for(int j = 0; j < 5; j++)
            cout << setw(6) << productCount[i][j];
        cout << endl;
    }
    return 0;
}