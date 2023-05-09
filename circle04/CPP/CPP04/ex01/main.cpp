#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int animalCount = 6;
    Animal* animals[animalCount];

    std::cout << "===========Fill array with dogs and cats=========== " << std::endl;

    // Fill the array with Dogs and Cats
    for (int i = 0; i < animalCount / 2; ++i) {
        animals[i] = new Dog();
    }

    for (int i = animalCount / 2; i < animalCount; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "===========Print type and sound of each animal=========== " << std::endl;

    // Print the type and sound of each animal
    for (int i = 0; i < animalCount; ++i) {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    std::cout << "===========Test deep copy=========== " << std::endl;

    // Test deep copy
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3 = dog1;
    Cat cat1;
    Cat cat2(cat1);
    Cat cat3 = cat1;

    std::cout << "===========Delete every animal object in Array=========== " << std::endl;
    // Delete every Animal object in the array
    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }

    std::cout << "===========Test brain=========== " << std::endl;
    // Test brain
    Dog *dog4 = new Dog();
    Cat *cat4 = new Cat();

    dog4->getBrain()->setIdea(0, "I'm a dog");
    std::cout << "Dog4 brain first idea: " + dog4->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog4 brain second idea: " + dog4->getBrain()->getIdea(1) << std::endl;

    cat4->getBrain()->setIdea(0, "I'm a cat");
    std::cout << "Cat4 brain first idea: " + cat4->getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat4 brain second idea: " + cat4->getBrain()->getIdea(1) << std::endl;

    std::cout << "===========Delete dog4 and cat4=========== " << std::endl;

    delete dog4;
    delete cat4;

    std::cout << "===========Return 0=========== " << std::endl;
    return 0;
}