#include "ScaveTrap.hpp"

ScaveTrap::ScaveTrap() : ClapTrap() {
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    std::cout << "ScaveTrap " << this->getName() << " constructor called"
              << std::endl;
}

ScaveTrap::ScaveTrap(std::string name) : ClapTrap() {
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    std::cout << "ScaveTrap " << this->getName() << " constructor called"
              << std::endl;
};

ScaveTrap::ScaveTrap(const ScaveTrap &c) {
    this->setName(c.getName());
    this->setHitPoint(c.getHitPoint());
    this->setEnergyPoint(c.getEnergyPoint());
    this->setAttackDamage(c.getAttackDamage());
}

ScaveTrap &ScaveTrap::operator=(const ScaveTrap &c) {
    if (this != &c) {
        this->setName(c.getName());
        this->setHitPoint(c.getHitPoint());
        this->setEnergyPoint(c.getEnergyPoint());
        this->setAttackDamage(c.getAttackDamage());
    }
    return (*this);
}

ScaveTrap::~ScaveTrap() {
    std::cout << "ScaveTrap " << this->getName() << " destructor called"
              << std::endl;
}

void ScaveTrap::guardGate() {
    std::cout << "ScaveTrap is now in Gate keeper mode" << std::endl;
}

void ScaveTrap::attack(const std::string &target) {
    if (this->getHitPoint() == 0) {
        std::cout << "ScaveTrap " << this->getName() << " can't attacks "
                  << target << ", because No more hit points" << std::endl;
        return;
    }
    std::cout << "ScaveTrap " << this->getName() << " attacks " << target
              << ", causing " << this->getAttackDamage() << " points of damage!"
              << std::endl;
    setHitPoint(getHitPoint() - 1);
    std::cout << "FragTrap ClapTrap " << this->getHitPoint() << " points left"
              << std::endl;
}