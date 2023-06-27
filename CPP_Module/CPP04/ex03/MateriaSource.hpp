#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria *(_inventory[4]);

 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(const MateriaSource &obj);
  MateriaSource &operator=(const MateriaSource &obj);

  void learnMateria(AMateria *p);
  AMateria *createMateria(std::string const &type);
};

#endif