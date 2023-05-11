#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << type << " class constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.getType()) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this != &obj) {
        type = obj.getType();
    }
    return (*this);
}
WrongAnimal::~WrongAnimal() {
    std::cout << type << " class destructor called" << std::endl;
}

const std::string WrongAnimal::getType() const { return (type); }

void WrongAnimal::setType(std::string type) { this->type = type; }