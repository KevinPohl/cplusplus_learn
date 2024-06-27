//------------------------------------------------------------------------------
#include <list>
#include <cstdlib>
#include <iostream>
// using namespace std;

typedef std::list<int> INTLIST;

/**
 * @brief Display values of a list of ints.
 * 
 * Displays the contents of a list of ints in the terminal, every value in a new
 * line.
 * @param c Source list.
 * @return int of last count
 */
int display(const INTLIST& c)
{
    int i = 0; // counter
    INTLIST::const_iterator pos; // iterator
    for(pos = c.begin(); pos != c.end(); pos++, i++)
        std::cout << *pos << std::endl;
    std::cout << std::endl;

    return i;
}

int main()
{
    INTLIST ls, sls;
    int i;
    for(i=1; i<=3; i++)
        ls.push_back( rand()%10 );          // 1 7 4
    ls.push_back(ls.front());               // 1 7 4 1
    ls.reverse();                           // 1 4 7 1
    ls.sort();                              // 1 1 4 7
    for(i=1; i<=3; i++)
        sls.push_back( rand()%10 );         // 0 9 4

    // first object of sls before last of ls
    auto pos = ls.end();
    ls.splice(--pos, sls, sls.begin());     // 1 1 4 0 7
    display(sls);                           // 9 4
    ls.sort();                              // 0 1 1 4 7
    sls.sort();                             // 4 9
    ls.merge(sls);                          // 0 1 1 4 4 7 9
    ls.unique();                            // 0 1 4 7 9
    display(ls);

    return 0;
}