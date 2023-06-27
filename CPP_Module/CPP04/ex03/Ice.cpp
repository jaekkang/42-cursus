#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &obj) : AMateria("ice") { new (this)(Ice)(obj); }

Ice &Ice::operator=(const Ice &obj) {
    new (this)(Ice)(obj);
    return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() { return (new Ice()); }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}