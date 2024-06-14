// Class TelList to display a list with names and phone numbers
//------------------------------------------------------------------------------
#ifndef TELLIST_H
#define TELLIST_H

#include <string>
using namespace std;

#define PSEUDO -1 // pseudoposition
#define MAX 100 // max count of elements

// Type of one list element:
struct Element { string name, telNr; };

class TelList
{
    private:
        Element v[MAX]; // Vector and current count of elements
        int count;
    public:
        TelList(){count = 0;}
        
        int getCount()const {return count;}
        
        Element *retrieve(int i)
        {
            return (i >= 0 && i < count)? &v[i] : NULL;
        }
        
        bool append(const Element& el)
        {
            return append(el.name, el.telNr);
        }
        
        bool append(const string& name, const string& telNr);
        bool erase(const string& name);
        int search(const string& name) const;
        void print()const;
        int print(const string& name) const;
        int getNewEntries();
};
#endif // TELLIST_H