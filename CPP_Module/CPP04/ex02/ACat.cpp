#include "ACat.hpp"

ACat::ACat() {
    setType("Dog");
    _brain = new Brain();
    std::cout << "Dog Class constructor called" << std::endl;
}

ACat::ACat(const ACat &obj) {
    this->type = obj.getType();
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

ACat &ACat::operator=(const ACat &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

ACat::~ACat() {
    std::cout << "Dog Class destructor called" << std::endl;
    delete _brain;
}

const Brain *ACat::getBrain() const { return (_brain); }