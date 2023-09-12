#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Class constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) { this->type = obj.getType(); }

Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}
Animal::~Animal() {
    std::cout << "Animal Class destructor called" << std::endl;
}

const std::string Animal::getType() const { return (this->type); }

void Animal::setType(std::string value) { this->type = value; }