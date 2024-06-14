//------------------------------------------------------------------------------
#include <iostream>
#include <string_view>
using namespace std;
char pattern[] = "1234567890"; 

int main()
{
    std::basic_string_view sv(pattern), prefix(pattern, 4);

    cout << "\n *** Standardclass string_view ***\n\n"
        << "The message: " << sv << endl
        << "count of chars: " << sv.length() << endl
        << "First 4 chars: " << prefix << endl;
    return 0;
}