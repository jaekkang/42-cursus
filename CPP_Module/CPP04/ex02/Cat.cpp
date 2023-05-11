#include "Cat.hpp"

Cat::Cat() {
    setType("Cat");
    std::cout << getType() << " class constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &obj) {
    setType(obj.getType());
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

Cat &Cat::operator=(const Cat &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

Cat::~Cat() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("Animal");
    delete _brain;
}

const Brain *Cat::getBrain() const { return _brain; }