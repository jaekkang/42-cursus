#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
  private:
  protected:
    std::string type;

  public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &obj);
    Animal &operator=(const Animal &obj);

    virtual void makeSound() const { std::cout << "Animal sound" << std::endl; }

    const std::string getType() const;
    void setType(std::string type);
};

#endif