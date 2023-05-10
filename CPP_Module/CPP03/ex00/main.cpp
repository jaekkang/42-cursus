#include "ClapTrap.hpp"

int main(void) {
    ClapTrap c1;
    ClapTrap c2("First");

    c2.attack("default");
    c1.takeDamage(3);
    c2.attack("default");
    c1.takeDamage(3);
    c2.attack("default");
    c1.takeDamage(3);
    c2.attack("default");
    c1.takeDamage(3);
    c2.attack("default");
    c1.takeDamage(3);
    c2.attack("default");
    c2.attack("default");
    c2.attack("default");
    c2.attack("default");
    c2.attack("default");
    c2.attack("default");
    c1.beRepaired(2);
    c1.beRepaired(3);
    c1.beRepaired(4);
}
