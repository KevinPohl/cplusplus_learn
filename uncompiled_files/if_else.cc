#include <iostream>
using namespace std;

int main()
{
    float x, y, min;
    cout << "Please input two different float numbers:\n";
    if(cin >> x && cin >> y) // if both inputs are successful
    {
        if(x < y) // calculate minimum of both
            min = x;
        else
            min = y;
        cout << "\nThe smaller number is: " << min << endl;
    }
    else
        cout << "\nError!" << endl;

    return 0;
}