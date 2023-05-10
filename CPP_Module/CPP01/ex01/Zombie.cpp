#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Zombie [default] constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie [" << name << "] constructor called" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie [" << (this->_name != "" ? this->_name : "default")
              << "] destructor called" << std::endl;
}

void Zombie::announce(void) {
    std::cout << "[" << (this->_name != "" ? this->_name : "default")
              << "] : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }
