#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other)
    {
        Animal::operator=(other);
        if (brain)
            delete(brain);
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog barks: Woof!" << std::endl;
}

Brain* Dog::getBrain() const{
	return brain;
}