#include <iostream>
#include <iomanip>
#include <string>

class Person
{
    private:
        std::string name, address;
        unsigned int age;

    public:

        // prototype
        std::string description() const;
        void friendship(const Person& new_friend) const;

        // full instantiation
        Person(
            const std::string& i_name,
            const unsigned int& i_age,
            const std::string& i_address)
        {
            name = i_name;
            age = i_age;
            address = i_address;
        } 

        // instantiation with name and age only
        Person(const std::string& i_name, const unsigned int& i_age)
        : Person::Person(i_name, i_age, ""){}

        // const getter - implicit inline here
        std::string getName()       const {return name;}
        int getAge()                const {return age;}
        std::string getAddress()    const {return address;}

        // setters - implicit inline here
        void setName(const std::string& x)          {name = x;}
        void setAge(const unsigned int& x)          {age = x;}
        void move(const std::string& newAddress)    {address = newAddress;}
        void happyBirthday()                        {age++;};

        // show "this pointer" which is normally not recommended, except in edge
        // cases
        void is50() const
        {   
            if (this->age == 50)
            {
                std::cout << "The Person is indeed at age 50." << std::endl;
            }
            else std::cout << "The Person is not at age 50." << std::endl;
        }

        // destructor is implicit inline
        // inline ~Person() // explixit inline is just as possible
        ~Person()
        {
            std::cout << "Deleting Person: " << getName() << "." << std::endl;
        }

};

std::string Person::description() const
{
    std::string desc = "Name: " + Person::getName();
    desc += ", Age: " + std::to_string(Person::getAge());
    desc += ", Address: " + Person::getAddress();
    return desc;
}

void Person::friendship(const Person& new_friend) const
{
    std::cout
        << "\n"
        << "-----------------------------------\n"
        << "A friendship is blooming:\n"
        << "-----------------------------------\n"
        << Person::getName() << ": " 
        << "Hi, here is my info: " 
        << Person::description() 
        << ". It's nice to meet you.\n"
        << new_friend.getName() << ": "
        << "Hello, nice meeting you, too. This is my info: "
        << new_friend.description() << "."
        << "\n"
        << "-----------------------------------\n"
        << "Blooming of friendship is complete.\n"
        << "-----------------------------------\n"
        << std::endl;
}


int main()
{
    // instantiation of 2 Persons
    Person pers1 = Person("Justin Bieber", 30, "some address in some city, somewhere in Canada");
    Person pers2 = Person("Michael Mittermeier", 50);
    
    std::cout << "Description of Person1: " << pers1.description() << std::endl;
    
    // increase age of one
    pers1.happyBirthday();
    std::cout << "Age of Person1 after birthday: " << pers1.getAge() << std::endl;

    // change of address
    pers2.move("an address in bavaria, probably");
    
    std::cout << "Description of Person2: " << pers2.description() << std::endl;
    
    // friendship of two class instances
    pers1.friendship(pers2);
    
    // dummy function to show this pointer
    pers2.is50();

    return 0;
}

