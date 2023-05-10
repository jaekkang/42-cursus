#include "ScaveTrap.hpp"

int main(void) {
    ScaveTrap new1("scavetrap01");
    ScaveTrap new2;

    new1.attack("another trap");
    new1.attack("another trap");
    new1.attack("another trap");
    new1.beRepaired(1);
    new1.guardGate();
    new1.takeDamage(10);
    new1.takeDamage(10);
    new1.takeDamage(10);
    new1.takeDamage(10);
    new1.takeDamage(10);
    new1.takeDamage(10);
    new1.takeDamage(10);
    return (0);
}