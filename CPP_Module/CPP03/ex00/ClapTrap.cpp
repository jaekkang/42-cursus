#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->getName() << " constructor called"
              << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) {
    this->_name = c.getName();
    this->_hitPoints = c.getHitPoint();
    this->_energyPoints = c.getEnergyPoint();
    this->_attackDamage = c.getAttackDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) {
    if (this != &c) {
        this->_name = c.getName();
        this->_hitPoints = c.getHitPoint();
        this->_energyPoints = c.getEnergyPoint();
        this->_attackDamage = c.getAttackDamage();
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->getName() << " can't attacks "
                  << target << ", because No more hit points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName() << " attacks " << target
              << ", causing " << this->getAttackDamage() << " points of damage!"
              << std::endl;
    --this->_hitPoints;
    std::cout << "ClapTrap " << this->_hitPoints << " points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " No Energy points already"
                  << std::endl;
        return;
    }
    this->_energyPoints -= amount;
    if (this->_energyPoints < 0)
        this->_energyPoints = 0;
    std::cout << "ClapTrap " << this->_name << " takes " << amount
              << " damage, " << this->_energyPoints << " points left"
              << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
    this->_energyPoints += amount;
    std::cout << "ClapTrap " << this->_name << " get energy points (" << amount
              << "), " << this->_energyPoints << " energy points left"
              << std::endl;
}

const std::string ClapTrap::getName() const { return (this->_name); }

int ClapTrap::getHitPoint() const { return (this->_hitPoints); }

int ClapTrap::getEnergyPoint() const { return (this->_energyPoints); }

int ClapTrap::getAttackDamage() const { return (this->_attackDamage); }
