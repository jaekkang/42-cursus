#include "Dog.hpp"

Dog::Dog() {
    setType("Dog");
    _brain = new Brain();
    std::cout << "Dog Class constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) {
    this->type = obj.getType();
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog Class destructor called" << std::endl;
    delete _brain;
}

const Brain *Dog::getBrain() const { return (_brain); }