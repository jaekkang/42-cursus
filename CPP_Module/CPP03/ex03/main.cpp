#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap new1("ASDF");

    new1.whoAmI();
    new1.attack("asdf");
    new1.attack("asdf");
    new1.attack("asdf");
    new1.beRepaired(5);
    new1.beRepaired(5);
}
