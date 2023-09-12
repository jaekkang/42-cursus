#ifndef ACAT_HPP
#define ACAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class ACat : public AAnimal {
  private:
    Brain *_brain;

  public:
    ACat(/* args*/);
    virtual ~ACat();
    ACat(const ACat &obj);
    ACat &operator=(const ACat &obj);

    void makeSound() const { std::cout << "Meow!" << std::endl; }
    const Brain *getBrain() const;
};

#endif