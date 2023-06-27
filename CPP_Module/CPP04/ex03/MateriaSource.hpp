#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {

  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &obj);
    MateriaSource &operator=(const MateriaSource &obj);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif