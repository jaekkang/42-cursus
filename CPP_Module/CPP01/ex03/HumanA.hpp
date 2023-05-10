#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
  private:
    std::string _name;
    Weapon &_weapon;

  public:
    HumanA(std::string name, Weapon &weapon);

    const std::string getName(void) const;
    const Weapon &getWeapon(void) const;
    void setWeapon(Weapon &weapon);
    void attack(void);
};

#endif
