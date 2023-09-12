#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap() {
    setName(name);
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) {
    setName(obj.getName());
    setAttackDamage(obj.getAttackDamage());
    setEnergyPoint(obj.getEnergyPoint());
    setHitPoint(obj.getHitPoint());
    std::cout << "FragTrap " << getName() << " copy constructor called"
              << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
    if (this != &obj) {
        setName(obj.getName());
        setAttackDamage(obj.getAttackDamage());
        setEnergyPoint(obj.getEnergyPoint());
        setHitPoint(obj.getHitPoint());
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap give me a high five" << std::endl;
}