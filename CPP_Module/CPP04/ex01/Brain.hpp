#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain {
  private:
    std::string _ideas[100];

  public:
    Brain();
    ~Brain();
    Brain(const Brain &obj);
    Brain &operator=(const Brain &obj);

    const std::string *getIdeas() const;
    const std::string getIdea(int idx) const;
    void setIdea(int idx, std::string value);
};

#endif