#ifndef ZOMEBIE_HPP
#define ZOMEBIE_HPP

#include <iostream>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    std::string getName(void);
    void setName(std::string name);
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
#endif