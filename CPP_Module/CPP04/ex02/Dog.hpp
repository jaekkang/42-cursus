#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  private:
    Brain *_brain;

  public:
    Dog();
    virtual ~Dog();
    Dog(const Dog &obj);
    Dog &operator=(const Dog &obj);

    void makeSound() const { std::cout << "Woof!" << std::endl; }
    const Brain *getBrain() const;
};

#endif