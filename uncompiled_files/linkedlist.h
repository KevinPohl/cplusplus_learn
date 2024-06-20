// definition of classes ListEl and LList
//------------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
#include "daytime_operator_overloading.h"
#include <iostream>
#include <iomanip>

using namespace std;

// an element of Linked List ///s348
class ListEl
{
    private:
        DayTime daytime; // Date
        double money_value; // money value
        
        // pointer to next element
        ListEl* next;

    public:
        ListEl( DayTime d = DayTime(1,1,1), double m = 0.0, ListEl* p = NULL)
        : daytime(d), money_value(m), next(p) {}
        
        // getter setter
        // getDatum(), setDatum(), getBetrag(), setBetrag()
        ListEl* getNext() const { return next; }
        friend class LList;
};

//------------------------------------------------------------------------------
// definition of class LList
class LList
{
    private:
        ListEl* first, *last;

    public:
    
        // constructor
        LList(){ first = last = NULL; }
        
        // destructor
        ~LList();

        // first and last element
        ListEl* front() const { return first; }
        ListEl* back() const { return last; }

        // append new element to list
        void pushBack(const DayTime& d, double b);

        // delete element from front of list
        void popFront();
};
#endif // LIST_H_



