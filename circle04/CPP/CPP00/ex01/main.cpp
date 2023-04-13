#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command, please try again." << std::endl;
        }
    }

    return 0;
}