#include "Dog.hpp"

Dog::Dog() { setType("Dog"); }

Dog::Dog(const Dog &obj) { this->type = obj.getType(); }

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}

Dog::~Dog() {}