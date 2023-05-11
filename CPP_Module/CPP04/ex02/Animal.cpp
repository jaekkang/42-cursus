#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << this->type << " class constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) : type(obj.getType()) {}

Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}
Animal::~Animal() {
    std::cout << this->type << " class destructor called : Animal class"
              << std::endl;
}

const std::string Animal::getType() const { return (this->type); }

void Animal::setType(std::string value) { this->type = value; }