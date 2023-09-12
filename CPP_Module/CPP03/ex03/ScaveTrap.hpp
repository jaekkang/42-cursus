#ifndef ScaveTrap_HPP
#define ScaveTrap_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScaveTrap : virtual public ClapTrap {
  private:
  public:
    ScaveTrap();
    ScaveTrap(std::string name);
    ~ScaveTrap();
    ScaveTrap(const ScaveTrap &c);
    ScaveTrap &operator=(const ScaveTrap &c);

    void guardGate();
    void attack(const std::string &target);
};

#endif