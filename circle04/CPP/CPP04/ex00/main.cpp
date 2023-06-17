#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


	std::cout << "type: " << meta->getType() << " " << std::endl; 
    std::cout << "type: " << j->getType() << " " << std::endl;
    std::cout << "type: " << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "========WRONG ANIMAL========" << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongI = new WrongCat();

    std::cout << "type: " << wrongMeta->getType() << " " << std::endl;
    std::cout << "type: " << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();
   
    delete wrongMeta;
    delete wrongI;
    
    return 0;
}