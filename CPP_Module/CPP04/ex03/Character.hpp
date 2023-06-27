#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
  private:
    std::string _name;

  protected:
    AMateria *inventory[4];

  public:
    Character(std::string name);
    ~Character();
    Character(const Character &obj);
    Character &operator=(const Character &obj);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif