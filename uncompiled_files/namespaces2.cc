// shows usage of using declaration and directive
//------------------------------------------------------------------------------
#include <iostream> // namespace std

// global function ::message()
void message()
{
 std::cout << "in function ::message()\n";
}

namespace A
{
    using namespace std; // names of std are visible here
    void message() // function A::message()
    {
        cout << "in function A::message()\n";
    }
}

namespace B
{
 using std::cout; // declare cout from std
 void message(void); // function B::message()
}

void B::message(void) // definition of B::message()
{
 cout << "in function B::message()\n";
}

int main()
{
    using namespace std; // names from std
    using B::message; // function name without brackets!
    cout << "test with namespaces!\n";
    cout << "\ncall of A::message()" << endl;
    A::message();
    cout << "\ncall of B::message()" << endl;
    
    // because of using-declaration hidden ::message()
    message();
    cout << "\ncall of ::message()" << endl;
    ::message(); // global function
    return 0;
}

#include <iostream> // namenspace std
//------------------------------------------------------------------------------