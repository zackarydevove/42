#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copy constructor called." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << name << " assigned." << std::endl;
    return *this;
}

void FragTrap::attack(const std::string &target) {
    if (energyPoints == 0 || hitPoints == 0) {
        std::cout << "FragTrap " << name << " is out of energy or has no hit points left. Can't attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}