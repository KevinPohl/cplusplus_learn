//------------------------------------------------------------------------------
#ifndef STAFFER_H
#define STAFFER_H
#include <string>
#include <iostream>
// using namespace std;

class Staffer
{
    private:
        std::string name;
        // further info

    public:
        Staffer(const std::string& s = ""):name(s) {}
        
        // virtual destructor, needed for derived classes
        virtual ~Staffer(){}
        
        const std::string& getName() const{ return name; }
        void setName(const std::string& n){ name = n; }
        virtual void display() const;
        
        // =0 means purely virtual, no function in base class, this is a null
        // pointer under the hood
        virtual double income() const = 0;
        
        virtual Staffer& operator=(const Staffer&);
};


class Worker : public Staffer
{
    private:
        double wage;
        int hours;

    public:
        Worker(const std::string& s="", double l=0.0, int h=0)
        : Staffer(s), wage(l), hours(h) {}
        // deconstructor "~Worker() {}" is implied from base class

        double getWage() const { return wage; }
        void setWage(double l) { wage = l; }
        int getHours() const { return hours; }
        void setHours(int h) { hours = h; }
        void display() const {};
        double income() const; //{return (wage * hours);}
        Worker& operator=(const Staffer&);
        Worker& operator=(const Worker&);
};

class Employee : public Staffer
{
    private:
        // monthly salary
        double salary;

    public:
        Employee(const std::string& s="", double g = 0.0) : Staffer(s), salary(g){ }

        double getSalary() const { return salary; }
        void setSalary(double g){ salary = g; }
        void display() const;
        double income() const { return salary; }
        Employee& operator=( const Staffer& );
        Employee& operator=( const Employee& );
};

#endif // STAFFER_H
//------------------------------------------------------------------------------

// void Staffer::display() const {std::cout << "Staffer display: hi" << std::endl;}
// Staffer& operator=(const Staffer&);
// Staffer::~Staffer(){}

double Worker::income() const
{
    return ( wage * hours );
}

//------------------------------------------------------------------------------
int main ()
{
    // error, because in this class exists one or more purely virtual methods
    // (here: income()), which makes it an abstract class, of which no
    // instantiations can be made
    // Staffer head_of_sales("Peter Parker");

    // does not produce an error, because the virtual method income is
    // inherited from base class
    // IF all inherited virtual methods are defined in derived class, this class
    // becomes a concrete class, and instantiations can be made
    // Worker miner("Peter Parker", 25.00, 45);
    // std::cout << "Income of "<< miner.getName() << ": " << miner.income() << std::endl;
    
    // Employee head_of_sales("Clark Kent", 4500.25);
    // std::cout << "Salary of "<< head_of_sales.getName() << ": " << head_of_sales.income() << std::endl;


    Staffer* stfPtr[2];
    stfPtr[0] = new Worker("Nell, Rudi", 25.0, 140);
    stfPtr[1] = new Employee("Sommer, Eva", 3850.0);
    for( int i = 0; i < 2; ++i)
    {
        stfPtr[i]->display();
        std::cout << "\nEinkommen von " << stfPtr[i]->getName() << " : " << stfPtr[i]->income() << std::endl;
    }
    delete stfPtr[0];
    delete stfPtr[1];
    return 0;


    std::cout << "hello" << std::endl;

    return 0;
}
