#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  private:
  public:
    Intern();
    ~Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);

    class NoMatchKey : public std::exception {
      public:
        const char *what() const throw();
    };

    AForm *makeForm(std::string name, std::string target);
};

#endif