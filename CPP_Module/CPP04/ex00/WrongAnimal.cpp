#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) { _type = obj.getType(); }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this != &obj) {
        _type = obj.getType();
    }
    return (*this);
}
WrongAnimal::~WrongAnimal() {}

const std::string WrongAnimal::getType() const { return (_type); }

void WrongAnimal::setType(std::string type) { _type = type; }