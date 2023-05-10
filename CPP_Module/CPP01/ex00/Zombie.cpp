#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "constructor: create Zombie class [default]" << std::endl;
}

Zombie::Zombie(std::string name) {
    std::cout << "constructor: create Zombie class [" << name << "]"
              << std::endl;
    this->set_name(name);
}

Zombie::~Zombie() {
    std::cout << "destructor: delete "
              << "[" << (this->get_name() != "" ? this->get_name() : "default")
              << "]" << std::endl;
}

void Zombie::announce(void) {
    std::cout << "<" << (this->get_name() != "" ? this->get_name() : "default")
              << ">: "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) { this->_name = name; }

std::string Zombie::get_name(void) { return (this->_name); }