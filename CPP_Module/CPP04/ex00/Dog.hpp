#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
  private:
  public:
    Dog();
    ~Dog();
    Dog(const Dog &obj);
    Dog &operator=(const Dog &obj);

    void makeSound() const { std::cout << "Woof!" << std::endl; }
};

#endif