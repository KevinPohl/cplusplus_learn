//------------------------------------------------------------------------------
#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>
// using namespace std;

class Cell
{
    private:
        Cell* next;

    protected:
        Cell(Cell* suc = NULL){ next = suc; }
    
    public:
        virtual ~Cell(){ }
        // getter/setter here
        Cell* getNext() const {return next;}
        void setNext(Cell* ptr) {next = ptr;}
        virtual void display() const = 0;
};

class BaseEl : public Cell
{
    private:
        std::string name;

    public:
        BaseEl( Cell* suc = NULL, const std::string& s = "")
        : Cell(suc), name(s){}
        // getter/setter here
        void display() const;
};

class DerivedEl : public BaseEl
{
    private:
        std::string bem;

    public:
        DerivedEl(Cell* suc = NULL, const std::string& s="", const std::string& b="")
        : BaseEl(suc, s), bem(b) { }
        // getter/setter here
        void display() const;
};
#endif

// List.h: Definition der Klasse InhomList
// ---------------------------------------------
#ifndef LIST_H
#define LIST_H
// #include "cell.h"
class InhomList
{
    private:
        Cell* first;
    
    protected:
        Cell* getPrev(const std::string& s);
        void insertAfter(const std::string& s, Cell* prev);
        void insertAfter(const std::string& s, const std::string& b, Cell* prev);
    
    public: // Konstruktor, Destruktor usw....
        void insert(const std::string& n);
        void insert(const std::string& n, const std::string& b);
        void displayAll() const;
        // void insertAfter(const std::string& s, Cell* prev);
};
#endif

void InhomList::insertAfter(const std::string& s, Cell* prev)
{
    if(prev == NULL) // Vor allen anderen einfügen:
        first = new BaseEl(first, s);
    else // In der Mitte oder am Ende:
    {
        Cell* p = new BaseEl(prev->getNext(), s);
        prev->setNext(p);
    }
}


int main()
{
    InhomList list1;
    list1.insert("first insert");
    list1.insert("second insert");
    list1.insertAfter("third insert", list1.first);

    // doesn't work, classes not complete
}
