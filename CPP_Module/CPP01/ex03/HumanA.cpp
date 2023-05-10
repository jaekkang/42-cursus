#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {}

void HumanA::attack() {
    std::cout << this->getName() << " attacks with his "
              << this->getWeapon().getType() << std::endl;
}

const std::string HumanA::getName(void) const { return (this->_name); }

const Weapon &HumanA::getWeapon(void) const { return (this->_weapon); }

void HumanA::setWeapon(Weapon &weapon) { this->_weapon = weapon; }