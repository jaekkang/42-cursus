#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
  private:
  public:
    Cat();
    ~Cat();
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);

    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

#endif