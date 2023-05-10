#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
  private:
    std::string _name;
    Weapon *_weapon;

  public:
    HumanB(std::string name);

    void attack();
    void setWeapon(Weapon &weapon);
    const Weapon *getWeapon(void) const;
    const std::string getName(void) const;
};

#endif