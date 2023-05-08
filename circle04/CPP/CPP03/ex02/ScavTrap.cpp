#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << name << " copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << name << " assigned." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints == 0 || hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is out of energy or has no hit points left. Can't attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}