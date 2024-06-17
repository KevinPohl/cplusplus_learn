//------------------------------------------------------------------------------
#include <iostream>
#include "Person_tpl2.h"

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