#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = 0;
  }
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i]) delete this->_inventory[i];
    if (obj._inventory[i]) this->_inventory[i] = (obj._inventory[i])->clone();
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i]) delete this->_inventory[i];
    if (obj._inventory[i]) this->_inventory[i] = (obj._inventory[i])->clone();
  }
  return (*this);
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i]) delete this->_inventory[i];
  }
}

void MateriaSource::learnMateria(AMateria *p) {
  int i = 0;

  while ((this->_inventory)[i] != 0 && i < 4) i++;
  if (i >= 4) {
    return;
  }
  (this->_inventory)[i] = p;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  int i = 0;

  while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type &&
         i < 4)
    i++;
  if (i >= 4 || !(this->_inventory)[i]) {
    return (NULL);
  }
  return (((this->_inventory)[i])->clone());
}