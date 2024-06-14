//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    float *pv, x, v[6] = {0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F};
    pv = v + 4; // set pv to v[4]
    *pv = 1.4;  // write 1.4 to v[4]
    pv -= 2;    // set pv to v[2]
    ++pv;       // set pv to v[3]
    x = *pv++;  // set v[3] to x, then set pv one element further
    x += *pv--; // x + v[4], then set pv back to v[3]
    --pv;       // set pv to v[2]
    
    for (int i=0; i<6; i++)
    {
    cout << v[i] << endl;
    }

    return 0;
}