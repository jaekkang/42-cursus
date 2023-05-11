#include "ADog.hpp"

ADog::ADog() {
    setType("Dog");
    _brain = new Brain();
    std::cout << "Dog Class constructor called" << std::endl;
}

ADog::ADog(const ADog &obj) {
    this->type = obj.getType();
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
}

ADog &ADog::operator=(const ADog &obj) {
    if (this != &obj) {
        this->type = obj.getType();
    }
    if (_brain)
        delete _brain;
    _brain = new Brain(*obj.getBrain());
    return (*this);
}

ADog::~ADog() {
    std::cout << "Dog Class destructor called" << std::endl;
    delete _brain;
}

const Brain *ADog::getBrain() const { return (_brain); }