#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("ClapTrap1");
    claptrap.attack("Enemy1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    return 0;
}