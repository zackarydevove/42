#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    Animal::operator=(other);
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

void Cat::makeSound() {
    std::cout << "Cat meows: Meow!" << std::endl;
}