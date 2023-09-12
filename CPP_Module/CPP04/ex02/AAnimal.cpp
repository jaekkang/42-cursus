#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "AAnimal Class constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) { this->type = obj.getType(); }

AAnimal &AAnimal::operator=(const AAnimal &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    return (*this);
}
AAnimal::~AAnimal() {
    std::cout << "Animal Class destructor called" << std::endl;
}

const std::string AAnimal::getType() const { return (this->type); }

void AAnimal::setType(std::string value) { this->type = value; }