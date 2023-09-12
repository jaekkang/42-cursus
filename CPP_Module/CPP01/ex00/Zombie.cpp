#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "constructor: create Zombie class [default]" << std::endl;
}

Zombie::Zombie(std::string name) {
    std::cout << "constructor: create Zombie class [" << name << "]"
              << std::endl;
    this->setName(name);
}

Zombie::~Zombie() {
    std::cout << "destructor: delete "
              << "[" << (this->getName() != "" ? this->getName() : "default")
              << "]" << std::endl;
}

void Zombie::announce(void) {
    std::cout << "<" << (this->getName() != "" ? this->getName() : "default")
              << ">: "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }

std::string Zombie::getName(void) { return (this->_name); }