#include "PhoneBook.hpp"

void PhoneBook::addContact() {
    if (_contactCount < 8) {
        std::string input;
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        _contacts[_contactCount].setFirstName(input);

        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        _contacts[_contactCount].setLastName(input);

        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        _contacts[_contactCount].setNickname(input);

        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        _contacts[_contactCount].setPhoneNumber(input);

        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        _contacts[_contactCount].setDarkestSecret(input);

        _contactCount++;
    } else {
        std::cout << "Phonebook is full. Oldest contact will be replaced." << std::endl;
        _contactCount = 0;
        addContact();
    }
}

void PhoneBook::searchContact() const {
    if (_contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    for (int i = 0; i < _contactCount; ++i) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _contacts[i].getFirstName() << "|";
        std::cout << std::setw(10) << _contacts[i].getLastName() << "|";
        std::cout << std::setw(10) << _contacts[i].getNickname() << std::endl;
    }

    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> index;
    std::cin.ignore();

    if (index >= 0 && index < _contactCount) {
        printContact(index);
    } else {
        std::cout << "Invalid contact index." << std::endl;
    }
}

void PhoneBook::printContact(int index) const {
    std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}