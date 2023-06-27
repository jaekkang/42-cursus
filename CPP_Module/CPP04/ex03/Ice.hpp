#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
  private:
  public:
    Ice();
    ~Ice();
    Ice(const Ice &obj);
    Ice &operator=(const Ice &obj);

    AMateria *clone();
    void use(ICharacter &target);
};

#endif