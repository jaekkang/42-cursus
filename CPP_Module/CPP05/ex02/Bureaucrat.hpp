#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;
class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);

    void signForm(AForm *obj);

    void downGrade();
    void upGrade();

    const std::string getName() const;
    int getGrade() const;

    void setGrade(int grade);

    class GradeTooHighException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &p);

#endif