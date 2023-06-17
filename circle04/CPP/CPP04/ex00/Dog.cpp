#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog barks: Woof!" << std::endl;
}