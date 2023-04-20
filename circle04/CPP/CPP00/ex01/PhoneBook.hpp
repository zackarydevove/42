#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
    void addContact();
    void searchContact() const;

private:
    Contact _contacts[8];
    int _contactCount;
    int _oldestContact;
    void printContact(int index) const;
};

#endif