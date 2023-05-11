#include "Dog.hpp"

Dog::Dog() {
    setType("Dog");
    std::cout << getType() << " class constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) { setType(obj.getType()); }

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("Animal");
}