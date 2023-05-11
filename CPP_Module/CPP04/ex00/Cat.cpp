#include "Cat.hpp"

Cat::Cat() {
    setType("Cat");
    std::cout << getType() << " class constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) { setType(obj.getType()); }

Cat &Cat::operator=(const Cat &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("Animal");
}