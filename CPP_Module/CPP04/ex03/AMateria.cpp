#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &obj) {
  if (this != &obj) {
    this->_type = obj.getType();
  }
}

AMateria &AMateria::operator=(const AMateria &obj) {
  if (this != &obj) {
    this->_type = obj.getType();
  }
  return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return (this->_type); }

void AMateria::setType(std::string type) { this->_type = type; }

void AMateria::use(ICharacter &target) {
  std::cout << "* This is default use function target :" << target.getName()
            << std::endl;
}
