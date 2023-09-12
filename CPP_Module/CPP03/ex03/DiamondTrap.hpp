#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScaveTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScaveTrap {
  private:
    std::string _name;

  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap &obj);

    void whoAmI();

    using ScaveTrap::attack;
};

#endif