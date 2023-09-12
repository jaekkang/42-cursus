#include "Cat.hpp"

Cat::Cat() { setType("Cat"); }

Cat::Cat(const Cat &obj) { this->type = obj.getType(); }

Cat &Cat::operator=(const Cat &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}

Cat::~Cat() {}