#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria {
 private:
 public:
  Ice();
  ~Ice();
  Ice(const Ice &obj);
  Ice &operator=(const Ice &obj);

  AMateria *clone(void) const;
  void use(ICharacter &target);
};

#endif