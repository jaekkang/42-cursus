#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class Character : public ICharacter {
 private:
  std::string _name;

 protected:
  AMateria *_inventory[4];

 public:
  Character(std::string name);
  ~Character();
  Character(const Character &obj);
  Character &operator=(const Character &obj);

  const AMateria *getAMateria(int idx) const;
  const std::string &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif