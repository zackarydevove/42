#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // // Test ClapTrap
    // ClapTrap clap1("ClapT");
    // ClapTrap clap2(clap1);
    // ClapTrap clap3;
    // clap3 = clap1;

    // clap1.attack("target1");
    // clap1.takeDamage(5);
    // clap1.beRepaired(3);

    // // Test ScavTrap
    // ScavTrap scav1("ScavT");
    // ScavTrap scav2(scav1);
    // ScavTrap scav3;
    // scav3 = scav1;

    // scav1.attack("target2");
    // scav1.takeDamage(30);
    // scav1.beRepaired(15);
    // scav1.guardGate();

    // Test FragTrap
    FragTrap frag1("Fraggy");
    FragTrap frag2("Fraggle");
    FragTrap frag3(frag1);

    frag1.attack("enemy1");
    frag2.attack("enemy2");
    frag3.attack("enemy3");

    frag1.highFivesGuys();
    frag2.highFivesGuys();
    frag3.highFivesGuys();

    frag2 = frag1;

    frag1.attack("enemy1");
    frag2.attack("enemy2");
    frag3.attack("enemy3");

    return 0;
}