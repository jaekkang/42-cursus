#include "ACat.hpp"

ACat::ACat() {
    setType("ACat");
    std::cout << getType() << " class constructor called" << std::endl;
    _brain = new Brain();
}

ACat::ACat(const ACat &obj) {
    setType(obj.getType());
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

ACat &ACat::operator=(const ACat &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

ACat::~ACat() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("AAnimal");
    delete _brain;
}

const Brain *ACat::getBrain() const { return (_brain); }