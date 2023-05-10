#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::attack() {
    std::cout << this->_name << " attacks with his " << this->_weapon->getType()
              << std::endl;
}

const Weapon *HumanB::getWeapon(void) const { return (this->_weapon); }

const std::string HumanB::getName(void) const { return (this->_name); }

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
