#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap {
  private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &c);
    ClapTrap &operator=(const ClapTrap &c);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackDamage() const;

    void setName(std::string name);
    void setHitPoint(unsigned int hitPoints);
    void setEnergyPoint(unsigned int energyPoints);
    void setAttackDamage(unsigned int attackDamage);
};

#endif