#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
  private:
  public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &obj);
    WrongCat &operator=(const WrongCat &obj);

    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

#endif