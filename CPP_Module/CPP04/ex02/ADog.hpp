#ifndef ADOG_HPP
#define ADOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class ADog : public AAnimal {
  private:
    Brain *_brain;

  public:
    ADog();
    ~ADog();
    ADog(const ADog &obj);
    ADog &operator=(const ADog &obj);

    void makeSound() const { std::cout << "Woof!" << std::endl; }
    const Brain *getBrain() const;
};

#endif