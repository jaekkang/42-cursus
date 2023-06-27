#include "Character.hpp"

Character::Character(std::string name) : _name(name) {}

Character::Character(const Character &obj) { new (this)(Character)(obj); }

Character &Character::operator=(const Character &obj) {
    new (this)(Character)(obj);
    return (*this);
}

Character::~Character() {}

void Character::equip(AMateria *m) { this->inventory[0] = m; }

void Character::unequip(int idx) { this->inventory[idx] = 0; }

void Character::use(int idx, ICharacter &target) {
    this->inventory[idx]->use(target);
}

std::string const &Character::getName() const { return (this->_name); }