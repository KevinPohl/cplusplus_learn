// function getPassword() and timediff() read and check password
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

long timediff(void);                // prototype

static string secret_word = "ISUS"; // Password
static long max_count = 3, max_time = 60; // Limits

bool getPassword()                  // read and check Password
{                                   // return-value: true, if Password ok
    bool ok_flag = false;           // for return value
    string word;                    // for input
    int count = 0, time = 0;
    timediff();                     // start counter

    while(ok_flag != true && ++count <= max_count) // count tries
    {
        cout << "\n\nInput your password: ";
        cin >> setw(20) >> word;
        cin.ignore(LLONG_MAX,'\n'); // delete rest of line
        time += timediff();
        if(time >= max_time)        // In time limit?
            break;                  // no!
        if(word != secret_word)
            cout << "password invalid!" << endl;
        else
            ok_flag = true;         // set ok = true
    }
    return ok_flag;                 // return
}

long timediff()                     // gives count of seconds since last call
{
    static time_t sec = 0;          // timestamp variable of last call
    time_t lastsec = sec;           // save last time
    time(&sec);                     // read new time
    return long(sec - lastsec);     // return difference
}
//------------------------------------------------------------------------------