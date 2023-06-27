#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &obj) : AMateria("cure") { new (this)(Cure)(obj); }

Cure &Cure::operator=(const Cure &obj) {
    new (this)(Cure)(obj);
    return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() { return (new Cure()); }

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}