#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog &other);
    virtual ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;
    Brain *getBrain() const;

private:
    Brain *brain;
};

#endif