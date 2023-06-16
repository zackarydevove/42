#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("Bob");
    claptrap.attack("Tom");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    ClapTrap claptrap2 = claptrap;
    claptrap2.attack("Job");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);

    ClapTrap claptrap3;
    claptrap3.attack("Dom");
    claptrap3.takeDamage(5);
    claptrap3.beRepaired(3);

    return 0;
}