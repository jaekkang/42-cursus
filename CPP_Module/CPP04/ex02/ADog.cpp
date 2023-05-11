#include "ADog.hpp"

ADog::ADog() {
    setType("ADog");
    std::cout << getType() << " class constructor called" << std::endl;
    _brain = new Brain();
}

ADog::ADog(const ADog &obj) {
    setType(obj.getType());
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

ADog &ADog::operator=(const ADog &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

ADog::~ADog() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("AAnimal");
    delete _brain;
}

const Brain *ADog::getBrain() const { return (_brain); }