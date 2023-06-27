#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
  private:
  public:
    Cure();
    ~Cure();
    Cure(const Cure &obj);
    Cure &operator=(const Cure &obj);

    AMateria *clone();
    void use(ICharacter &target);
};

#endif