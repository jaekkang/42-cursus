#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
  private:
  protected:
    std::string _type;

  public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal &obj);
    WrongAnimal &operator=(const WrongAnimal &obj);

    void makeSound() const { std::cout << "Animal sound" << std::endl; }

    const std::string getType() const;
    void setType(std::string type);
};

#endif