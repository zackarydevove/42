#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
public:
    void addContact();
    void searchContact() const;

private:
    Contact _contacts[8];
    int _contactCount;
    void printContact(int index) const;
};

#endif