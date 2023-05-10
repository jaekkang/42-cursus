#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "constructor: create Zombie class (default)" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->setName(name);
    std::cout << "constructor: create Zombie class (" << this->_name << ")"
              << std::endl;
}

Zombie::~Zombie() {
    std::cout << "destructor: delete "
              << "(" << (this->_name != "" ? this->_name : "default") << ")"
              << std::endl;
}

void Zombie::announce(void) {
    std::cout << "<" << (this->_name != "" ? this->_name : "default") << ">: "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }