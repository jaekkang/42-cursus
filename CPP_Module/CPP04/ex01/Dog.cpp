#include "Dog.hpp"

Dog::Dog() {
    setType("Dog");
    std::cout << getType() << " class constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &obj) {
    setType(obj.getType());
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

Dog::~Dog() {
    delete _brain;
    std::cout << getType() << " class destructor called" << std::endl;
    setType("Animal");
}

const Brain *Dog::getBrain() const { return _brain; }