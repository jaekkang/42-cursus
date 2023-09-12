#ifndef AFORM_HPP
#define AFORM_HPP

#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    const int _signGrade;
    const int _excuteGrade;
    bool _isSigned;
    std::string _target;

  public:
    class FormNotSigned : public std::exception {
      public:
        const char *what(void) const throw();
    };

    class GradeTooHighException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    class BureauGradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };

    AForm(std::string name, int signGrade, int excuteGrade);
    virtual ~AForm();
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);

    void beSigned(const Bureaucrat &obj);

    virtual void execute(const Bureaucrat &executor) const = 0;
    const std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExcuteGrade() const;
    const std::string getTarget() const;

    void setGrade(int signGrade, int excuteGrade);
    void setName(std::string name);
    void setSigned(bool isSigned);
    void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &os, AForm &p);

#endif