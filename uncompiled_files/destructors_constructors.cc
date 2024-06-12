#include <iostream>
#include <string>
using namespace std;

// object counter
int object_counter = 0;

class Demo
{
    private:
        string name;

    public:
        // constructor
        Demo(const string&);
        
        // destructor
        Demo();
};

Demo::Demo(const string& str)
{
    ++object_counter; name = str;
    cout << "I am the constructor of "<< name << "."
    << "\nThis is the " << object_counter << ". object!"
    << endl;
}

Demo::Demo() // definition of the destructor
{
    cout << "I am the destructor of " << name << "."
    << "\nthe " << object_counter << ". object " 
    << "is destructed" << endl;
    --object_counter;
}

// -- construct and destruct objects in demo --
Demo globalObject("global object");
int main()
{
    cout << "First command in main()." << endl;
    Demo firstLocalObject("First local object.");
    {
        Demo secLocalObject("second local object");
        static Demo staticObjekt("static object");
        cout << "\nLast command in inner block."
        << endl;
    }
    cout << "Last command in main()." << endl;
    return 0;
}