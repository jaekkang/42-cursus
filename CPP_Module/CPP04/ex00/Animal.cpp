#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal &obj) { this->type = obj.getType(); }

Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}
Animal::~Animal() {}

const std::string Animal::getType() const { return (this->type); }

void Animal::setType(std::string type) { this->type = type; }