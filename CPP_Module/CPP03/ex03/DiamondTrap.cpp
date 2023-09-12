#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << getName() << " constructor called"
              << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    _name = name;
    setName(name + "_clap_name");
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << getName() << " constructor called"
              << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
    setName(obj.getName());
    setAttackDamage(obj.getAttackDamage());
    setEnergyPoint(obj.getEnergyPoint());
    setHitPoint(obj.getHitPoint());
    std::cout << "DiamondTrap " << getName() << " copy constructor called"
              << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    if (this != &obj) {
        setName(obj.getName());
        setAttackDamage(obj.getAttackDamage());
        setEnergyPoint(obj.getEnergyPoint());
        setHitPoint(obj.getHitPoint());
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap has " << this->_name << std::endl;
    std::cout << "  ClapTrap has " << this->getName() << std::endl;
}