#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
  private:
  protected:
    std::string type;

  public:
    AAnimal(/* args*/);
    virtual ~AAnimal();
    AAnimal(const AAnimal &obj);
    AAnimal &operator=(const AAnimal &obj);

    virtual void makeSound() const = 0;

    const std::string getType() const;
    void setType(std::string value);
};

#endif