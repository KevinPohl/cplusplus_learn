//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Person
{
    private:
        std::string name, address;
        unsigned int age;
        std::vector<Person*> friendslist;

    public:
        // prototype
        std::string description() const;

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

        inline void friendship(Person &new_friend)
        {
            Person *tptr;
            tptr = &new_friend;
            friendslist.push_back(tptr);
            new_friend.friendslist.push_back(this);
        }

        inline void getFriends()
        {
            if(!friendslist.empty()){
                std::cout << "Friends of " << getName() << "["
                    << friendslist.size() << "]: ";
                for(std::vector<Person *>::iterator vec_iter = \
                    friendslist.begin(); vec_iter != friendslist.end();
                    ++vec_iter)
                {
                    std::string friend_name = (**vec_iter).getName();
                    if (vec_iter == friendslist.begin()) 
                    {
                        std::cout << friend_name;
                    }
                    else 
                    {
                        std::cout << ", " << friend_name;
                    }
                }
                std::cout << std::endl;
            } else {std::cout << getName() << " has no friends." << std::endl;}
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

int main()
{
    // instantiation of 2 Persons
    Person pers1 = Person("Justin Bieber", 30,
        "some address in some city, somewhere in Canada");
    Person pers2 = Person("Michael Mittermeier", 50);
    Person pers3 = Person("Hermann Herre", 120, "a cemetery");
    Person pers4 = Person("Forever Alone", 10, "some place on the internet");
    Person pers5 = Person("Everybodies Darling", 25, "Alabama");
    
    std::cout << "Description of Person1: " << pers1.description() << std::endl;
    
    // increase age of one
    pers1.happyBirthday();
    std::cout << "Age of Person1 after birthday: " << pers1.getAge()
        << std::endl;

    // change of address
    pers2.move("an address in bavaria, probably");
    
    std::cout << "Description of Person2: " << pers2.description() << std::endl;
    
    // friendship of two class instances
    pers1.friendship(pers2);
    pers1.friendship(pers3);

    // friends output
    pers1.getFriends();
    pers2.getFriends();
    pers3.getFriends();
    pers4.getFriends();

    pers5.friendship(pers1);
    pers5.friendship(pers2);
    pers5.friendship(pers3);
    pers5.friendship(pers4);
    pers1.getFriends();
    pers2.getFriends();
    pers3.getFriends();
    pers4.getFriends();
    pers5.getFriends();

    return 0;
}