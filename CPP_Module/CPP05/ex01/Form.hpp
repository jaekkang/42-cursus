#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class Form {
  private:
    const std::string _name;
    const int _signGrade;
    const int _excuteGrade;
    bool _isSigned;

  public:
    class GradeTooHighException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    Form(std::string name, int signGrade, int excuteGrade);
    ~Form();
    Form(const Form &obj);
    Form &operator=(const Form &obj);

    void beSigned(const Bureaucrat &obj);

    const std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExcuteGrade() const;

    void setSigned(bool isSigned);
};

std::ostream &operator<<(std::ostream &os, Form &p);

#endif