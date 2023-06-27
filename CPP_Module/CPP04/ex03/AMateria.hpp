#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria {
  private:
  protected:
    std::string _type;

  public:
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria(const AMateria &obj);
    AMateria &operator=(const AMateria &obj);

    std::string const &getType() const;
    void setType(std::string type);
    virtual AMateria *clone() = 0;
    virtual void use(ICharacter &target);
};

#endif