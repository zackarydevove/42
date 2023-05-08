#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test ClapTrap
    ClapTrap clap1("ClapT");
    ClapTrap clap2(clap1);
    ClapTrap clap3;
    clap3 = clap1;

    clap1.attack("target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    // Test ScavTrap
    ScavTrap scav1("ScavT");
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav1;

    scav1.attack("target2");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();

    return 0;
}