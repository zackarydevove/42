#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : _contactCount(0), _oldestContact(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    int index = _contactCount == 8 ? _oldestContact : _contactCount;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    _contacts[index].setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    _contacts[index].setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    _contacts[index].setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    _contacts[index].setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    _contacts[index].setDarkestSecret(input);

    if (_contactCount == 8)
        _oldestContact++;

    if (_contactCount < 8)
        _contactCount++;

    if (_oldestContact >= 8)
        _oldestContact = -1;
}

std::string truncateAndFormat(const std::string &output) {
    if (output.length() > 10)
        return output.substr(0, 9) + ".";
    return output;
}

void PhoneBook::searchContact() const {
    if (_contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    for (int i = 0; i < _contactCount; ++i) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateAndFormat(_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateAndFormat(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateAndFormat(_contacts[i].getNickname()) << std::endl;
    }

    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    
    if (std::cin >> index && index >= 0 && index < _contactCount)
        printContact(index);
    else {
        std::cout << "Invalid contact index." << std::endl;
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void PhoneBook::printContact(int index) const {
    std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}