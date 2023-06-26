#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);

    std::string getType() const;
    virtual void makeSound() const = 0;

protected:
    std::string type;
};


#endif