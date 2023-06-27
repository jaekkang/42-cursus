#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = 0;
  }
}

Character::Character(const Character &obj) {
  for (int i = 0; i < 4; i++) {
    if ((obj._inventory)[i])
      (this->_inventory)[i] = (obj._inventory[i])->clone();
  }
}

Character &Character::operator=(const Character &obj) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i]) delete this->_inventory[i];
    if (obj._inventory[i]) this->_inventory[i] = (obj._inventory[i])->clone();
  }
  return (*this);
}

Character::~Character() {}

void Character::equip(AMateria *m) {
  int i = 0;

  if (!m) {
    return;
  }
  while ((this->_inventory)[i] != 0 && i < 4) i++;
  if (i >= 4) {
    return;
  }
  (this->_inventory)[i] = m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4)
    std::cout << this->_name << " tried to unequip nothing at slot " << idx
              << " and it did nothing\n";
  else if (!(this->_inventory)[idx])
    std::cout << this->_name << " has nothing equipped at slot " << idx
              << " so he can't unequip it\n";
  else {
    AMateria *ptr = (this->_inventory)[idx];
    std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "
              << idx << "\n";
    (this->_inventory)[idx] = 0;
  }
}

void Character::use(int idx, ICharacter &target) {
  std::string name = this->getName();

  if (idx < 0 || idx >= 4 || !(this->_inventory)[idx]) {
    std::cout << "Nothing found to use at index " << idx << std::endl;
    return;
  }
  ((this->_inventory)[idx])->use(target);
}

std::string const &Character::getName() const { return (this->_name); }