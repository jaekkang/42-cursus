#include "Cat.hpp"

Cat::Cat() {
    setType("Cat");
    _brain = new Brain();
    std::cout << "Cat Class constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) {
    this->type = obj.getType();
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

Cat &Cat::operator=(const Cat &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat Class destructor called" << std::endl;
    delete _brain;
}

const Brain *Cat::getBrain() const { return _brain; }