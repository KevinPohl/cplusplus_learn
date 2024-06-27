// Eine Liste mit int-Werten ausgeben.
//------------------------------------------------------------------------------
#include <list>
#include <iostream>
// using namespace std;

// int list
typedef std::list<int> INTLIST;

int display(const INTLIST& c)
{
    // counter
    int i = 0;
    
    // iterator
    INTLIST::const_iterator pos;
    
    for(pos = c.begin(); pos != c.end(); pos++, i++)
        std::cout << *pos << std::endl;
    std::cout << std::endl;
    return i;
}


#include "account5_destructor.h"
#include <vector>
typedef std::vector<Account> AccountVec;

void display(const AccountVec& v)
{
    // Iterator
    AccountVec::const_iterator pos = v.begin();
    // auto pos = v.begin(); // alternatively
    for( ; pos < v.end(); pos++)
    pos->display();
    cout << endl;
}


// #include <vector>
#include <functional> // for comparator class less<T>

template <class T, class Compare = less<T> >
class SortVec : public vector<T>
{
 public:
    SortVec() { }
    SortVec(int n, const T& x = T()):vector<T>(n,x){} 

    void insert(const T& obj); // sort insert
    int search(const T& obj);
    void merge(const SortVec& v);
};

int main()
{
    // instantiate and display a list of ints
    INTLIST some_list;
    for(int element : {10, 12, 54, 9, 12}){some_list.push_back(element);}
    display(some_list);

    // instantiate and display a vector of Account
    AccountVec some_account_vector;
    for (Account element:
            {
                Account("John Smith", 105321, 115.41),
                Account("Jane Smith", 105322, 3400),
                Account("Jacky Smith", 105323, 12.1),
                Account("Jenny Smith")
            }
        )
    {
        some_account_vector.push_back(element);
    }
    display(some_account_vector);


    // instantiate and SortVec of Ints
    typedef SortVec<int> IntSortVec;
    
    // default constructor
    IntSortVec v, w;
    

    // operator < has to be initialized
    // v.insert(2);
    // v.insert(7);
    // v.insert(1);
    
    // int n = v.search(7);
    // std::cout << n << std::endl;
    // w.insert(3);
    // w.insert(9);
    // v.merge(w);
    


    // Danach enthält der Vektor v die Elemente: 1 2 3 7 9

    // v.search(9);
    // for(int elem:v){std::cout << elem << std::endl;}

}